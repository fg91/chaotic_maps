// "Copyright 2018 <Fabio M. Graetz>"

#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using std::ofstream;
using std::ios;

Bitmap::Bitmap(int width, int height)
    : _width(width), _height(height),
      _pPixels(new uint8_t[width * height * 3]{}) {
}

Bitmap::Bitmap(Bitmap &&other)
    : _pPixels(std::move(other._pPixels)),
      _width(other._width), _height(other._height) {
}

Bitmap &Bitmap::operator=(Bitmap &&other) {
  _pPixels = std::move(other._pPixels);
  _width = other._width;
  _height = other._height;
  return *this;
}

bool Bitmap::write(std::string filename) {
  BitmapFileHeader fileHeader;
  BitmapInfoHeader infoHeader;

  fileHeader.fileSize = sizeof(BitmapFileHeader)
      + sizeof(BitmapInfoHeader)
      + _width*_height*3;
  fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
  
  infoHeader.width = _width;
  infoHeader.height = _height;

  ofstream file;
  file.open(filename, ios::out|ios::binary);

  if (!file) {
    return false;
  }

  file.write(reinterpret_cast<char *>(&fileHeader), sizeof(fileHeader));
  file.write(reinterpret_cast<char *>(&infoHeader), sizeof(infoHeader));
  file.write(reinterpret_cast<char *>(_pPixels.get()), _width*_height*3);
  
  file.close();

  if (!file) {
    return false;
  }
  return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
  uint8_t *pPixel = _pPixels.get();
  pPixel += 3 * (y * _width + x);

  // bitmap is a little endian file format
  pPixel[0] = blue;
  pPixel[1] = green;
  pPixel[2] = red;
  
}

Bitmap::~Bitmap() {
}

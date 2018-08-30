// "Copyright 2018 <Fabio M. Graetz>"

#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using std::ofstream;
using std::ios;

Bitmap::Bitmap(int width, int height)
    : m_width(width), m_height(height),
      m_pPixels(new uint8_t[width * height * 3]{}) {
}

Bitmap::Bitmap(Bitmap &&other)
    : m_pPixels(std::move(other.m_pPixels)),
      m_width(other.m_width), m_height(other.m_height) {
}

bool Bitmap::write(std::string filename) {
  BitmapFileHeader fileHeader;
  BitmapInfoHeader infoHeader;

  fileHeader.fileSize = sizeof(BitmapFileHeader)
      + sizeof(BitmapInfoHeader)
      + m_width*m_height*3;
  fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
  
  infoHeader.width = m_width;
  infoHeader.height = m_height;

  ofstream file;
  file.open(filename, ios::out|ios::binary);

  if (!file) {
    return false;
  }

  file.write(reinterpret_cast<char *>(&fileHeader), sizeof(fileHeader));
  file.write(reinterpret_cast<char *>(&infoHeader), sizeof(infoHeader));
  file.write(reinterpret_cast<char *>(m_pPixels.get()), m_width*m_height*3);
  
  file.close();

  if (!file) {
    return false;
  }
  return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
  uint8_t *pPixel = m_pPixels.get();
  pPixel += 3 * (y * m_width + x);

  // bitmap is a little endian file format
  pPixel[0] = blue;
  pPixel[1] = green;
  pPixel[2] = red;
  
}

Bitmap::~Bitmap() {
}

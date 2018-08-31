// "Copyright 2018 <Fabio M. Graetz>"

#ifndef BITMAP_H_
#define BITMAP_H_

#include <memory>
#include <string>
#include <cstdint>

class Bitmap {
 private:
  int _width{0};
  int _height{0};
  std::unique_ptr<uint8_t[]> _pPixels{nullptr};
 public:

  Bitmap(int width, int height);
  Bitmap(const Bitmap &other) = delete;
  Bitmap &operator=(const Bitmap &other) = delete;
  Bitmap(Bitmap &&other);
  Bitmap &operator=(Bitmap &&other);
  virtual ~Bitmap();
  bool write(std::string filename);
  void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
};

#endif  // BITMAP_H_

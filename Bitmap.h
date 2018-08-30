// "Copyright 2018 <Fabio M. Graetz>"

#ifndef BITMAP_H_
#define BITMAP_H_

#include <memory>
#include <string>
#include <cstdint>

class Bitmap {
 private:
  int m_width{0};
  int m_height{0};
  std::unique_ptr<uint8_t[]> m_pPixels{nullptr};;
 public:
  Bitmap(int width, int height);
  bool write(std::string filename);
  void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
  virtual ~Bitmap();
};

#endif  // BITMAP_H_

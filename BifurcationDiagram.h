// "Copyright 2018 <Fabio M. Graetz>"

#include <cstdint>
#include <string>
#include "Bitmap.h"
#include "CoordSystem.h"
#include "ChaoticMap.h"
#include "Histogram.h"

#ifndef BIFURCATIONDIAGRAM_H_
#define BIFURCATIONDIAGRAM_H_

class BifurcationDiagram {
 private:
  int _width{800};
  int _height{600};
  int _transient{1000};
  int _samples{1000};
  int _brightness{150};
  Bitmap _bitmap;
  const CoordSystem &_coords;
  ChaoticMap *_map;


 public:
  BifurcationDiagram(int width, int height, int transient,
                     int samples, int brightness,
                     const CoordSystem &coords, ChaoticMap *map);
  void drawDiagram(std::string filename, bool verbose);
  uint8_t color(int brightness, int binCount, int totCount);
  
  
  
};

#endif  // BIFURCATIONDIAGRAM_H_

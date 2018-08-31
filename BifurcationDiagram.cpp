// "Copyright 2018 <Fabio M. Graetz>"

#include <math.h>
#include <iostream>
#include "BifurcationDiagram.h"

BifurcationDiagram::BifurcationDiagram(int width, int height,
                                       int brightness,
                                       const CoordSystem &coords,
                                       ChaoticMap *map)
    : _width(width), _height(height), _brightness(brightness),
      _coords(coords), _map(map), _bitmap(Bitmap(width, height)) {

}
BifurcationDiagram::~BifurcationDiagram() {
}

void BifurcationDiagram::drawDiagram(std::string filename, bool verbose) {
  #pragma omp parallel for
  for (int xFrame = 0; xFrame < _width; xFrame++) {
    if (verbose == true && xFrame%(_width/10) == 0) {
      std::cout << 100 * static_cast<double>(xFrame)/_width << "%" << std::endl;
    }
    double xDiag = _coords.coordTransform(xFrame, 0).first;
    Histogram hist(_height, _coords._ymin, _coords._ymax);
    double x0 = _map->doTransient(0.5, xDiag);
    for (int i = 0; i < _map->_nSamples; i++) {
      x0 = _map->equation(x0, xDiag);
      hist.add(x0);
    }
    int count = hist.getCount();
    Histogram::iterator it = hist.begin();
    for (int yFrame = 0; yFrame < _height; yFrame++, it++) {
      uint8_t col = color(_brightness, *it, count);
      _bitmap.setPixel(xFrame, yFrame, col, col, col);
    }

  }
  _bitmap.write(filename);
}

uint8_t BifurcationDiagram::color(int brightness, int binCount, int totCount) {
  double dummy = static_cast<double>(binCount)/ (totCount + 1);
  return 255 * (1 - fmin(brightness*dummy, 1.));
}

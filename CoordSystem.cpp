// "Copyright 2018 <Fabio M. Graetz>"

#include <assert.h>
#include "CoordSystem.h"

using std::pair;

CoordSystem::CoordSystem(double xmin, double xmax, double ymin,
                         double ymax, int width, int height)
    : _xmin(xmin), _xmax(xmax), _ymin(ymin), _ymax(ymax),
      _deltaX(xmax - xmin), _deltaY(ymax-ymin),
      _width(width), _height(height) {
  assert(_xmin < _xmax);
  assert(_ymin < _ymax);
}

CoordSystem::~CoordSystem() {
}

pair<double, double> CoordSystem::coordTransform(int xBitmap, int yBitmap) const {
  assert(xBitmap >= 0);
  assert(yBitmap >= 0);

  assert(xBitmap < _width);
  assert(yBitmap < _height);
  
  double xCoord = _xmin + _deltaX * static_cast<double>(xBitmap)/(_width - 1);
  double yCoord = _ymin + _deltaY * static_cast<double>(yBitmap)/(_height - 1);
  return pair<double, double>(xCoord, yCoord);
}

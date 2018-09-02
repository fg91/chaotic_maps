// "Copyright 2018 <Fabio M. Graetz>"

#include <iostream>
#include <iomanip>
#include <assert.h>
#include "Zoom.h"

Zoom::Zoom(CoordSystem *initial, CoordSystem *final, int iter,
           int bright, ChaoticMap *map)
    : _initial(initial), _final(final), _iterations(iter),
      _brightness(bright), _map(map) {

  assert(initial->_width == final->_width);
  assert(initial->_height == final->_height);
  assert(bright > 0);

  _deltaXmin = (final->_xmin - initial->_xmin) / (iter - 1);
  _deltaXmax = (final->_xmax - initial->_xmax) / (iter - 1);
  _deltaYmin = (final->_ymin - initial->_ymin) / (iter - 1);
  _deltaYmax = (final->_ymax - initial->_ymax) / (iter - 1);
}

Zoom::~Zoom() {
}

CoordSystem Zoom::getCurrent(int i) {
  assert(i >=0 && i < _iterations);
  return CoordSystem(_initial->_xmin + i * _deltaXmin,
                     _initial->_xmax + i * _deltaXmax,
                     _initial->_ymin + i * _deltaYmin,
                     _initial->_ymax + i * _deltaYmax,
                     _initial->_width, _initial->_height);
}

void Zoom::animate() {
  for (int i = 0; i < _iterations; i++) {
    if (i % (_iterations/10) == 0) {
      std::cout << 100 * static_cast<double>(i)/_iterations << "%" << std::endl;
    }
    auto current = getCurrent(i);
    BifurcationDiagram diag(current._width, current._height,
                            _brightness, current, _map);
    std::stringstream ss;
    ss << "frame_";
    ss << std::setfill('0') << std::setw(5) << i;
    ss << ".bmp";
    diag.drawDiagram(ss.str(), false);
  }
}

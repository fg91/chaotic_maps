// "Copyright 2018 <Fabio M. Graetz>"

#include <assert.h>
#include <math.h>
#include "GaussMap.h"

GaussMap::GaussMap(double r, double alpha, double x0,
                      int transient, int samples)
    : _alpha(alpha), ChaoticMap(r, x0, transient, samples) {
  assert(r >= 0. && r <= 4.);
  assert(x0 >=0 && x0 <= 1.);
  assert(transient >= 0 && samples > 0);
}

double GaussMap::equation() {
  assert(_r >= -1. && _r <= 1.);
  _x = exp(-_alpha * _x * _x) + _r;
  return _x;
}

void GaussMap::doTransient() {
  for (int i = 0; i < _nTransient; i++) {
    equation();
  }
}

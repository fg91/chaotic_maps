// "Copyright 2018 <Fabio M. Graetz>"

#include <assert.h>
#include "LogisticMap.h"

LogisticMap::LogisticMap(double r, double x0, int transient, int samples)
    : ChaoticMap(r, x0, transient, samples) {
  assert(r >= 0. && r <= 4.);
  assert(x0 >=0 && x0 <= 1.);
  assert(transient >= 0 && samples > 0);
}

double LogisticMap::equation() {
  assert(_r >= 0. && _r <= 4.);
  _x = _r * _x * (1. - _x);
  return _x;
}

void LogisticMap::doTransient() {
  for (int i = 0; i < _nTransient; i++) {
    equation();
  }
}

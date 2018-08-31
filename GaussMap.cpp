// "Copyright 2018 <Fabio M. Graetz>"

#include <assert.h>
#include <math.h>
#include "GaussMap.h"

GaussMap::GaussMap(double alpha, int transient, int samples)
    : _alpha(alpha), ChaoticMap(transient, samples) {
  assert(transient >= 0 && samples > 0);
}

GaussMap::~GaussMap() {
}

double GaussMap::equation(double x, double r) {
  x = exp(-_alpha * x * x) + r;
  return x;
}

double GaussMap::doTransient(double x0, double r) {
  for (int i = 0; i < _nTransient; i++) {
    x0 = equation(x0, r);
  }
  return x0;
}

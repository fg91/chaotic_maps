// "Copyright 2018 <Fabio M. Graetz>"

#include <math.h>
#include <assert.h>
#include "TentMap.h"

TentMap::TentMap(int transient, int samples)
    : ChaoticMap(transient, samples) {
  assert(transient >= 0 && samples > 0);
}

TentMap::~TentMap() {
}

double TentMap::equation(double x, double r) {
  assert(r >= 0. && r <= 2.);
  assert(x >=0 && x <= 1.);

  x = r * fmin(x, 1. - x);
  return x;
}

double TentMap::doTransient(double x0, double r) {
  for (int i = 0; i < _nTransient; i++) {
    x0 = equation(x0, r);
  }
  return x0;
}

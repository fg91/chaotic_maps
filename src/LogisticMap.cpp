// "Copyright 2018 <Fabio M. Graetz>"

#include <assert.h>
#include "LogisticMap.h"

LogisticMap::LogisticMap(int transient, int samples)
    : ChaoticMap(transient, samples) {
  assert(transient >= 0 && samples > 0);
}

LogisticMap::~LogisticMap() {
}

double LogisticMap::equation(double x, double r) {
  assert(r >= 0. && r <= 4.);
  assert(x >=0 && x <= 1.);

  x = r * x * (1. - x);
  return x;
}

double LogisticMap::doTransient(double x0, double r) {
  for (int i = 0; i < _nTransient; i++) {
    x0 = equation(x0, r);
  }
  return x0;
}

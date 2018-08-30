// "Copyright 2018 <Fabio M. Graetz>"

#ifndef GAUSSMAP_H_
#define GAUSSMAP_H_

#include "ChaoticMap.h"

struct GaussMap: ChaoticMap {
  double _alpha{1.};
  GaussMap(double r, double alpha, double x0, int transient, int samples);
  virtual double equation();
  virtual void doTransient();
};

#endif  // GAUSSMAP_H_


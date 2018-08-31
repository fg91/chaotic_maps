// "Copyright 2018 <Fabio M. Graetz>"

#ifndef GAUSSMAP_H_
#define GAUSSMAP_H_

#include "ChaoticMap.h"

struct GaussMap: ChaoticMap {
  double _alpha{1.};
  GaussMap(double alpha, int transient, int samples);
  virtual ~GaussMap();
  virtual double equation(double x, double r);
  virtual double doTransient(double x0, double r);
};

#endif  // GAUSSMAP_H_


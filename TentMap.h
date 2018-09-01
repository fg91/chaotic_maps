// "Copyright 2018 <Fabio M. Graetz>"

#ifndef TENTMAP_H_
#define TENTMAP_H_

#include "ChaoticMap.h"

struct TentMap: ChaoticMap {
  TentMap(int transient, int samples);
  virtual ~TentMap();
  virtual double equation(double x, double r);
  virtual double doTransient(double x0, double r);
};

#endif  // TENTMAP_H_


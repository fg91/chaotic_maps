// "Copyright 2018 <Fabio M. Graetz>"

#ifndef LOGISTICMAP_H_
#define LOGISTICMAP_H_

#include "ChaoticMap.h"

struct LogisticMap: ChaoticMap {
  LogisticMap(double r, double x0, int transient, int samples);
  virtual double equation();
  virtual void doTransient();
};

#endif  // LOGISTICMAP_H_


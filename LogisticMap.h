// "Copyright 2018 <Fabio M. Graetz>"

#ifndef LOGISTICMAP_H_
#define LOGISTICMAP_H_

#include "ChaoticMap.h"

struct LogisticMap: ChaoticMap {
  LogisticMap(int transient, int samples);
  virtual ~LogisticMap();
  virtual double equation(double x, double r);
  virtual double doTransient(double x0, double r);
};

#endif  // LOGISTICMAP_H_


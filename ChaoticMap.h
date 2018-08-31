// "Copyright 2018 <Fabio M. Graetz>"

#ifndef CHAOTICMAP_H_
#define CHAOTICMAP_H_

struct ChaoticMap {
  int _nTransient{0};
  int _nSamples{0};
  ChaoticMap(int transient, int samples);
  virtual ~ChaoticMap();
  virtual double equation(double x, double r) = 0;
  virtual double doTransient(double x0, double r) = 0;
};

#endif  // CHAOTICMAP_H_

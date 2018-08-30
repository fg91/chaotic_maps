// "Copyright 2018 <Fabio M. Graetz>"

#ifndef CHAOTICMAP_H_
#define CHAOTICMAP_H_

struct ChaoticMap {
  double _r{0};
  double _x{0};
  int _nTransient{0};
  int _nSamples{0};
  ChaoticMap(double r, double x, int transient, int samples);
  virtual double equation() = 0;
  virtual void doTransient() = 0;
};

#endif  // CHAOTICMAP_H_

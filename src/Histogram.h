// "Copyright 2018 <Fabio M. Graetz>"

#include <memory>

#ifndef HISTOGRAM_H_
#define HISTOGRAM_H_

class Histogram {
 public:
  class iterator;

 private:
  const int _nBins;
  const double _min;
  const double _max;
  const double _binWidth;
  int count{0};
  std::unique_ptr<int[]> _bins{nullptr};
  
 public:
  Histogram(int nBins, double min, double max);
  Histogram(const Histogram &other) = delete;
  Histogram &operator=(const Histogram &other) = delete;
  Histogram(Histogram &&o);
  Histogram &operator=(Histogram &&o) = delete;  // because _nBins is const!
  virtual ~Histogram();
  void add(double value);
  int get(int pos) const;
  iterator begin();
  iterator end();
  int getCount() const;
};

class Histogram::iterator {
 private:
  int _pos;
  const Histogram &_hist;

 public:
  iterator(int pos, const Histogram &hist);
  iterator &operator++(int);
  iterator &operator++();
  int operator*();
  bool operator!=(const iterator &other) const;
  
};

#endif  // HISTOGRAM_H_

// "Copyright 2018 <Fabio M. Graetz>"

#include <math.h>
#include <assert.h>
#include <iostream>
#include "Histogram.h"

Histogram::Histogram(int nBins, double min, double max)
    : _nBins(nBins), _bins(new int[_nBins]{}),
      _min(min), _max(max), _binWidth((max - min) / nBins) {
  assert(min < max);

}

void Histogram::add(double value) {
  if (value < _min || value > _max) {
    return;
  }
  count++;
  if (value == _max) {
    _bins[_nBins - 1]++;
  } else {
    _bins[static_cast<int>((value - _min) / _binWidth)]++;
  }
}

int Histogram::get(int pos) const {
  assert(pos >= 0 && pos < _nBins);
  return _bins[pos];
}

int Histogram::getCount() const {
  return count;
}

Histogram::iterator Histogram::begin() {
  return Histogram::iterator(0, *this);
}

Histogram::iterator Histogram::end() {
  return Histogram::iterator(_nBins, *this);
}

Histogram::iterator::iterator(int pos, const Histogram& hist)
    : _pos(pos), _hist(hist) {
}

Histogram::iterator &Histogram::iterator::operator++() {
  ++_pos;
  return *this;
}

Histogram::iterator &Histogram::iterator::operator++(int) {
  _pos++;
  return *this;
}

int Histogram::iterator::operator*() {
  return _hist.get(_pos);
}

bool Histogram::iterator::operator!=(const iterator &other) const {
  return _pos != other._pos;
}




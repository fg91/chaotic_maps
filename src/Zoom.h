// "Copyright 2018 <Fabio M. Graetz>"

#ifndef ZOOM_H_
#define ZOOM_H_

#include <sstream>
#include "CoordSystem.h"
#include "ChaoticMap.h"
#include "LogisticMap.h"
#include "GaussMap.h"
#include "BifurcationDiagram.h"

class Zoom {
 private:
  CoordSystem *_initial;
  CoordSystem *_final;
  int _iterations{1};
  int _brightness{100};
  double _deltaXmin{0.};
  double _deltaXmax{0.};
  double _deltaYmin{0.};
  double _deltaYmax{0.};
  ChaoticMap *_map;
  CoordSystem getCurrent(int i);

 public:
  Zoom(CoordSystem *initial, CoordSystem *final,
       int iter, int bright, ChaoticMap *map);
  virtual ~Zoom();
  void animate();
};

#endif  // ZOOM_H_

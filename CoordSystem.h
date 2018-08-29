// "Copyright 2018 <Fabio M. Graetz>"
#ifndef COORDSYSTEM_H_
#define COORDSYSTEM_H_

#include <utility>

struct CoordSystem {
  double _xmin{0.0};
  double _xmax{1.0};
  double _ymin{0.0};
  double _ymax{1.0};
  double _deltaX{0};
  double _deltaY{0};
  int _width{0};
  int _height{0};

  CoordSystem(double xmin, double xmax, double ymin,
              double ymax, int width, int height);
  std::pair<double, double> coordTransform(int xBitmap, int yBitmap);
};

#endif  // COORDSYSTEM_H_

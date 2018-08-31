// "Copyright 2018 <Fabio M. Graetz>"

#include <iostream>
#include <sstream>
#include "CoordSystem.h"
#include "LogisticMap.h"
#include "GaussMap.h"
#include "BifurcationDiagram.h"

using std::cout;
using std::endl;

int main() {

  int width = 1920;
  int height = 1080;
  
  double xmin = 3.5;
  double xmax = 4.0;
  double ymin = 0.0;
  double ymax = 1.;

  int transient = 1000;
  int samples = 1000;

  int brightness = 80;
  
  CoordSystem coords(xmin, xmax, ymin, ymax, width, height);
  LogisticMap map(transient, samples);
  // GaussMap map(alpha, transient, samples);
  BifurcationDiagram bD(width, height, brightness, coords, &map);
  
  bD.drawDiagram("test.bmp", true);
  

  
  return 0;
}

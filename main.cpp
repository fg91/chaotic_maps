// "Copyright 2018 <Fabio M. Graetz>"

#include <iostream>
#include <sstream>
#include "CoordSystem.h"
#include "LogisticMap.h"
#include "GaussMap.h"
#include "BifurcationDiagram.h"

int main() {

  int width = 1920;
  int height = 1080;

  double xmin = -1.;
  double xmax = 1.0;
  double ymin = -1.0;
  double ymax = 1.5;

  int transient = 1000;
  int samples = 150000;

  int brightness = 50;
  
  
  for (double alpha = 4.5; alpha < 5; alpha+= 0.01) {
    std::cout << alpha << std::endl;
    CoordSystem coords(xmin, xmax, ymin, ymax, width, height);
    //  LogisticMap map(0.0, 0.5, transient, samples);
    GaussMap map(0.0, alpha, 0.5, transient, samples);
    BifurcationDiagram bD(width, height, transient, samples, brightness, coords, &map);
  
    std::stringstream ss;
  
    ss << "Bild";
    ss << alpha;
    ss << ".bmp";
  
    bD.drawDiagram(ss.str(), false);
  }


  
  return 0;
}

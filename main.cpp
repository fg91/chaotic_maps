// "Copyright 2018 <Fabio M. Graetz>"

#include <iostream>
#include "CoordSystem.h"
#include "LogisticMap.h"
#include "GaussMap.h"
#include "BifurcationDiagram.h"
#include "Zoom.h"

using std::cout;
using std::endl;

int main() {

  int width = 6000;
  int height = 3000;
  int iterations = 600;

  double xminInit = 3.5;
  double xmaxInit = 4.0;
  double yminInit = 0.0;
  double ymaxInit = 1.;
  
  // double xminInit = 2.5;
  // double xmaxInit = 4.0;
  // double yminInit = 0.0;
  // double ymaxInit = 1.;

  // double xminFinal = 3.84925;
  // double xmaxFinal = 3.8495;
  // double yminFinal = 0.958;
  // double ymaxFinal = 0.9585;

  CoordSystem init(xminInit, xmaxInit, yminInit, ymaxInit, width, height);
  //  CoordSystem final(xminFinal, xmaxFinal, yminFinal, ymaxFinal, width, height);
  

  int transient = 10000;
  int samples = 500000;

  int brightness = 150;

  LogisticMap map(transient, samples);
  // GaussMap map(alpha, transient, samples);

  BifurcationDiagram bd(width, height, brightness, init, &map);
  bd.drawDiagram("trying.bmp", true);
  // Zoom zoom(&init, &final, iterations, brightness, &map);
  
  // zoom.animate();
  return 0;
}

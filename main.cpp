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

  int width = 1920;
  int height = 1080;
  int iterations = 3;
  
  double xminInit = 2.5;
  double xmaxInit = 4.0;
  double yminInit = 0.0;
  double ymaxInit = 1.;

  double xminFinal = 3.8;
  double xmaxFinal = 3.9;
  double yminFinal = 0.8;
  double ymaxFinal = 0.9;

  CoordSystem init(xminInit, xmaxInit, yminInit, ymaxInit, width, height);
  CoordSystem final(xminFinal, xmaxFinal, yminFinal, ymaxFinal, width, height);
  

  int transient = 2000;
  int samples = 10000;

  int brightness = 120;

  LogisticMap map(transient, samples);
  // GaussMap map(alpha, transient, samples);
  
  Zoom zoom(&init, &final, iterations, brightness, &map);
  
  zoom.animate();
  return 0;
}

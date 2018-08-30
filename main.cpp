// "Copyright 2018 <Fabio M. Graetz>"
#include <iostream>
#include <cstdint>
#include "Bitmap.h"
#include "CoordSystem.h"
#include "LogisticMap.h"
#include "Histogram.h"



using std::cout;
using std::endl;


int main() {

  int width = 4000;
  int height = 4000;

  double xmin = 2.0;
  double xmax = 4.0;
  double ymin = 0.;
  double ymax = 1.;
      
  // Here assert when moving to class
  
  Bitmap test(width, height);
  CoordSystem coords(xmin, xmax, ymin, ymax, width, height);



  for (int x = 0; x < width; x++) {
    // Get physical x coordinate
    double co = coords.coordTransform(x, 0).first;
    cout << co << endl;
    Histogram hist(height, ymin, ymax);
    LogisticMap l(co, 0.5, 1000, 10000);
    l.doTransient();
    for (int i = 0; i < l._nSamples; i++) {
      double val = l.equation();
      hist.add(val);
    }

    Histogram::iterator it = hist.begin();
    for (int y = 0; y < height; y++, it++) {
      test.setPixel(x, y, 255-255**it/50., 255-255**it/50., 255-255**it/50.);
    }
    

    
  }

  test.write("log.bmp");
  return 0;
}

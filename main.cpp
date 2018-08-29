// "Copyright 2018 <Fabio M. Graetz>"
#include <iostream>
#include "Bitmap.h"
#include "CoordSystem.h"
#include "LogisticMap.h"


using std::cout;
using std::endl;


int main() {

  int width = 800;
  int height = 600;
  // Here assert when moving to class
  
  // Bitmap test(width, height);

  
  // CoordSystem coords(0., 1., 0., 1., width, height);

  // std::pair<double, double>  xy = coords.coordTransform(0, 599);
  

  // test.write("test.bmp");


  for (double r = 1.; r <= 4.; r += 0.05) {
    LogisticMap l(r, 0.5, 100, 1000);
    l.doTransient();
    for (int i = 0; i < l._nSamples; i++) {
      cout << r << "\t" << i << "\t" << l.equation() << endl;
    }
  }
  
  return 0;
}

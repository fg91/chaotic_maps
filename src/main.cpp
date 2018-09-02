// "Copyright 2018 <Fabio M. Graetz>"

#include <iostream>
#include <iomanip>
#include "CoordSystem.h"
#include "LogisticMap.h"
#include "GaussMap.h"
#include "TentMap.h"
#include "BifurcationDiagram.h"
#include "Zoom.h"

using std::cout;
using std::endl;

int main() {

  // ------------------------------------
  // -- Example 1: Bifurcation diagram --
  // ------------------------------------

  // Parameters for frame
  int width = 1800;
  int height = 1600;
  int brightness = 150;

  // Coordinate system
  double xmin = 2.5;
  double xmax = 4.0;
  double ymin = 0.0;
  double ymax = 1.0;
  CoordSystem coords(xmin, xmax, ymin, ymax, width, height);

  // Chaotic map
  int transient = 5000;
  int samples = 100000;
  LogisticMap map(transient, samples);
  // GaussMap map(4.9, transient, samples); // x from -1 to 1, y from -1 to 1.5
  // TentMap map(transient, samples);  // x from 1 to 2, y from 0 to 1

  BifurcationDiagram bd(width, height, brightness, coords, &map);

  // Progress will not be printed in order if run in parallel
  bd.drawDiagram("bifurcation.bmp", true);


  // ------------------------------------
  // --- Example 2: zoom in animation ---
  // ------------------------------------
  /*
  // Parameters for frames and video
  int width = 1920;
  int height = 1080;
  int brightness = 150;
  int iterations = 600;

  // Initial and final coordinate system
  double xminInit = 2.5;
  double xmaxInit = 4.0;
  double yminInit = 0.0;
  double ymaxInit = 1.;

  double xminFinal = 3.84925;
  double xmaxFinal = 3.8495;
  double yminFinal = 0.958;
  double ymaxFinal = 0.9585;

  CoordSystem init(xminInit, xmaxInit, yminInit, ymaxInit, width, height);
  CoordSystem final(xminFinal, xmaxFinal, yminFinal, ymaxFinal, width, height);

  // Chaotic map
  int transient = 10000;
  int samples = 100000;
  LogisticMap map(transient, samples);

  // Creating the frames for the zoom animation
  Zoom zoom(&init, &final, iterations, brightness, &map);
  zoom.animate();
  */

  // -----------------------------------------------
  // --- Example 3: changing parameter animation ---
  // -----------------------------------------------
  /*
  // Parameters for frame and animation
  int width = 1920;
  int height = 1080;
  int brightness = 100;
  int iterations = 600;
  
  // Coordinate system
  double xmin = -.8;
  double xmax = .1;
  double ymin = -.8;
  double ymax = 1.2;
  CoordSystem coords(xmin, xmax, ymin, ymax, width, height);

  // Chaotic map
  double alphaInit = 3.5;
  double alphaFinal = 8.;
  int transient = 10000;
  int samples = 100000;

  for (int i = 0; i < iterations; i++) {
    GaussMap map(alphaInit + i * (alphaFinal - alphaInit) / (iterations - 1), transient, samples);
    BifurcationDiagram bd(width, height, brightness, coords, &map);
    std::stringstream ss;
    ss << "frame_";
    ss << std::setfill('0') << std::setw(5) << i;
    ss << ".bmp";
    bd.drawDiagram(ss.str(), false);
    std::cout << i << std::endl;
  }
  */
  return 0;
}

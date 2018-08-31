CXX=g++
CPPFLAGS=-std=c++11 #-fopenmp -O2
LIBSEARCHPATH=-L/opt/local/lib/

OBJECTS=$(PROJECT).o Bitmap.o CoordSystem.o ChaoticMap.o LogisticMap.o Histogram.o BifurcationDiagram.o GaussMap.o Zoom.o
PROJECT=main

$(PROJECT) : $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(OBJECTS) -o $@ $(LIBSEARCHPATH) $(LIBS)

.cpp.o :
	$(CXX) -c $(CPPFLAGS) -o $@ $< 

clean :
	rm -f $(OBJECTS)

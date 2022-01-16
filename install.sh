#! /bin/bash

# Generating objects

g++ -c -o ./objs/ils_plotting.o ils_plotting.cpp -fPIC -I include/ -lglut -lGLU -lGL 
g++ -c -o ./objs/optgl.o optgl.cpp -fPIC -I include/ -lglut -lGLU -lGL 

# Generating shared libraries

g++ -shared -o ./lib/libilsplt.so ./objs/ils_plotting.o -I include/ -lglut -lGLU -lGL
g++ -shared -o ./lib/liboptgl.so ./objs/optgl.o -I include/ -lglut -lGLU -lGL
#! /bin/bash

# Generating objects

g++ -c -o ./objs/graph.o ./src/graph.cpp -fPIC -I include/ -lglut -lGLU -lGL 
g++ -c -o ./objs/cartesian.o ./src/cartesian.cpp -fPIC -I include/ -lglut -lGLU -lGL 
g++ -c -o ./objs/tree.o ./src/tree.cpp -fPIC -I include/ -lglut -lGLU -lGL
g++ -c -o ./objs/optgl.o ./src/optgl.cpp -fPIC -I include/ -lglut -lGLU -lGL 

# Generating shared libraries

g++ -shared -o ./lib/libgraph.so ./objs/graph.o -I include/ -lglut -lGLU -lGL
g++ -shared -o ./lib/liboptcartesian.so ./objs/cartesian.o -I include/ -lglut -lGLU -lGL
g++ -shared -o ./lib/libtree.so ./objs/tree.o -I include/ -lglut -lGLU -lGL
g++ -shared -o ./lib/liboptgl.so ./objs/optgl.o ./objs/graph.o ./objs/tree.o ./objs/cartesian.o -I include/ -lglut -lGLU -lGL

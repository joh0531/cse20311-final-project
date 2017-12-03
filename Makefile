FLAGS = -std=c++11 -O2
exec: project.cpp
	g++ project.cpp gfx.o -lX11 -o project $(FLAGS) 

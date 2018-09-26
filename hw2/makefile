150120220:Dynarray.o main.o
	g++ Dynarray.o main.o -std=c++11 -o 150120220
Dynarray.o:Dynarray.cpp Dynarray.h
	g++ -c -std=c++11 Dynarray.cpp
main.o:main.cpp Dynarray.h
	g++ -c -std=c++11 main.cpp
clean:
	rm *.o 150120220 sorted.txt

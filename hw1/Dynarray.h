//Dynarray.h
#ifndef DYNARRAY
#define DYNARRAY

#include <iostream>

using namespace std;

class Dynarray {

private:
 	
 	int *dynarray;
 	int length;
 	int arrayCap;
 	
 public:
 
 	Dynarray();
 	
	~Dynarray();
 	
	Dynarray(int arrayCap);
 	
	void add(int value, int location);
 	
	int size();

	int item(int location);
	
};

#endif

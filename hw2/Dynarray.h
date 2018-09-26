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
 	
	void add(int value, int location); // Adds a value at the given location inside the dynamic array 
 	
	void swap(int location1, int location2); // Swaps two elements of the dynamic array
	
	int size(); // returns the size of dynamic array

	int item(int location); // returns the element at the given location inside the dynamic array 
	
	
};

#endif

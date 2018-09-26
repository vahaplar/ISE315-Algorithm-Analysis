//Dynarray.cpp
#include "Dynarray.h"
 
 	Dynarray::Dynarray(){
 	
 		dynarray = new int[10];
 		arrayCap = 10;
 		length = 0;
	}
	 
	Dynarray::~Dynarray(){ 
 	
		delete [] dynarray;
	}
	
	Dynarray::Dynarray(int cap){
	
		dynarray = new int[cap];
 		arrayCap = cap;
 		length = 0;
	} 
 	
	void Dynarray::add(int value, int location){
 	
		dynarray[location] = value;
		length++;
	 
	}
	
	int Dynarray::size(){
	
		return arrayCap;
	}

	int Dynarray::item(int location){
		
		return dynarray[location];
	}

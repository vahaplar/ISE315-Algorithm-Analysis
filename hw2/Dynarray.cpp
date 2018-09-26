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
	void Dynarray::swap(int location1, int location2){
		
		int temp;
	
		temp = dynarray[location1];
		dynarray[location1] = dynarray[location2];
		dynarray[location2] = temp;

	}
	
	int Dynarray::size(){
	
		return arrayCap;
	}

	int Dynarray::item(int location){
		
		return dynarray[location];
	}

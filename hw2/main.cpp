#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <random>
#include <ctime>

#include "Dynarray.h"


void openInputFile(ifstream &myfile);
//Opens data.txt if it's available, if not returns warning message via assert
void openOutputFile(ofstream &myfile);
//Creates an output file named sorted.txt
Dynarray getArray(ifstream &myfile, int sizeOfArray);
//Seperates the lines of the expressions in the file
void quickSort(Dynarray & a, int p, int r);
//Applies randomized quick sort
int partition(Dynarray & a, int p, int r);
//Partition creation operation
void writeOutputFile(ofstream & myoutfile, Dynarray & a);
//Writes the sorted array on the output file

int main(int argc, char** argv){
	

	int N = atoi(argv[1]);

	ifstream myfile;	
	openInputFile(myfile);
	ofstream myoutfile;	
	openOutputFile(myoutfile);
	Dynarray a = getArray(myfile,N);
	
	//
	clock_t start;
    double duration;
    start = clock();
	//
	
	quickSort(a,0,N);
	writeOutputFile(myoutfile,a);

	//
	duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
    cout<<"Duration: "<< duration <<'\n';
	//
	
	return 0;
}

void openInputFile(ifstream &myfile){
	
	string fileName;
	fileName = "data.txt";
	
	myfile.open(fileName.c_str());
	assert(myfile.is_open()!=false);
}

void openOutputFile(ofstream &myfile){
	
	string fileName;
	
	fileName ="sorted.txt";
	
	myfile.open(fileName.c_str());
	assert(myfile.is_open()!=false);

}

Dynarray getArray(ifstream &myfile,int sizeOfArray){
	
	Dynarray a = Dynarray(sizeOfArray);
	string currentValue;	
	
	for(int i=0;i<=sizeOfArray;i++){
	
		getline(myfile,currentValue);
		a.add(atoi(currentValue.c_str()),i);
			
	}
	
	myfile.close();
	return a;	
}


void quickSort(Dynarray & a, int p, int r){
   
    int j;
    if (p < r){
    	
        j = partition(a, p, r);
        quickSort(a, p, j-1);
        quickSort(a, j+1, r);
    }
}

int partition(Dynarray & a, int p, int r){
   
	int pivotIndex = p + rand()%(r - p + 1); //Random index selected as a pivot 
    int pivot;
    int i = p - 1;
    int j;
    
    pivot = a.item(pivotIndex);
    
	a.swap(pivotIndex,r);
	
    for (j = p; j < r; j++){
        if (a.item(j) < pivot)
        {
            i++;
            a.swap(i,j);
        }
    }
    a.swap(i+1,r);
    
    return i + 1;

}


void writeOutputFile(ofstream & myoutfile, Dynarray & a){
	
	for(int i=0;i<a.size();i++){
		myoutfile<< a.item(i)<< endl;
	}
}

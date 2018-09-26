#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <string.h>
#include <climits>

#include "Dynarray.h"

void openInputFile(ifstream &myfile);
//Opens data.txt if it's available, if not returns warning message via assert
void openOutputFile(ofstream &myfile);
//Creates an output file named sorted.txt
Dynarray getArray(ifstream &myfile, int sizeOfArray);
//Seperates the lines of the expressions in the file
void insertionSort(Dynarray & a);
//Applies insertionSort
void mergeSort(Dynarray & a, int low, int high);
//Helper function for mergeSort operation
void merge(Dynarray & a, int low, int mid, int high);
//Applies merging operation.
void writeOutputFile(ofstream & myoutfile, Dynarray & a);
//Writes the sorted array on the output file

int main(int argc, char** argv){
	
	int N = atoi(argv[1]);

	ifstream myfile;	
	openInputFile(myfile);
	ofstream myoutfile;	
	openOutputFile(myoutfile);
	Dynarray a = getArray(myfile,N);
	
	if(0==strcmp(argv[2],"InsertionSort")){
		insertionSort(a);
		writeOutputFile(myoutfile,a);
	}
	else if(0==strcmp(argv[2],"MergeSort")){
		mergeSort(a, 0, N);
		writeOutputFile(myoutfile,a);
	}
	
	else{
		
		cout << "Invalid argument!";
		return 0;
	}
	
		mergeSort(a, 0, N);
		writeOutputFile(myoutfile,a);

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

void mergeSort(Dynarray & a, int low, int high){
   
    int mid;
    if (low < high){
    	
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
    return;
}


void merge(Dynarray & a, int p, int q, int r){
       
    int n1 = q - p + 1;
    int n2 = r - q;
    Dynarray L = Dynarray(n1+1);
    Dynarray R = Dynarray(n2 + 1);

    for (int i = 0; i < n1; i++)
        L.add(a.item(p + i),i);

    for (int j = 0; j < n2; j++)
        R.add(a.item(q + j + 1),j);

    L.add(INT_MAX,n1);
    R.add(INT_MAX,n2);

    int x = 0, y = 0;

    for (int k = p; k <= r; k++){

        if (L.item(x) <= R.item(y)){
        	
            a.add(L.item(x),k);
            x++;
        }
        else{
        	
        	a.add(R.item(y),k);
            y++;
        }
    }
}

void insertionSort (Dynarray & a){

	int j, temp;
		
	for (int i = 0; i < a.size(); i++){
		
		j = i;
		
		while (j > 0 && a.item(j) < a.item(j-1)){
			  
			temp = a.item(j);
			a.add(a.item(j-1),j);
			a.add(temp,j-1);
			j--;	  
		}
	}
}

void writeOutputFile(ofstream & myoutfile, Dynarray & a){
	
	for(int i=0;i<a.size();i++){
		myoutfile<< a.item(i)<< endl;
	}
}

#include<iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

int main(int argc, char* argv[]){
	double start, end;
	start = clock();
    ifstream infile;
    ofstream outfile;
    infile.open(argv[1]);
    outfile.open(argv[2]);
    
    if(!infile){
        cout << "Error" << endl;
        return 0;
    }
    
    int matSiz;
    char ch;
    while(!infile.eof()){
    	infile >> matSiz;
	
		int **mat1 = new int*[matSiz];
		int **mat2 = new int*[matSiz];
		int **mat3 = new int*[matSiz];
		for(int i = 0;i<matSiz;i++) {
			mat1[i] = new int[matSiz];
			mat2[i] = new int[matSiz];
			mat3[i] = new int[matSiz];
		}

		// load elements to the matrix
    	for(int i = 0, j = 0;;){
    		infile >> mat1[i][j];
    		if(i == matSiz-1 && j == matSiz-1) break;
		else if(j == matSiz -1) {
    			j = 0;
    			i = i+1;
    		} else j = j+1;
    	}
    	
    	for(int i = 0, j = 0;;){
    		infile >> mat2[i][j];
    		if(i == matSiz-1 && j == matSiz-1) break;
		else if(j == matSiz -1) {
    			j = 0;
    			i = i+1;
    		} else j = j+1;
    	}
		infile >> ch;
	    /*
	    for(int i = 0, j = 0;;){
	    	cout << mat1[i][j] << " ";
	    	if(i == matSiz-1 && j == matSiz-1) break;
			else if(j == matSiz -1) {
	    		j = 0;
	    		i = i+1;
	    		cout << endl;
	    	} else j = j+1;
	    }
	
		cout << endl;
		for(int i = 0, j = 0;;){
	    	cout << mat2[i][j] << " ";
	    	if(i == matSiz-1 && j == matSiz-1) break;
			else if(j == matSiz -1) {
	    		j = 0;
	    		i = i+1;
	    		cout << endl;
	    	} else j = j+1;
	    }
    	*/
    	for(int i = 0, j = 0;;){
    		for(int k = 0;k < matSiz;k++) mat3[i][j]+= mat1[i][k] * mat2[k][j];
    		outfile << mat3[i][j] << " ";
    	
		if(i == matSiz-1 && j == matSiz-1) break;
		else if(j == matSiz -1) {
	 	    j = 0;
		    i = i+1;
	   	    outfile << endl;
		} else j = j+1;
    	}

	/*	
	for(int i = 0, j = 0;;){
	    	cout << mat3[i][j] << " ";
	    	if(i == matSiz-1 && j == matSiz-1) break;
			else if(j == matSiz -1) {
			j = 0;
			i = i+1;
			cout << endl;
		} else j = j+1;
	} */
    }
	
	end = clock();
	cout << "Time: " << (end - start) / CLOCKS_PER_SEC << "s" << endl;
	
	return 0;
    

}
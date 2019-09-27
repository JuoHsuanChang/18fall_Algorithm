#include<iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

/*
int ** smallMat(int a1, int a2, int b1, int b2, int ** mat1, int ** mat2, int ** mat3){
	int **mat = new int*[a2 - a1 + 1];
	for(int i = 0; i < a2 - a1 + 1; i++){
		mat[i] = new int[b2 - b1 + 1];
	}
	if (a2 - a1 == b2 - b1 == 1){
		mat[a1][b1] = mat1[a1][b1] * mat2[a1][b1] + mat1[a1][b2] * mat2[a2][b1];
		mat[a1][b2] = mat1[a1][b1] * mat2[a1][b2] + mat1[a1][b2] * mat2[a2][b2];
		mat[a2][b1] = mat1[a2][b1] * mat2[a1][b1] + mat1[a2][b2] * mat2[a2][b1];
		mat[a2][b2] = mat1[a2][b1] * mat2[a1][b2] + mat1[a2][b2] * mat2[a2][b2];
		return mat;
	} else if(a2 - a1 == b2 - b1){
		if((a2 - a1) % 2 == 1) {
			for(int i = 0; i <= (a2 - a1) / 2; i++){
				for(int j = 0; j <= (b2 - b1) / 2; j++) mat[i][j] = smallMat(a1, (a1 + a2) / 2, b1, (b1 + b2) / 2, mat1, mat2)[i][j] + smallMat(a1, (a1 + a2) / 2, (b1 + b2) / 2 + 1, b2, mat1, mat2)[i][j];
				for(int j = (b2 - b1) / 2 + 1; j <= b2 - b1 + 1; j++)
			}
			
			
		}
///there are only three case: a = b + 1; b = a + 1; a = b(minimum to 2);
	}
}
*/

int ** smallMat(int matSize, int** mat1, int ** mat2){
	int ** mat = new int*[matSize];
	for(int i = 0; i < matSize; i++){
		mat[i] = new int[matSize];
	}
	
	if(matSize == 2){
		mat[0][0] = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0];
		mat[0][1] = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1];
		mat[1][0] = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0];
		mat[1][1] = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1];
	}
	else{
		int newMatSize = (matSize + 1) / 2;
		
		int ** mat1A = new int*[newMatSize];
		int ** mat1B = new int*[newMatSize];
		int ** mat1C = new int*[newMatSize];
		int ** mat1D = new int*[newMatSize];
		
		int ** mat2A = new int*[newMatSize];
		int ** mat2B = new int*[newMatSize];
		int ** mat2C = new int*[newMatSize];
		int ** mat2D = new int*[newMatSize];
		
		int ** temMat1 = new int*[newMatSize];
		int ** temMat2 = new int*[newMatSize];
		
		for(int i = 0; i < newMatSize; i++){
			mat1A[i] = new int[newMatSize];
			mat1B[i] = new int[newMatSize];
			mat1C[i] = new int[newMatSize];
			mat1D[i] = new int[newMatSize];
			
			mat2A[i] = new int[newMatSize];
			mat2B[i] = new int[newMatSize];
			mat2C[i] = new int[newMatSize];
			mat2D[i] = new int[newMatSize];
			
			temMat1[i] = new int[newMatSize];
			temMat2[i] = new int[newMatSize];
		}
		
		for(int i = 0; i < newMatSize; i++){
			for(int j = 0; j < newMatSize; j++){
				mat1A[i][j] = mat1[i][j];
				mat1B[i][j] = (matSize % 2 == 1 && j == newMatSize - 1)? 0: mat1[i][j + newMatSize];
				mat1C[i][j] = (matSize % 2 == 1 && i == newMatSize - 1)? 0: mat1[i + newMatSize][j];
				mat1D[i][j] = (matSize % 2 == 1 && (j == newMatSize - 1 || i == newMatSize - 1))? 0: mat1[i + newMatSize][j + newMatSize];
				
				mat2A[i][j] = mat2[i][j];
				mat2B[i][j] = (matSize % 2 == 1 && j == newMatSize - 1)? 0: mat2[i][j + newMatSize];
				mat2C[i][j] = (matSize % 2 == 1 && i == newMatSize - 1)? 0: mat2[i + newMatSize][j];
				mat2D[i][j] = (matSize % 2 == 1 && (j == newMatSize - 1 || i == newMatSize - 1))? 0: mat2[i + newMatSize][j + newMatSize];
			}
		}
		
		
		temMat1 = smallMat(newMatSize, mat1A, mat2A);
		temMat2 = smallMat(newMatSize, mat1B, mat2C);
		for(int i = 0; i < newMatSize; i++){
			for(int j = 0; j < newMatSize; j++) mat[i][j] = temMat1[i][j] + temMat2[i][j];
		}
		
		temMat1 = smallMat(newMatSize, mat1A, mat2B);
		temMat2 = smallMat(newMatSize, mat1B, mat2D);
		for(int i = 0; i < newMatSize; i++){
			for(int j = newMatSize; j < matSize; j++) mat[i][j] = temMat1[i][j - newMatSize] + temMat2[i][j - newMatSize];
		}
		
		temMat1 = smallMat(newMatSize, mat1C, mat2A);
		temMat2 = smallMat(newMatSize, mat1D, mat2C);
		for(int i = newMatSize; i < matSize; i++){
			for(int j = 0; j < newMatSize; j++) mat[i][j] = temMat1[i - newMatSize][j] + temMat2[i - newMatSize][j];
		}
		
		temMat1 = smallMat(newMatSize, mat1C, mat2B);
		temMat2 = smallMat(newMatSize, mat1D, mat2D);
		for(int i = newMatSize; i < matSize; i++){
			for(int j = newMatSize; j < matSize; j++) mat[i][j] = temMat1[i - newMatSize][j - newMatSize] + temMat2[i - newMatSize][j - newMatSize];
		} 
	}
	
	return mat;
}

/*
int ** smallMat(int matSizeA, int matSizeB, int ** mat1, int ** mat2){
	int **mat = new int*[matSizeA];
	for(int i = 0; i < matSizeA; i++){
		mat[i] = new int[matSizeB];
	}
	if(){
		
		
	}else{
		int a1 = (matSizeA + 1) / 2;
		int a2 = matSizeA / 2;
		int b1 = (matSizeB + 1) / 2;
		int b2 = matSizeB / 2;
		
		int ** matA = new int*[a1];
		int ** matB = new int*[a1];
		int ** matC = new int*[a2];
		int ** matD = new int*[a2];
		
		int ** matE = new int*[a1];
		int ** matF = new int*[a1];
		int ** matG = new int*[a2];
		int ** matH = new int*[a2];
		
		int ** mat_1 = new int*[a1];
		int ** mat_2 = new int*[a1];
		int ** mat_3 = new int*[a2];
		int ** mat_4 = new int*[a2];
		
		for(int i = 0; i < a2; i++){
			matA[i] = new int[b1];
			matB[i] = new int[b2];
			matC[i] = new int[b1];
			matD[i] = new int[b2];
			
			matE[i] = new int[b1];
			matF[i] = new int[b2];
			matG[i] = new int[b1];
			matH[i] = new int[b2];
			
			mat_1[i] = new int[b1];
			mat_2[i] = new int[b2];
			mat_3[i] = new int[b1];
			mat_4[i] = new int[b2];
		}
		if(matSizeA % 2 == 1){	
			matA[a1 - 1] = new int[b1];
			matB[a1 - 1] = new int[b2];
			
			matE[a1 - 1] = new int[b1];
			matF[a1 - 1] = new int[b2];
			
			mat_1[a1 - 1] = new int[b1];
			mat_2[a1 - 1] = new int[b2];
		}
		for(int i = 0; i < a1; i++){
			for(int j = 0; j < b1; j ++) {
				matA[i][j] = mat1[i][j];
				matE[i][j] = mat2[i][j];
			}
		}
		for(int i = 0; i < a1; i++){
			for(int j = 0; j < b2; j ++) {
				matB[i][j] = mat1[i][j + b1];
				matF[i][j] = mat2[i][j + b1];
			}
		}
		for(int i = 0; i < a2; i++){
			for(int j = 0; j < b1; j ++) {
				matC[i][j] = mat1[i + a1][j];
				matG[i][j] = mat2[i + a1][j];
			}
		}
		for(int i = 0; i < a2; i++){
			for(int j = 0; j < b2; j ++) {
				matD[i][j] = mat1[i + a1][j + b1];
				matH[i][j] = mat2[i + a1][j + b1];
			}
		}
		
		mat_1 = smallMat(a1, b1, matA, matE) + smallMat(a1, b1, matB, matG);
	}
	return mat;
	
}
*/
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

//////////////////////CALCULATION!!!

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
    	*/
		
	

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
	
	mat3 = smallMat(matSiz, mat1, mat2);
	
	for(int i = 0; i < matSiz; i ++){
		for(int j = 0; j < matSiz; j++){
			outfile << mat3[i][j] << " ";
		}
		outfile << endl;
	}
	
    }
	
	end = clock();
	cout << "Time: " << (end - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;

}
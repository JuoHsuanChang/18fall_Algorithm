#include<iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

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
		
		int ** mat11 = new int*[newMatSize];
		int ** mat12 = new int*[newMatSize];
		int ** mat21 = new int*[newMatSize];
		int ** mat22 = new int*[newMatSize];
		int ** mat31 = new int*[newMatSize];
		int ** mat32 = new int*[newMatSize];
		int ** mat41 = new int*[newMatSize];
		int ** mat42 = new int*[newMatSize];
		int ** mat51 = new int*[newMatSize];
		int ** mat52 = new int*[newMatSize];
		int ** mat61 = new int*[newMatSize];
		int ** mat62 = new int*[newMatSize];
		int ** mat71 = new int*[newMatSize];
		int ** mat72 = new int*[newMatSize];
		
		int ** p1 = new int*[newMatSize];
		int ** p2 = new int*[newMatSize];
		int ** p3 = new int*[newMatSize];
		int ** p4 = new int*[newMatSize];
		int ** p5 = new int*[newMatSize];
		int ** p6 = new int*[newMatSize];
		int ** p7 = new int*[newMatSize];

		for(int i = 0; i < newMatSize; i++){
			mat11[i] = new int[newMatSize];
			mat12[i] = new int[newMatSize];
			mat21[i] = new int[newMatSize];
			mat22[i] = new int[newMatSize];
			mat31[i] = new int[newMatSize];
			mat32[i] = new int[newMatSize];
			mat41[i] = new int[newMatSize];
			mat42[i] = new int[newMatSize];
			mat51[i] = new int[newMatSize];
			mat52[i] = new int[newMatSize];
			mat61[i] = new int[newMatSize];
			mat62[i] = new int[newMatSize];
			mat71[i] = new int[newMatSize];
			mat72[i] = new int[newMatSize];
			
			p1[i] = new int[newMatSize];
			p2[i] = new int[newMatSize];
			p3[i] = new int[newMatSize];
			p4[i] = new int[newMatSize];
			p5[i] = new int[newMatSize];
			p6[i] = new int[newMatSize];
			p7[i] = new int[newMatSize];
		}

		for(int i = 0; i < newMatSize; i++){
			for(int j = 0; j < newMatSize; j++){
				mat11[i][j] = mat1[i][j] + ((matSize % 2 == 1 && (j == newMatSize - 1 || i == newMatSize - 1))? 0: mat1[i + newMatSize][j + newMatSize]);
				mat12[i][j] = mat2[i][j] + ((matSize % 2 == 1 && (j == newMatSize - 1 || i == newMatSize - 1))? 0: mat2[i + newMatSize][j + newMatSize]);
				mat21[i][j] = ((matSize % 2 == 1 && i == newMatSize - 1)? 0: mat1[i + newMatSize][j]) + ((matSize % 2 == 1 && (j == newMatSize - 1 || i == newMatSize - 1))? 0: mat1[i + newMatSize][j + newMatSize]);
				mat22[i][j] = mat2[i][j];
				mat31[i][j] = mat1[i][j];
				mat32[i][j] = ((matSize % 2 == 1 && j == newMatSize - 1)? 0: mat2[i][j + newMatSize]) - ((matSize % 2 == 1 && (j == newMatSize - 1 || i == newMatSize - 1))? 0: mat2[i + newMatSize][j + newMatSize]);
				mat41[i][j] = (matSize % 2 == 1 && (j == newMatSize - 1 || i == newMatSize - 1))? 0: mat1[i + newMatSize][j + newMatSize];
				mat42[i][j] = ((matSize % 2 == 1 && i == newMatSize - 1)? 0: mat2[i + newMatSize][j]) - mat2[i][j];
				mat51[i][j] = mat1[i][j] + ((matSize % 2 == 1 && j == newMatSize - 1)? 0: mat1[i][j + newMatSize]);
				mat52[i][j] = (matSize % 2 == 1 && (j == newMatSize - 1 || i == newMatSize - 1))? 0: mat2[i + newMatSize][j + newMatSize];
				mat61[i][j] = ((matSize % 2 == 1 && i == newMatSize - 1)? 0: mat1[i + newMatSize][j]) - mat1[i][j];
				mat62[i][j] = mat2[i][j] + ((matSize % 2 == 1 && j == newMatSize - 1)? 0: mat2[i][j + newMatSize]);
				mat71[i][j] = ((matSize % 2 == 1 && j == newMatSize - 1)? 0: mat1[i][j + newMatSize]) - ((matSize % 2 == 1 && (j == newMatSize - 1 || i == newMatSize - 1))? 0: mat1[i + newMatSize][j + newMatSize]);
				mat72[i][j] = ((matSize % 2 == 1 && i == newMatSize - 1)? 0: mat2[i + newMatSize][j]) + ((matSize % 2 == 1 && (j == newMatSize - 1 || i == newMatSize - 1))? 0: mat2[i + newMatSize][j + newMatSize]);
			
			}
		}
		
		p1 = smallMat(newMatSize, mat11, mat12);
		p2 = smallMat(newMatSize, mat21, mat22);
		p3 = smallMat(newMatSize, mat31, mat32);
		p4 = smallMat(newMatSize, mat41, mat42);
		p5 = smallMat(newMatSize, mat51, mat52);
		p6 = smallMat(newMatSize, mat61, mat62);
		p7 = smallMat(newMatSize, mat71, mat72);
		
		for(int i = 0; i < newMatSize; i++){
			for(int j = 0; j < newMatSize; j++) mat[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];
		}
		for(int i = 0; i < newMatSize; i++){
			for(int j = newMatSize; j < matSize; j++) mat[i][j] = p3[i][j - newMatSize] + p5[i][j - newMatSize];
		}
		for(int i = newMatSize; i < matSize; i++){
			for(int j = 0; j < newMatSize; j++) mat[i][j] = p2[i - newMatSize][j] + p4[i - newMatSize][j];
		}
		for(int i = newMatSize; i < matSize; i++){
			for(int j = newMatSize; j < matSize; j++) mat[i][j] = p1[i - newMatSize][j - newMatSize] + p3[i - newMatSize][j - newMatSize] - p2[i - newMatSize][j - newMatSize] + p6[i - newMatSize][j - newMatSize];
		} 
	}
	
	return mat;
}


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
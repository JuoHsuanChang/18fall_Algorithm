#include<iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

int main(){
	ofstream outfile;
	outfile.open("case1200.txt");
	
	outfile << 1200 << endl << endl;
	
	for(int i = 0; i < 1200; i++){
		for(int j = 0; j < 1200; j++){
			outfile << (i * j) % 13 << " ";
		}
		outfile << endl;
	}
	outfile << endl;
	
	for(int i = 0; i < 1200; i++){
		for(int j = 0; j < 1200; j++){
			outfile << (i * j) % 11 << " ";
		}
		outfile << endl;
	}

	return 0;
}
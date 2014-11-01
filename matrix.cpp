#include "matrix.h"
#include <iostream>
#include <fstream>

#define mark 999

using namespace std;

Matrix::~Matrix(){
}

Matrix& Matrix::operator=(const Matrix& N){
	i = N.i;
	j = N.j;
	M = new int *[i];

	for (int a = 0; a < i; a++){
		M[a] = new int[j];
	}

	for(int ai = 0; ai < i; ai++){
		for(int aj = 0; aj < j; aj++){
			M[ai][aj] = N.M[ai][aj];
		}
	}

	return *this;
}

void Matrix::InputMatrix(){
	ifstream inputFile;
	inputFile.open("in4.dat");

	int i, j;
	inputFile >> i >> j;

	this->i = i;
	this->j = j;

	M = new int *[i];

	for (int a = 0; a < i; a++){
		M[a] = new int[j];
	}

	for (int ai = 0; ai < i; ai++){
		for (int aj = 0; aj < j; aj++){
			inputFile >> M[ai][aj];
		}
	}
}

void Matrix::Print(){
	for (int ai = 0; ai < i; ai++){
		for (int aj = 0; aj < j; aj++){
			printf("%4d ",  M[ai][aj]);
		}
		cout << endl;
	}
}
int Matrix::LeastValue(char S, int N){
	int min;
	if (S == 'H'){
		int temp = 0;
		min = mark;
		while (temp < j){
			if (min > M[N][temp] && M[N][temp]!= mark)
				min = M[N][temp]; 
			temp++;
		}
	}
	else {
		int temp = 0;
		min = mark;
		while (temp < i){
			if (min > M[temp][N] && M[temp][N]!= mark)
				min = M[temp][N];
			temp++;
		}
	}
	return min;
}
bool Matrix::CRD(){
	bool check = true;
	int x = 0;
	while (check && x < i){
		if (LeastValue('V', x) != 0 || LeastValue('H', x) != 0)
			check = false;
		x++;
	}
	return check;
}

Matrix Matrix::CostReducing(){
	Matrix X;
	X = *this;
	for (int ai = 0; ai < i; ai++){
		int Least = X.LeastValue('H', ai);
		if (Least != 0 && Least != mark){
			cout << "Least for H-" << ai << " : " << Least << endl;
			for (int aj = 0; aj < j; aj++){
				if (X.M[ai][aj] != mark){
					cout << X.M[ai][aj] << "=> ";
					X.M[ai][aj] = X.M[ai][aj] - Least;
					cout << X.M[ai][aj] << "      ";
				}
			}
		}
	}
	for (int ai = 0; ai < i; ai++){
		int Least = X.LeastValue('V', ai);
		if (Least != 0 && Least != mark){
			cout << "Least for V-" << ai << " : " << Least << endl;
			for (int aj = 0; aj < j; aj++){
				if (X.M[aj][ai] != mark){
					cout << X.M[aj][ai] << "=> ";
					X.M[aj][ai] = X.M[aj][ai] - Least;
					cout << X.M[aj][ai] << "      ";
				}
			}
		}
	}
	cout << endl;
	return X;
}

int Matrix::VCostReduce(){
	Matrix N;
	N = *this;
	int retval = 0;
	//cout << "From Horizontal :";
	for (int ai = 0; ai < i; ai++){
		int Least = N.LeastValue('H', ai);
		if (Least != 0 && Least != mark){
			for (int aj = 0; aj < j; aj++){
				if (N.M[ai][aj] != mark){
					N.M[ai][aj] = N.M[ai][aj] - Least;
				}
			}
			//cout << Least << " ";
			retval = retval + Least;
		}
	}
	//cout << endl << "From Vertical :";
	for (int ai = 0; ai < i; ai++){
		int Least = N.LeastValue('V', ai);
		
		if (Least != 0  && Least != mark){
			for (int aj = 0; aj < j; aj++){
				if (N.M[aj][ai] != mark){
					N.M[aj][ai] = N.M[aj][ai] - Least;
				}
			}
			//cout << Least << " ";
			retval = retval + Least;
		}
	}
	return retval;
}
int Matrix::totalValue(){
	int total = 0;
	for (int ai = 0; ai < i; ai++){
		for (int aj = 0; aj < j; aj++){
			if (M[ai][aj] != mark)
				total = total + M[ai][aj];
		}
	}
	return total;
}

Matrix Matrix::NullMatrix(char S, int N){
	Matrix X;
	X = *this;
	if (S == 'H'){
		int temp = 0;
		while (temp < j){
			X.M[N][temp] = mark;
			temp++;
		}
	}
	else {
		int temp = 0;
		while (temp < i){
			X.M[temp][N] = mark;
			temp++;
		}
	}

	return X;
}
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <time.h>
#include <vector>
#include <ctime>


#define MAX 500
using namespace std;

int main()
{
	srand(time(NULL));
	vector<vector<int> > mat1(MAX, vector<int>(MAX, 0));
	vector<vector<int> > mat2(MAX, vector<int>(MAX, 0));
	vector<vector<int> > mat3(MAX, vector<int>(MAX, 0));
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			mat1[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			mat2[i][j] = rand() % 100;
			mat3[i][j] = 0;
		}
	}
	int bloque = 50;
	auto start = std::chrono::system_clock::now();

	for (int ib = 0; ib < MAX; ib += bloque){
		for (int jb = 0; jb < MAX; jb += bloque){

			for (int kb = 0; kb < MAX; kb += bloque){
				for (int i = ib; i < ib + bloque; i++){
					for (int j = jb; j < ib + bloque; j++){
						for (int k = kb; k < kb + bloque; k++){
							mat3[i][j] += mat1[i][k] * mat2[k][j];
						}
					}
				}
			}
		}
	}

	//Version alternativa a la de 6 bucles
	//Aparentemete un mejor rendimiento

	/*int temp = 0;
	for (int jj = 0; jj < MAX; jj += bloque) {
		for (int kk = 0; kk < MAX; kk += bloque) {
			for (int i = 0; i < MAX; i++) {
				for (int j = jj; j < ((jj + bloque) > MAX ? MAX : (jj + bloque)); j++) {
					temp = 0;
					for (int k = kk; k < ((kk + bloque) > MAX ? MAX : (kk + bloque)); k++) {
						temp += mat1[i][k] * mat2[k][j];
					}
					mat3[i][j] += temp;
				}
			}
		}
	}*/



	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration = end - start;
	cout << duration.count() << " ms" << endl;
}
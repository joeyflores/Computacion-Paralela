#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <ctime>
#include <random>
#include <algorithm>
#include <vector>

using namespace std;

void initializeMatrix(vector<vector<int>>& matrix, int n, int m) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = dis(gen);
        }
    }
}

int main()
{
  
	int n = 1000;
  vector<vector<int>> A(n, vector<int>(n));
  vector<vector<int>> B(n, vector<int>(n));
  vector<vector<int>> C(n, vector<int>(n, 0));

  auto start1 = chrono::steady_clock::now();
  
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j <n; j++)
		{
			for (int k = 0; k <n; k++)
			{
				C[i][j] += (A[i][k]) * (B[k][j]);
			}
		}
	}
  
	auto end1 = chrono::steady_clock::now();
    cout << "Tiempo transcurrido: " << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() / 1000000.0 << " segundos" << endl;

}
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <ctime>

using namespace std;

const int BLOCK_SIZE = 16;

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

void matrixMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    int n = A.size();
    int m = B[0].size();
    int p = B.size();

    for (int i = 0; i < n; i += BLOCK_SIZE) {
        for (int j = 0; j < m; j += BLOCK_SIZE) {
            for (int k = 0; k < p; k += BLOCK_SIZE) {
                for (int ii = i; ii < min(n, i + BLOCK_SIZE); ii++) {
                    for (int jj = j; jj < min(m, j + BLOCK_SIZE); jj++) {
                        int sum = 0;
                        for (int kk = k; kk < min(p, k + BLOCK_SIZE); kk++) {
                            sum += A[ii][kk] * B[kk][jj];
                        }
                        C[ii][jj] += sum;
                    }
                }
            }
        }
    }
}

int main() {
  
  int n = 1000;
  vector<vector<int>> A(n, vector<int>(n));
  vector<vector<int>> B(n, vector<int>(n));
  vector<vector<int>> C(n, vector<int>(n, 0));
  
  initializeMatrix(A, n, n);
  initializeMatrix(B, n, n);

  auto start1 = chrono::steady_clock::now();
    
  matrixMultiplication(A, B, C);

  auto end1 = chrono::steady_clock::now();
  cout << "Tiempo transcurrido: " << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() / 1000000.0 << " segundos" << endl;

  return 0;
  
}

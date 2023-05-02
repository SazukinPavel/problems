#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    cout << "start";
    unsigned short n = matrix.size();
    unsigned short m = matrix[0].size();
    vector<vector<int>> newMatrix (n,vector<int>(m));
    for (unsigned short i = 0; i < n; i++) {
      for (unsigned short j = 0; j < m; j++) {
        newMatrix[j][n-i-1] = matrix[i][j];
      }
    }
   
    matrix=newMatrix;
  }
};

void print_matrix(vector<vector<int>> m) {
  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m[0].size(); j++) {
      cout << m[i][j] << "\t";
    }
    cout << "\n";
  }
}

int main() {
  Solution s;
  vector<vector<int>> v{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  print_matrix(v);
  s.rotate(v);
  print_matrix(v);
}
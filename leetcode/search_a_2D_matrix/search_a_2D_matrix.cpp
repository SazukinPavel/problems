#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        unsigned short n = matrix.size(), m = matrix[0].size();
        for (unsigned short i = 0; i < n; i++)
        {
            if (target >= matrix[i][0] && target <= matrix[i][m - 1])
            {
                short low = 0;
                short high = m - 1;
                short mid = 0;
                do
                {
                    mid = low + (high - low) / 2;
                    if (matrix[i][mid] == target)
                    {
                        return true;
                    }
                    else if (matrix[i][mid] > target)
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                } while (low <= high);
                break;
            }
        }
        return false;
    }
};

void print_matrix(vector<vector<int>> m)
{
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    Solution s;
    vector<vector<int>> v{{1, 4, 10}, {12, 15, 19}, {21, 25, 40}};
    print_matrix(v);
    cout << "\n 4 in v " << (s.searchMatrix(v, 4) ? "true" : "false");
    cout << "\n 12 in v " << (s.searchMatrix(v, 12) ? "true" : "false");
    cout << "\n 17 in v " << (s.searchMatrix(v, 17) ? "true" : "false");
    cout << "\n 21 in v " <<( s.searchMatrix(v, 23) ? "true" : "false");
    cout << "\n 40 in v " << (s.searchMatrix(v, 40) ? "true" : "false");
}
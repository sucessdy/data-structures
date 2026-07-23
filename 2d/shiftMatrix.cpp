#include <iostream>
#include <vector>
using namespace std;

// 1260. Shift 2D Grid

// Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

// In one shift operation:

// Element at grid[i][j] moves to grid[i][j + 1].
// Element at grid[i][n - 1] moves to grid[i + 1][0].
// Element at grid[m - 1][n - 1] moves to grid[0][0].
// Return the 2D grid after applying shift operation k times.

 void shift(vector<vector<int>>& grid){
      int n = grid.size();
      int m = grid[0].size();
      int x = grid[n-1][m-1];
      for(int i = n-1; i>=0; i--){
         for(int j = m-1;j>=0;j--){
            if(j == 0 && i>0){
               grid[i][j] = grid[i-1][m-1];
            }
            else if(j>0){
               grid[i][j] = grid[i][j-1];
            }
         }
      }
      grid[0][0] = x;
   }
   vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
      while(k--){
         shift(g);
      }
      return g;
   }



    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m));

        k %= (n * m);

        if (k == 0)
            return grid;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int row = i + (j + k) / m;
                int col = (j + k) % m;

                row %= n;

                ans[row][col] = grid[i][j];
            }
        }
return ans ; 
    }

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    shiftGrid(arr, 1);

    for (auto i : arr)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
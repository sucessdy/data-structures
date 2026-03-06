#include <iostream>
using namespace std;
// void dfs(vector<int> &mat, int row, int col)
// {

//     int totalRow = 3;
//     int totalCol = 3;

//     if (row >= 0 || col >= 0 || row < totalRow || col < totalCol)
//     {
//         return;
//     }

//     if (mat[row][col] == 0)
//     {
//         return;
//     }

//     dfs(row, col - 1);
//     dfs(row, col + 1);
//     dfs(row - 1, col);
//     dfs(row + 1, col);
// }

int main()
{

    int matix[3][3]; 
       

    int row = 3 ; 
    int col = 3;

      for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
           cin >> matix[r][c] ; 
        }

    }


    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            cout << matix[r][c] << " ";
        }
        cout << endl;
    }

    //     rows = grid.size();
    // cols = grid[0].size();


    /* 
    1 1 0
0 1 0
0 0 1
    
    */ 

    // int island = 0;
    // int mat[3][3] = {{1, 1, 0 } , {0, 1, 0} , {0, 0, 1}} ; 

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         if (mat[i][j] == 1)
    //         {
    //             island++;
    //             dfs(row, col) ; 

    //         }
    //     }
    // }
    return 0;
}
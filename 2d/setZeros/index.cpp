#include <iostream>
#include <vector>
using namespace std;
void setZeroes(vector<vector<int>> &matrix)
{
    int r= matrix.size();
    int c = matrix[0].size();  // time complexity : O(r*c)

vector<bool> row(r , false) , col (c, false) ;  // space  O(r + c)


    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 0)
            {
               row[i] = true; 
               col [j] = true; 
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (row[i] || col[j])
            {
              matrix[i][j] = 0  ; 
            }
        }
    }

   
    }



int main()
{

    vector<vector<int>> mat = {{1,1,1},{1,0,1},{1,1,1}} ;
setZeroes(mat)  ;
 
for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
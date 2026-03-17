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



    // class Solution {
// public: optimal one... O(1)
    void setZeroes(vector<vector<int>>& matrix) 
    {
        bool rowzero=false,colzero=false;
        for(int j=0;j<matrix[0].size();j++)
            if(matrix[0][j]==0)
            {
                rowzero=true;
                break;
            }
        
        for(int i=0;i<matrix.size();i++)
            if(matrix[i][0]==0)
            {
                colzero=true;
                break;
            }
        
        for(int i=1;i<matrix.size();i++)
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }

        for(int i=1;i<matrix.size();i++)
            for(int j=1;j<matrix[0].size();j++)
        {
           if(matrix[i][0]==0 ||  matrix[0][j]==0)
                matrix[i][j]=0;     
        }

        if(colzero)
        {
            for(int i=0;i<matrix.size();i++)
                matrix[i][0]=0;
        }

        if(rowzero)
        {
            for(int j=0;j<matrix[0].size();j++)
                matrix[0][j]=0;
        }
        
    }
          
    
// };/

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
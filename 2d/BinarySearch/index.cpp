#include <iostream>
#include <vector>
using namespace std;

bool SearchMatrix(vector<vector<int>> &matrix, int row, int col, int target)
{


    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
        }
    }

    return false;
}

pair<int, int>  BinarySearchValue (vector<vector<int>> & mat , int target){
int row  = mat.size() ; 
int col = mat[0].size() ; 
int left = 0;
int right = row * col -1;



while (left <= right){ 
    int mid = left + (right - left) / 2; 

    int r = mid / col ; 
    int c = mid % col; 
    if (mat[r][c] == target ){ 
        return {r,c} ; 
    }
    else if (mat[r][c] < target){
        left = mid +1; 
    }
    else {
right = mid -1; 
    }

}

return {-1, -1} ;  




}




int main()
{
vector<vector<int>>  nums = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

  
    int target = 11;
 pair<int, int> res = BinarySearchValue(nums, target);
   cout << "Row = " << res.first << endl;
    cout << "Col = " << res.second << endl; 
    return 0;
}
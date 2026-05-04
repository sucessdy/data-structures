#include <iostream>
#include <vector>
using namespace std;

// vector<int> rotate(vector<vector<int>> &matrix)
// {
//     int row = matrix.size();
//     int col = matrix[0].size();
//     int left = 0;
//     int right = row - 1;
//     int top = 0;
//     int bottom = col - 1;
//     vector<int> ans;
//     while (top <= bottom && left <= right)
//     {
//         for (int i = left; i <= right; i++)
//         {
//             ans.push_back([matrix[top][i]]);
//         }
//         top++;
//         for (int i = top; i <= bottom; i++)
//         {
//             ans.push_back(matrix[i][right])
//         }
//         right--;
//         if (top <= bottom)
//         {
//             for (int i = right; i >= left; i--)
//             {
//                 ans.push_back(matrix[bottom][i]);
//             }
//             bottom--;
//         }

//         if (left <= right)
//         {
//             for (int i = bottom; i >= top; i--)
//             {
//                 ans.push_back(matrix[i][left]);
//             }
//             left++;
//         }
//     }
//     return ans;
// }

// void Rotate(vector<vector<int>> &mat)
// {
//     int n = mat.size();

//     // int m = mat[0].size( ) ;
//     // transpose
//     for (int i = 0; i < n; i++)
//     {

//         for (int j = i; j < n; j++)
//         {

//             swap(mat[i][j], mat[j][i]);
//             // cout << "matrix: ij " << mat[i][j] << " matrix ji : "<< mat[j][i] <<  endl;
//         }
//         // continue;
//     }
//     // reveser
//     for (int i = 0; i < n / 2; ++i)
//     {
//         swap(mat[i], mat[n - i - 1]);
//     }

//     // for (int j = 0; j < n; j++) {
//     //             reverse(mat[j].begin(), mat[j].end());

//     //         }
// }
// void Rotate(vector<vector<int>> &mat)
// {
//     int row = mat.size();
//     int col = mat[0].size();

//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (mat[i][j])
//         }
//     }
// }

// bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
// {
//     // int n = mat.size();

//     for (int i = 0; i < 4; i++)
//     {
//         if (mat == target)
//         {
//             return true;
//         }

//         Rotate(mat);
//     }
//     return false;
// }

// class Solution
// {
// public:
//     bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
//     {
//         int n = mat.size();
//         bool r0 = true, r90 = true, r180 = true, r270 = true;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (mat[i][j] != target[i][j])
//                 {
//                     r0 = false;
//                 }
//                 if (mat[i][j] != target[j][n - i - 1])
//                 {
//                     r90 = false;
//                 }
//                 if (mat[i][j] != target[n - 1 - i][n - j - 1])
//                 {
//                     r180 = false;
//                 }
//                 if (mat[i][j] != target[n - j - 1][i])
//                 {
//                     r270 = false;
//                 }
//             }
//         }
//         return r0 || r90 || r180 || r270;
//     }
// };
// vector<int> RotateMat(vector<vector<int>> &matrix)
// {
//     int row = matrix.size();
//     vector<int> ans;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             swap(matrix[i][j], matrix[j][i]);
//             ans.push(matrix[i][j]);
//         }
//     }

//     for (int i = 0; i < n / 2; i++)
//     {
//         swap(mat[i], mat[n - i - 1]);
//     }
//     return ans;
// }
// void rotate(vector<vector<int>> &matrix)
// {
//     int n = matrix.size();

//     for (int i = 0; i < n; i++)
//     {
//     }
// }

void RotateImage(vector<vector<int>> &mat)
{

    int row = mat.size();
    int col = mat[0].size();
    vector<int> ans;

    for (int i = 0; i < row -1 ; i++)
    {
        for (int j = i + 1; j < col; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for ( int i = 0; i < row ; i ++) { 
        reverse(mat[i].begin() , mat[i].end()) ; 
    }
}


int main()
{
    vector<vector<int>> mat = {{1,2,3}, {4,5,6}, {7, 8 , 9}};
    // vector<vector<int>> t = {{1, 0}, {0, 0}};
    RotateImage(mat);
    int n = mat.size() ; 
    for ( int i = 0;i < n  ; i ++){
        for ( int j = 0; j < n ; j ++) { 
            cout<< mat[i][j] ; 
        }
        cout << endl;
    }
// for (auto i : mat)
    // cout << (res ? "true" : "false") << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void LinearSearch(int mat[][4], int row, int col, int target)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == target)
            {
                cout << " Found at row : " << i << " column : " << j << " ";
                return;
            }
        }
    }
    cout << " not found the target";
}
bool SearchSortedMatrix(int mat[][4], int row, int col, int target)
{
    int i = 0;
    int j = col - 1;

    while (i < row && j >= 0)
    {
        if (target == mat[i][j])
        {
            return true;
        }
        else if (target > mat[i][j])
        {
            i++; // row
        }
        else
        {
            j--; // col
        }

        // i++;
        // j--;
    }
    return false;
}

void SearchSorted2d(vector<vector<int>> &mat, int row, int col, int target)
{

    int i = 0;       // row
    int j = col - 1; //  // col

    while (i < row && j >= 0)
    {
        if (mat[i][j] == target)
        {
            cout << "Found  row -> " << i << " cols -> " << j << endl;
            return;
        }
        else if (

            mat[i][j] > target)
        {
            j--;
            cout << "left-> " << j << endl;
        }
        else
        {
            i++;
            cout << "down-> " << i << endl;
            ;
        }
    }
    cout << "not found";
}
int main()
{

    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int row = 4;
    int col = 4;
    int target = 10;
    SearchSorted2d(mat, row, col, target);

    // int mat[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    // // vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    // int row = 4;
    // int col = 4;
    // int target = 10;

    // bool res = SearchSortedMatrix(mat, target);
    // cout << (res ? "true" : "false") << endl;

    return 0;
}
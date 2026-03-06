#include <iostream>
#include  <vector> 
using namespace std;

void LS(int matrix[][4], int row, int col, int target) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            if (matrix[i][j] == target) {
                cout << "Found at: " << i << "," << j << endl;
                return;
            }

        }
    }

    cout << "Element not found";
}
// binary Search

bool search2dMatrix(vector<vector<int>> & mat, int target) { 

    int row = mat.size(); 
    int col = mat[0].size(); 
    int st = 0;
     int end = col - 1; 

     
}
int main() {

    // int matrixes[4][4] = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12},
    //     {13, 14, 15, 16}
    // };

    // int row = 4;
    // int col = 4;

    // int target = 2;

    // LS(matrixes, row, col, target);

    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    bool res = search2dMatrix(mat, 8 ); 
    cout << (res ? "true" : "false ") << endl;  

return 0; 

}
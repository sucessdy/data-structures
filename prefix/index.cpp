#include <iostream>
#include <vector>
using namespace std;
void subarray(vector<int> &arr)
{

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << " ";
            }

         cout << endl; 
        }
    }
}

int main()
{

    vector<int> arr = {1, 2, 3};
    subarray(arr);
    return 0;
}
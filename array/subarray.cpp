#include <iostream>
#include <vector> 

using namespace std;

void subarray(vector<int> &arr)
{
    // vector<int> temp =0 ;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            // temp.push_back(arr[j]) ;
            for (int k = i; k <= j; k++)
            {
                cout << arr[k];
            }
            cout << " ";
        }
        cout << endl;
    }
}

int main()
{

    vector<int> arr = {1, 2, 3} ;
    subarray(arr) ;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

// Given an array of integers, find the maximum element.
// Input: input i' ll give is very hard .. try to solve this without any built in function like map (in js )...or max 
// Output: only max value 
// Pattern: and simple logic where we check with very number and we try to store that number which is max so 
// Time: O(n) and space (1) 
// Edge cases: for negative and single value is stll the maximum and duplicate.. 

int maximum(vector<int> &arr)
{

    if (arr.size() == 0)return -1;
    
    int max = INT_MIN ; 

    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

vector<int> Prefix (vector<int> arr) {
    int size = arr.size() ; 

    vector<int> prefix(size) ; 
prefix[0] = arr[0] ; 
for (int i = 1; i < size ; i ++) { 
prefix[i] =prefix[i -1  ] + arr[i];
}
return prefix;

}
int main()
{
    vector<int> n = {100, 80,100, 8999, 9999999};
    cout << maximum(n) << endl;
    vector<int> arr =  {10, 20, 10, 5, 15};

    vector<int> ans= Prefix(arr) ; 
    for (auto i : ans){ 
        cout << i << endl;

    }

    return 0 ;

}
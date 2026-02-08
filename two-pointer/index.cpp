// Question: Pair Sum in a Sorted Array

// Problem Statement:
// Given a sorted array of integers arr[] of size n and an integer X, determine whether there exists a pair of elements in the array whose sum is equal to X.

// Pattern: Two-pointer cus the array is sorted and we need to meet the target and its pair 
// Why: I also try to do with nested loop and and but i think i just need a pair so, we can sum the pair and move the pointer left and right and see and match the target and here we want to return the boolean function we crate and return the true and false ; 
// Time Complexity:O(n)
// Space Complexity: constant
// Edge Cases:

#include <iostream>
#include <vector>
using namespace std;
bool PairSum(vector<int> &arr, int target)
{

    if(arr.size() < 2) return false; 
    int st = 0;
    int end = arr.size() - 1;

    while (st < end)
    {
        int sum = arr[st] + arr[end];
        if (sum == target)
        {
            return true;
        }
        else if (sum < target)
        {
            st++;
        }
        else
        {
            end--;
        }
    }
    return false;
}

int main()
{
    vector<int> a = {1 } ;
    //  cout << PairSum(a, 4 ) << endl ;
    bool pair = PairSum(a, 6);
    if (!pair)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }

    return 0;
}
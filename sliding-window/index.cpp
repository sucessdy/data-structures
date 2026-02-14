#include <iostream>
#include <vector>
using namespace std;
// fixed size window type 
int ConstantWindow(vector<int> &arr , int k) {
    int n = arr.size( ); 
    
    int maxSum = 0; 

    for (int i = 0; i < k ; i++){ 
        maxSum+= arr[i];
    }
    int window = maxSum ; 

    for (int i = k ; i< n; i++){ 
        window+= arr[i];  // add 
        window-=arr[i -k];  // remove
        maxSum= max(maxSum, window) ; 
    }
    return maxSum ; 


}
// Maximum Sum of a Subarray with K Elements 
// this si where we Try every window 
int MaximumSubarray(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxsum = INT_MIN; 

 
    for (int i = 0; i <= n - k; i++)
    {
           int sum = 0;
    

        for (int j = 0; j < k; j++)
        {
            sum += arr[i + j]; // here its sum
        }
        maxsum = max(sum, maxsum); // here we get the max value
    }
    return maxsum; // return the max vale
}
int maxSubarray(vector<int> &a, int k)
{

    int windowSum = 0;
    for (int i = 0; i < k; i++)
    {
        windowSum+= a[i];
    }
    int  maxSum = windowSum;
    for (
        int j = k;
        j < a.size() ; j++)
    {
        windowSum += a[j];
        windowSum -= a[j - k]  ;
        maxSum = max(windowSum, maxSum);
    }
    return maxSum;
}


int main()
{

    vector<int> arr = {5, 2, -1, 0, 3};
    int k = 3;

    //  cout <<  MaximumSubarray(arr , k) << endl;
    cout << ConstantWindow(arr, k) << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
// fixed size window type
int ConstantWindow(vector<int> &arr, int k)
{
    int n = arr.size();

    int maxSum = 0;

    for (int i = 0; i < k; i++)
    {
        maxSum += arr[i];
    }
    int window = maxSum;

    for (int i = k; i < n; i++)
    {
        window += arr[i];     // add
        window -= arr[i - k]; // remove
        maxSum = max(maxSum, window);
    }
    return maxSum;
}
// Maximum Sum of a Subarray with K Elements
// this si where we Try every window
// this is brute force 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result ; 
        int n = nums.size() ;
        for (int i = 0; i <= n - k ; i++){
            int maxSum = nums[i] ; 

         
            for (int j = 1 ; j < k ;j ++){ 
             
                maxSum = max(maxSum, nums[i + j] ); 
            }
            result.push_back(maxSum); 
        }
        return result; 
    }

    // maximum subarray size of k 
int maxSubarray(vector<int> &a, int k)
{
   

    int windowSum = 0;
    for (int i = 0; i < k; i++)
    {
        windowSum += a[i];
    }
    int maxSum = windowSum;
    for (
        int j = k;
        j < a.size(); j++)
    {
        windowSum += a[j] - a[j - k];
        // windowSum -= a[j - k];
       
        maxSum = max(windowSum, maxSum);
       
    }
    return maxSum;
}
// If goal = SUM of each window
//  3 -1 1 5 14 16 

vector<int> maxSubarrayOptime(vector<int> &a, int k)
{
    vector<int> ans;

    int windowSum = 0;
    for (int i = 0; i < k; i++)
        windowSum += a[i];

    ans.push_back(windowSum); // first window

    for (int j = k; j < a.size(); j++)
    {
        windowSum += a[j];
        windowSum -= a[j - k];
        ans.push_back(windowSum);
    }
    return ans;
} 

// If goal = MAX SUM among all windows

// Then return int, not vector<int>:

// ans =  16
int maxSubarrays(vector<int> &a, int k)
{
    int windowSum = 0;
    for (int i = 0; i < k; i++)
        windowSum += a[i];

    int maxSum = windowSum;

    for (int j = k; j < a.size(); j++)
    {
        windowSum += a[j];
        windowSum -= a[j - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}

int main()
{

    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    // cout << MaximumSlidingWindow(arr, k ) < endl; 
// cout << maxSubarrays(arr, k) << endl; 
    vector<int> answer =maxSlidingWindow(arr, k);
    for (auto i : answer)
    {
        cout << i << " ";
    }
    cout << endl;

    //  cout <<  MaximumSubarray(arr , k) << endl;
    // cout << ConstantWindow(arr, k) << endl;

    return 0;
}
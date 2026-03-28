// 50. Pow(x, n)
#include <iostream>
#include <vector>
using namespace std;
// maximum subarray sum
/*
🧩 Your DSA Question (Today)
🔹 Problem: Maximum Subarray Sum

👉 Given an array of integers nums, find the maximum sum of a contiguous subarray.

📥 Example:
Input:  nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6

👉 Explanation:
Subarray [4, -1, 2, 1] → sum = 6
*/

int maxSubArray(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {

        int curr = 0;
        for (int j = i; j < n; j++)
        {
            curr += nums[j];
            maxSum = max(curr, maxSum);
        }
    }
    return (maxSum == INT_MIN ? -1 : maxSum);
}

int maxSubArraywithOptimal(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int n = nums.size();
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += nums[i];
        maxSum = max(curr, maxSum);
        if (curr < 0)
        {
            curr = 0;
        }
    }
    return maxSum;
}

int maxSubarrayDeleteByOne(vector<int> &nums)
{

    int n = nums.size();

    int res = 0;


    int curr = 0;
     int prev= 0; 
    for (int i = 0; i < n; i++)
    {

 curr = max(prev ,nums[i] + curr);

 prev = max(nums[i] , nums[i] + prev) ; 


          res = max( res, max(prev , curr)) ;
          cout <<  "res " <<  res << endl; 
    }

    return res;
}
int main()
{
    vector<int> nums = {1,-2,0,3};
    cout << maxSubarrayDeleteByOne(nums) << endl;
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
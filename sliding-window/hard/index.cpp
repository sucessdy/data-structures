// Problem: "Maximum Sum of 3 Non-Overlapping Subarrays"
// Difficulty: Hard (but crackable with logic)

// Description:
// Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with the maximum sum, and return their starting indices (0-indexed).

// If multiple answers exist, return the lexicographically smallest one.

// Constraints:

// 1 <= k <= n / 3

// n == nums.length

// 1 <= n <= 2 * 10^4

// -10^4 <= nums[i] <= 10^4

// Example 1:

// text
// Input: nums = [1,2,1,2,6,7,5,1], k = 2
// Output: [0,3,5]
// Explanation: Subarrays: [1,2] (sum 3), [2,6] (sum 8), [7,5] (sum 12) → total 23.
// Other combos: [1,2] [6,7] [5,1] total 22, etc.
// Example 2:

// text
// Input: nums = [1,2,3,4,5,6], k = 1
// Output: [3,4,5]
// Explanation: 4+5+6 = 15 is max.

// 689. Maximum Sum of 3 Non-Overlapping Subarrays
#include <iostream>
#include <vector>
using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
{
    vector<int> ans;
    int n = nums.size();
    long long maxSum = LLONG_MIN;
    vector<long long> prefixSum(n + 1, 0); //
                                           // Precompute prefix sums to quickly find subarray sums

    for (int i = 0; i < n; i++)
    {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    //       // Iterate through all possible starting indices for the three subarrays
    for (int i = 0; i <= n - 3 * k; ++i)
    {
        for (int j = i + k; j <= n - 2 * k; ++j)
        {
            for (int l = j + k; l <= n - k; ++l)
            {
                long long sum1 = prefixSum[i + k] - prefixSum[i];
                long long sum2 = prefixSum[j + k] - prefixSum[j];
                long long sum3 = prefixSum[l + k] - prefixSum[l];
                long long currSum = sum1 + sum2 + sum3;
                if (currSum > maxSum)
                {
                    maxSum = currSum;
                    ans = {i, j, l};
                }
                else if (currSum == maxSum)
                {
                    vector<int> temp = {i, j, l};
                    if (temp < ans)
                    {
                        ans = temp;
                    }
                }
            }
        }
    }
    return ans;
}

vector<int> maxSumofThreeSubarryOptimal(vector<int> &nums, int k)
{
    vector<int> result;
    int j = 0;

    long long maxSum = LLONG_MIN;

    int currSum = 0;

    int n = nums.size();

    vector<long long> windowSum(n - k + 1);
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i <= n - k; ++i)
    {
        windowSum[i] = prefixSum[i + k] - prefixSum[i];
    }
    // right[i] = index of best subarray from i -> end
    vector<int> right(n - k+1) ; 
    
    for (int i = 0; i < j - k; ++i)
    { // i
        for (int l = j + k; l < n; ++l)
        { // l
            if (j >= i + k)
            { // overlap logic
            }
        }
    }
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 6, 7, 5, 1};
    int k = 2;
    vector<int> res = maxSumOfThreeSubarrays(nums, k);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// TIME TAKEN -> 4hours + 30 mins

/*
Problem: REVISED
Given an integer array nums, return the maximum sum of a contiguous subarray.

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] = 6
*/
// brute force
// This is brute i can think of, i run a two loop for making the boundary and selection also.. with k loop i can make a pair of.. pointer. from all the possible subarray... then with curr i can add to the nums[k] so i can get the curr subarrays with next line will be finding the maximum subarray  then stil one edge case is that ... what if happend if i encounter any negative ... so our curr... must reset to 0 .. when my curr became 0 .. so we must resetto 0 then next value we addd ... if all the value is negative then negative maximum we should return not 0 ... i also check if array is blank or haaving a single value.. then we should return that number..
//
int MaximumContigousSubarray(vector<int> &nums)
{
    int n = nums.size();
    int maxElement = INT_MIN;
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];
    for (int i = 0; i < n; ++i)
    {

        for (int j = i; j < n; ++j)
        {
            int curr = 0;
            for (int k = i; k <= j; k++)
            {
                curr += nums[k];
            }
            maxElement = max(curr, maxElement);
        }
    }
    return maxElement;
}
// TC :  O(n cube)
// SC : constant
// little optimise with O (n cube ) -> to O (n square) -> to remove one loop its a extra loop k in above code.. where i remove cuz i want subarray pair.. with j =i .. i can create a subarrys..which reduced my time complexitty
int MaximumSubarrayOrder2(vector<int> &nums)
{
    int maxSub = INT_MIN;
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        int curr = 0;
        for (int j = i; j < n; j++)
        {
            curr += nums[j];
            maxSub = max(curr, maxSub);
        }
    }
    return maxSub;
}
// TC :  O(n square)
// SC : constant

int maximumBetterOneh(vector<int> &nums)
{

    int maxSub = nums[0];
    int curr = nums[0];
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        /// little improvment heree
        // curr += nums[i];
        // maxSub = max(curr, maxSub);
        // must be this .

        curr = max(nums[i], curr + nums[i]);
        // cout << "curr : " << curr << endl;
        maxSub = max(maxSub, curr);
        // cout << "max :  " << maxSub << endl;
    }

    return maxSub;
}

// TC :  O(n)  loop run once for all the value
// SC : constant  no extra space i didint create any other data struture or even a variable for store only int max and int curr this is constant

// only able to return the array not st, end , max -> i'm tired here to even think any furthur
vector<vector<int>> MaximumSub(vector<int> &nums)
{
    int maximum = INT_MIN;
    int n = nums.size();
    int curr = 0;
    for (auto i : nums)
    {
        curr += i;
        if (maximum < curr)
            maximum = curr;
        if (curr < 0)
            curr = 0;
    }

    vector<vector<int>> result;
    for (int i = 0; i < n; ++i)
    {
        int currSum = 0;
        for (int j = i; j < n; j++)
        {
            currSum += nums[j];
            if (maximum == currSum)
            {
                result.push_back(vector<int>(nums.begin() + i, nums.begin() + j + 1));
            }
        }
    }

    return result;
};

// what should you return?

// Since we need 3 things:

// maxSum
// startIndex
// endIndex

vector<int> MaximumSumReturnAlltheValue(vector<int> &nums)
{
    int curr = nums[0];
    int maximum = nums[0];
    int start = 0;
    int end = 0;
    int tempStart = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > curr + nums[i])
        {
            curr = nums[i];
            tempStart = i;
        }
        else
        {
            curr += nums[i];
        }

        if (curr > maximum)
        {
            maximum = curr;
            start = tempStart;
            end = i;
        }
    }
    return {maximum, start, end};
}

int maximumBetterOne(vector<int> &nums)
{

    int maxSub = nums[0];
    int Totalsum = nums[0];
    int minSub = nums[0];
    int curr = nums[0];
    int currMin = nums[0];
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        curr = max(nums[i], curr + nums[i]);
        maxSub = max(maxSub, curr);
        currMin = min(nums[i], currMin + nums[i]);
        minSub = min(minSub, currMin);

        Totalsum += nums[i];
          if (maxSub < 0)
        return maxSub;
    }


  
    // for (int i = 1 ; i < nums.size() ; ++i){
    //  int cap = nums(i  + 1% nums.size()  ) ;

    // }

    int maximumCircular = Totalsum - minSub;
    cout << Totalsum << "total sum " << minSub << "minsub" << endl;
    // Min

    // if (!maximumCircular){
    // return maxSub;
    // }
    // else {
    //   return   maximumCircular;
    // }
    // if (maximumCircular> max)

if (maximumCircular == minSub) { 
    return maxSub;  
}

// else { 
//     return minSub; 

// }
 
    return max( maxSub, maximumCircular);
}
int main()
{
    vector<int> nums = {-3,-2,-3};
    // vector<int> n = {-99, 100, -444};
    // cout << MaximumContigousSubarray(nums) << endl;
    cout << maximumBetterOne(nums) << endl;

    // vector<int> arr = {1, 2, 3, -4};
    // vector<int> res = MaximumSumReturnAlltheValue(arr);

    // for (auto i : res)
    // {
    //     // for (const auto it : i)
    //     // {
    //         cout << i << " ";
    //     // }

    // }   cout << endl;

    return 0;
}
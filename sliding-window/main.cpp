#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
// dyamic window
vector<int> longestSubarray(vector<int> &arr, int k)
{
    vector<int> ans;
    int n = arr.size();
    int maxLen = 0;
    int st, end = -1;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {

            sum += arr[j];

            if (sum <= k && (j - i + 1) > maxLen)
            {
                // maxLen = max(maxLen , j - i + 1);
                maxLen = j - i + 1;
                st = i;
                end = j;
            }
        }
    }

    if (st != -1)
    {
        for (int i = st; i <= end; i++)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int LongestSubarraywithBetter(vector<int> &arr, int k)
{
    int l = 0;
    int r = 0;
    int maxLen = 0;
    int sum = 0;
    while (r < arr.size())
    {

        sum += arr[r];

        // i need ti check the invalid condition
        while (sum > k)
        {
            sum -= arr[l];

            l++;
        }

        if (sum <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }

        r = r + 1;
    }
    return maxLen;
}

int longesubstring(string s, int k)
{
    unordered_map<char, int> mpp;
    int maxlen = 0;
    for (int i = 0; i < s.length(); i++)
    {
        mpp.clear();
        for (int j = i; j < s.length(); j++)
        {
            mpp[s[j]]++;

            if (mpp.size() <= k)
            {
                maxlen = max(maxlen, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    return maxlen;
}

int longestSubStringwithOptimal(string s, int k)
{
    int l = 0;
    int maxLen = 0;
    unordered_map<char, int> m;
    for (int r = 0; r < s.size(); r++)
    {
        m[s[r]]++;
        while (m.size() > k)
        {
            m[s[l]]--;
            if (m[s[l]] == 0)
            {
                m.erase(s[l]);
            }
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}

// smallest subarray with sum >= k

int minSubArrayLen(vector<int> &nums, int target)
{ 
    // if (nums.size() < 0){
    //     return -1; 
    // }
    int minSub = INT_MAX;

    
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
         
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];

            if (sum >= target)
            {
         minSub = min(minSub, (j - i + 1));
   
          
            }
            
           
        }
    }
    return minSub; 
}

int minSubArrayLenwithOptimse(vector<int> &nums , int target){ 
    int sum = 0 ; 
    int minLen = INT_MAX ;
    int l = 0; 

  for (int r = 0 ;  r < nums.size( ) ; r++) {
    sum+= nums[r] ; 
    while ( sum >= target) { 
        minLen = min(minLen, (r - l + 1) ) ; 
        sum-=nums[l] ; 
        l++; 
    }
 
  } 
  return( minLen == INT_MAX )? 0 : minLen ; 

}


int maxlongestSubarray(vector<int> &arr, int target)
{
    int maxlen = INT_MIN; 

    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
           
            // cout << "front arrj" << arr[j]  << endl; 
            sum += arr[j];
// cout << "after sum arrj" << arr[j]  << endl; 
            if (sum == target )
            {

                maxlen = max(maxlen, (j - i + 1));
            }
        }
    }
    return maxlen;
}

int main()
{

    // string s = "eceba";
    // int k = 2;

    // cout << longestSubStringwithOptimal(s, k) << endl;

    vector<int> nums = {5,1,3, 10 , 1 , 4};
    int target = 15;
    cout << minSubArrayLenwithOptimse(nums, target) << endl;

    //  vector<int> arr = {10, 5, 2, 7, 1, 90};
    // int k = 15;
    // vector<int> ans = longestSubarray(arr, k);
    // for  ( auto i : ans){
    //     cout << i << " ";
    // }cout << endl;

    // cout << LongestSubarraywithBetter(arr, k) << endl;
    return 0;
}
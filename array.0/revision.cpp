// 50. Pow(x, n)
#include <iostream>
#include <vector>
#include <cctype>
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
    int prev = 0;
    for (int i = 0; i < n; i++)
    {

        curr = max(prev, nums[i] + curr);

        prev = max(nums[i], nums[i] + prev);

        res = max(res, max(prev, curr));
        cout << "res " << res << endl;
    }

    return res;
}

string lowerString(string s)
{
    for (char &ch : s)
    {
        ch = tolower(ch);
    }
    return s;
}

    bool canBeEqualOptimal(string s1, string s2) {
        for (int i = 0; i < 2; i++){
            if(s1[i] != s2[i]){
                swap(s1[i], s1[i+2]);
            }
        }
        return s1 == s2;
    }

// optimal  

bool canBeEqual(string s1, string s2)
{
    vector<vector<int>> charFrequency(2, vector<int>(26, 0));
    for (int i = 0; i < s1.length(); ++i)
    {

        int parity = i & 1;
        ++charFrequency[parity][s1[i] - 'a'];
        --charFrequency[parity][s2[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i)
    {
        if (charFrequency[0][i] != 0 || charFrequency[1][i] != 0)
            return false;
    }

    return true;
}


bool canBeEqualAlternate(string s1, string s2){ 
    // group   
    string a1 = {s1[0] , s1[2]};
    string a2 = {s1[1] , s1[3]};
    // group.  b
    string b1= {s2[0] , s2[2]};
    string b2= {s2[1] , s2[3]};

    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    sort(b1.begin(), b1.end());
    sort(b2.begin(), b2.end());
    return (a1 == b1 ) && (a2 == b2) ;   
    
    for (int i = 0; i < s1.length() ; i++){
        if ( i % 2 == 0) { 
            
        }
    }

}




int main()
{

    string s1 = "abcdef";
    string s2 = "cdabef";
    bool res = canBeEqualAlternate(s1, s2);
    cout << (res ? "true" : "false") << endl;
    cout << endl;

    return 0;
}
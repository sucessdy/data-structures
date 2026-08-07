#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

// vector<int> findMissingElements(vector<int>& nums) {

//     vector<int> ans;
//     int i = 0 ;
//     int n = nums.size();
//     while (i <= n)
//     {
//         int index = nums[i] -1  ;

//         if (nums[i] != nums[index])
//         {
//             swap(nums[i], nums[index]);
//         }
//         else
//         {
//             i++;
//         }
//     }
//     for (int it = 0; it < n; it++)
//     {
//         if (nums[it] != it  + 1 )
//         {
//             ans.push_back({it + 1} );
//         }
//     }
//     return ans;

//     }

//     vector<int>  firstmissingElement(vector<int> &nums)   {
//     int n = nums.size() ;
//     vector<int> ans;
//     vector<bool> seen(n , false ) ;
//     for ( auto i : nums) {
//         if (i > 0 && i <= n) {
// seen[n] = true;
//         }
//     }
//     for ( int i = 1 ; i <=n ; i++) {
//         if ( !seen[i] ) {
//             ans.push_back( ) ;
//         }
//     }

//     return ans;
// }

// vector<int> findMissingElement(vector<int> &nums)
// {
//     if (nums.empty())
//         return {};

//     int maxVal = *max_element(nums.begin(), nums.end());
//     int minVal = *min_element(nums.begin(), nums.end());

//     unordered_set<int> s(nums.begin(), nums.end());
//     vector<int> missingRange;

//     for (int i = minVal; i <= maxVal; i++)
//     {
//         i
//     }
//     return missingRange;
// }

// vector<int> findMissingElements(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     int n = nums.size();
//     vector<int> missing;

//     for (int i = 0; i < n - 1; i++)
//     {
//         if (nums[i + 1] != nums[i] + 1)
//         {
//             for (int j = nums[i] + 1; j < nums[i + 1]; j++)
//             {
//                 missing.push_back(j);
//             }
//         }
//     }
//     return missing;
// }

vector<int> FindMissingElements(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> ans;
    int i = 0;
    int n = nums.size();
    while (i < n -1 )
    {
        int curr = nums[i] + 1;
        while (i < n - 1 && nums[i + 1]  > curr)
        {
            ans.push_back(curr);
          curr++; 
        }
        i++;
      
    }

    return ans;
}

int main()
{
    vector<int> nums = {5, 1};
    vector<int> ans = FindMissingElements(nums);
    for (auto i : ans) 
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
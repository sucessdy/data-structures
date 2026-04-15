#include <iostream>
#include <vector>
#include <map>
using namespace std;
// brute forcesss

/* 
i'm using two loops.. for making a pair... to check with target .. i',m triying every pair, time complexity -> O (n square) cuz we 're suing two loops for finding the every combination.. for checking the target... 
*/
vector<int> TwoSum(vector<int> &nums, int target)
{
   

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1 ; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target )
            {
                return {i, j}; // return the index.. 
            }
        }
    }
    return {-1, -1}; // handing the edge case..
}

// optimal -> 
vector <int> TwoSumOptimal(vector<int> & nums, int target) {
map<int, int> mp;  // used the map .... for ordered data... at the worst case its will take tC ->  ( log n ) whereas the TC -> O (n) .. if collison occurs if amotrized will be contstant time. complexity for unorreder _mp .. 
     int n = nums.size() ; // veector size 
     for (int i= 0; i < n; ++i){ // loop 
        int first = nums[i] ; 
        int second = target - first;  // just a simple trick..here.. if i have tow value can't i find the thried .. one i can.. so taget - first= second or diff ...which i look at the map.. ifits presend or not.. 

if ( mp.find(second) != mp.end()){ 
            return { mp[second ], i} ; 

        }
  mp[nums[i]] = i; 



     }
     return {-1, -1} ; 



}
int main()
{

    vector<int> nums = {2, 4, 2};
    int target = 4;
    vector<int> res = TwoSumOptimal(nums, target);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
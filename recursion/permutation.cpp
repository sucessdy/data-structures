#include <iostream>
#include <vector>
using namespace std;

void backtrack( vector<int>& nums, int st, vector<vector<int>> &ans) {
    if (st == nums.size() ) {
        ans.push_back(nums);
        return; 
    }
    for (int i = st ; i < nums.size() ; i++) {
         
        
             
          swap(nums[i] , nums[st]) ; 
         backtrack(nums, st+1, ans) ; 
         swap(nums[i] , nums[st]) ; 

         }
        
         
    }
   

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans ; 
        backtrack(nums, 0, ans) ;
        return ans; 
    }


int main() {
    
    vector<int> nums = {1, 1, 2} ; 
    vector<vector<int>> ans = permuteUnique(nums) ;
    for ( auto i : ans){ 
       for (auto val : i) {
        cout << val << " " ; 
       }
    }
    cout << endl; 
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int firstMissing(vector<int> &nums) { 
sort(nums.begin(), nums.end()) ; 
int res  = 1 ; 

for ( int i =0 ;i < nums.size() ; i ++) {
    if ( res == nums[i]){
        res++;
    } 
    // else if (res > nums[i]) { 
       
    //     break; 
    // }
}

 int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        vector<bool>seen(n+1, false);

        for ( int num : nums){
            if(num>0 && num<=n){
                seen[num]=true;
            }
        }

        for ( int i=1; i<=n; i++ ){
            if(!seen[i]){
                return i;
            }
        }

        return n+1;
    }
return res; 
}
int main() {
    vector<int> nums = {1, 2,0} ; 
    cout << firstMissing(nums ) << endl;
   return 0;
}
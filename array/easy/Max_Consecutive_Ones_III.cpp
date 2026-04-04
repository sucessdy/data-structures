#include <iostream>
#include <vector>
using namespace std;
// max_consecutive one 3

int longestOne(vector<int> & nums, int k) {
    int left = 0;
    int maxLen = 0 ;
    int zeroCount = 0;
    for ( int right = 0; right < nums.size() ; right ++){
        if (nums[right] == 0){
            zeroCount++;
        }
        while(zeroCount > k){
            if(nums[left] == 0 ) {
                zeroCount--; 

            }
            left++; 

        }
        maxLen = max(maxLen, right - left + 1) ;

    }
    return maxLen; 
} 

int main (){ 
    vector<int> nums = {1, 0, 1, 0, } ;
    int k = 2 ; 
    cout << longestOne(nums, k) << endl; 
    return 0; 

}
#include <iostream>
#include <vector>
using namespace std;


    int findMin(vector<int>& nums) {
        int st = 0; 
        int end = nums.size() - 1 ;
        sort(nums.begin(), nums.end()) ; 
        
        while ( st < end)  {
            if ( nums[st] < nums[end]) {
                return nums[st];
            }

            int mid = st + (end - st) / 2 ; 

            if ( nums[mid] > nums[end]) { 
                st = mid + 1 ;
            }
            else {
                end = mid ; 
            }
        }
        return nums[st] ; 
    }

int main() {
    vector<int> nums = { 3, 3,3, 2, 1} ; 
    cout << findMin( nums) << endl;
    return 0;
}
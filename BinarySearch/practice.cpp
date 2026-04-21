#include <iostream>
#include <vector>
using namespace std;
/// optimal log n -> TC 
int KthMissingNumber (vector<int> &nums, int k ) { 
int low = 0; 
int n = nums.size() ; 
int high = n -1; 
int missing = 0; 

while ( low <= high){ 
    int mid = (low + high ) / 2; 
missing = nums[mid] - (mid + 1 ) ; 
if (missing < k) { 
    low = mid +1 ;
}
else { 
    high = mid-1; 

}

 }
 return low + k ; 

}
int main() {
    vector<int> nums= {2, 3, 4, 7, 11} ; 
    int k =5;
    cout << KthMissingNumber(nums, k)<< endl; 
    return 0;
}
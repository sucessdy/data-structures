#include <iostream>
#include <vector>
using namespace std;
int largestElement(vector<int>& nums) {
    int largest = 0 ;  
for (int i = 0 ; i < nums.size() ; i ++){ 

    if (largest  <  nums[i]) {
         largest = nums[i] ; 
    }
}
return largest ; 
    } 

int main() {
vector<int> nums = { 1, 2,34,5} ;
cout << largestElement(nums) << endl;  
    return 0;
}
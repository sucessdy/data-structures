#include <iostream>
#include <vector>
using namespace std;

int RototionCount(vector<int> &nums) { 
int st = 0; 
int end = nums.size() -1; 
while ( st <= end) { 
    int mid = st + ( end-st) / 2; 
    if ( mid < end &&  nums[mid] >  nums[mid +1 ]){ 
        return mid;
    }
    if (st < mid && nums[mid ] < nums[mid -1])  {
        return mid -1;  


    } 
    if (nums[st] >= nums[mid]){ 
        end = mid-1;
    }
    else {
        st = mid +1 ;
    }
}
return -1; 

}

int pivot(vector<int> & nums) { 
    int piv = RototionCount(nums) ;
    return piv + 1; 
}

int main() {
    vector<int> nums = {4, 5, 6, 7,0 , 1, 2} ; 
    cout << pivot (nums) << endl;
    return 0;
}
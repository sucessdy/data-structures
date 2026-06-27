#include <iostream>
#include <vector>
using namespace std;
int BinarySearch(vector<int> & nums, int tar) 
{ 

    int st = 0; 
    int end = nums.size()
 -1; 

 while ( st <= end) { 
    int mid = st + (end - st ) / 2; 
    if ( nums[mid] == tar) { 
        return mid; 
    } 
    else if ( nums[mid] < tar) { 
        st = mid +1 ;
    }
    else { 
        end = mid -1; 
    }
 }
 return st; 

 
}

int main() {
    
vector<int> nums = {1, 2 ,3 ,4,6} ; 
int tar = 5;
cout << BinarySearch(nums, tar) << endl; 
    return 0;
}
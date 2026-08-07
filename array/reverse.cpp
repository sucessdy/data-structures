// Given an integer array nums, return the number of reverse pairs in the array  
#include <iostream>
#include <vector>
using namespace std;

int mergeSort(vector<int> & nums , int temp, int st , int end) {

int mid = st + (end - st) /2; 
int count =0; 
count+= mergeSort(nums, temp , st, mid) ;
count+= mergeSort(nums, temp , mid+ 1, end) ;

int right = count + 1 ; 

for ( int idx = 0 ;idx < nums.size() ;  idx++) { 
if (right <end && (long)(long)nums[idx] > 2LL * nums[right]) { 
    count+= (right - (mid + 1)) ; 
}

}
int  i = st ; 
int j = mid +1 ;







}
int reversePairs(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int>temp (n); 
        return  

    }  
int main() {
    
    return 0;
}


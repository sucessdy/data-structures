#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int  findMinMax(vector<int> &arr, int n, int &minVal, int &maxVal) {
      vector<int> res(n);  
    // if (n == 1) {
    //     minVal = maxVal = arr[0];
    //     return;
    // }
    
    int mid = n / 2;
    int leftMin, leftMax, rightMin, rightMax;
    
    // Divide
    findMinMax(arr, mid, leftMin, leftMax);
    findMinMax(arr, mid + 1 , rightMin, rightMax);
    
    // Conquer/Combine
    minVal = min(leftMin, rightMin);
    maxVal = max(leftMax, rightMax);

    for ( int  i = minVal ;i < maxVal ; i ++) { 
     return  res.push_back(arr[i]) ; 
        
    }
    return {}; 
}

//   vector<int> findMissingElements(vector<int>& nums) {

//     vector<int> res; 
//     int n = nums.size() -1 ; 
//    return findMinMax(nums, n , 0, n-1 );
//   }

int main() {
    // int arr[] = {3, 5, 4, 1, 9};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int minVal, maxVal;
    
    // findMinMax(arr, n, minVal, maxVal);
    
    // cout << "Minimum: " << minVal << ", Maximum: " << maxVal << endl;
vector<int> nums = {1, 2,4, 6,8} ; 
   cout <<  findMinMax(nums )  << endl; 
    return 0;
}   
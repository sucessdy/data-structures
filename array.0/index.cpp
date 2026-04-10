#include <iostream>
#include <vector>
using namespace std;

int largest (vector<int> &nums) {  
     
    int maxEle = INT_MIN ; 
    for ( int i = 0; i < nums.size() ; ++i){ 
        if (nums[i] > maxEle){
            maxEle = nums[i] ; 
        }
    }
    return maxEle ; 
}
int SecondLargest(vector<int> & nums ){
int maxElem = INT_MIN;
int secondMax  =                   INT_MIN; 
    
for ( int i = 0;i < nums.size()  ; ++i){ 
    if (maxElem < nums[i]) { 
        secondMax = maxElem; 
        maxElem = nums[i] ;  
    } 

  else  if (secondMax < nums[i ] && maxElem!= nums[i]   ){
   secondMax = nums[i] ; 
         
    }
}
return secondMax; 
}

int removeDuplicated (vector<int> & nums) { 
    int j =0;
    for ( int i = 1 ;i < nums.size() ; ++i){ 
if (nums[i] != nums[j]){
     j++; 
     nums[j] = nums[i] ; 

}
    }

  return  j+ 1; 
}

int removeDuplicatedII(vector<int> & nums) { 
    int j =2;
    for ( int i = 2 ;i < nums.size() ; ++i){ 
if (nums[i] != nums[j - 2]){
     j++; 
     nums[j] = nums[i] ; 

}
    }

  return  j;  
}

void moveZeroes(vector<int> &nums) { 
int j =0 ;
 for (int i = 0 ; i < nums.size() ; ++i){
    if (nums[i] != 0) { 
        nums[j++] = nums[i] ;
    }

   
 }

 while ( j < nums.size()) { 
    nums[j++] = 0; 
 }
}
int main() {
    vector<int> nums = {0,1,0,3,12} ; 
    // cout <<moveZeroes(nums ) << endl; 
    moveZeroes(nums) ; 
    for (auto i : nums) {
        cout << i << endl;
    }

    
    return 0;
}
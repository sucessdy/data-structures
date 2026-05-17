#include <iostream>
#include <unordered_map> 
#include <vector> 
#include <algorithm>
using namespace std;


// /// 1. Two Sum 
// 1. Two Sum

// Goal: Hashing + thinking about optimization

// You’ll practice:

// brute force → O(n²)
// hashmap → O(n)

// Example:

// Input: [2,7,11,15], target = 9
// Output: [0,1]


vector<int> twoSum(vector<int>& nums, int target) { 
  
  for ( int i = 0; i < nums.size() ; i++){
    for (int j = i + 1 ; j < nums.size() ; j ++) { 
      if ( nums[i] + nums[j] == target){
         return {i , j} ; 
      } 
    }
    
  }
  return  {-1, -1} ; 
}
/// optinal one.. 
//  we using the unordered_map for avegrge case is constant but in collison occur... its O(n) but that rare 
//  we usng hashing for store the count of the diff in a element .... taget - nums[i] if we have two value we can find the thired also...
//  
vector<int> twoSumOptimal(vector<int>& nums, int target) { 
  
  unordered_map<int, int> mp; 
  for (int i = 0; i < nums.size() ; i ++) { 
    int diff = target - nums[i] ; 
    if (mp.count(diff)){ // checking i a map if the key prsent exist of not/ 
       return {  mp[diff] , i } ;  //  we store the index as a key 
    }
    mp[nums[i]] = i; 
  } 
  return {-1, -1 } ; 
}

// here without using extra space 
// but sort take ur order n log n  
// then one for loop  


// using two pointer here.  just to rid of spaxe its a trade off. 
// somwhwe u neeed to lose the time or soemtimes space complexityv 


vector<int> TwoSum(vector<int>& nums, int target) { 
  sort(nums.begin(), nums.end()) ; 
  int st = 0;
  int n = nums.size() ;
  int end = n -1 ; 
  
while ( st < end){
     int sum = nums[st] + nums[end] ; 
    if (sum == target){ 
      return {st , end} ; 
      
    }
    else if (sum < target) {
      st++; 
    }
    else { 
      end--; 
      
    }
    
  } 
  return {-1 , -1 } ; 
}

int main() 
{
   vector<int> nums = {2,7 } ; 
   int n = 9; 
   vector<int> res = TwoSum(nums, n)  ;
   for (auto i : res){
     cout << i << " ";
     
   }
   cout << endl; 
   
   
    return 0;
}
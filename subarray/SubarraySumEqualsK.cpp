#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int sumSub(vector<int> &nums , int k) { 
int sum =0; 
int n =nums.size(); 
for (int i =0; i < n ; i ++) { 
    for ( int j = i ; j <n ; j++) {
        int curr =0; 
        for ( int k = i ; k < j ; k ++) {
            curr+= nums[k] ; 
  sum = max(sum, curr) ; 
        }
        if (curr ==k){ 
return sum ; 
        }
    }
}
return -1; 
}

int sumSubOptimse(vector<int> &nums , int k) { 
int cnt  =0; 
int n =nums.size(); 
for (int i =0; i < n ; i ++) { 
      int curr =0; 
    for ( int j = i ; j <n ; j++) {
      curr+= nums[j] ; 
// sum = max(curr, sum) ; // u can do this way also ... 
        
       cnt += (curr == k);  // a nother way of oding it 
    }
    
}
return cnt; 
}

int SumSubOptimse (vector<int> & nums, int k ) {
     
    unordered_map<int, int> mp ; 
    int prefix = 0; 
    int cnt= 0 ;
    mp[0] =1 ; 
    for ( int i =0 ; i < nums.size()  ; i ++)  
    {
        prefix+= nums[i] ; 
   cnt += mp[prefix - k   ] ; 
        // cnt+= mp[remove] ; 
        mp[prefix ]++; 


    }
return cnt; 
}

int main() {
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3} ; 
    cout << SumSubOptimse(nums, 3) << endl;
    
    return 0;
}
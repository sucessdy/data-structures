#include <iostream>
#include <vector>
using namespace std;

void Rotate(vector<int> &nums, int k)
{
int n =  nums.size() ; 
 k  = k % n; 
    vector<int> temp(k);

    for (int i = 0; i < k; i++) // k=. 5, 4 , 6  = k-1 
    { 
         temp[i] = nums[n - k + i]; // temp = 5, 4, 6

    }

    for ( int  i = n - k-1  ; i >= 0; i--){ // backward loop -> cuz of shifting the element -> if we don't do this we not able to use element 
         nums[i + k] = nums[i]  ;  // 1234 
       
         
    }

 
    for ( int i = 0 ; i < k; i ++){  // print all the elemnt in the temp 
        nums[i] = temp[i] ; // 5461234 

        
    }

}

 void rotate(vector<int>& nums, int k) {
        int n = nums.size() ; 
        k = k % n ; 
        if (n == 0)return; 

        reverse(nums.begin(), nums.end()) ;  // whole array reverse 
        reverse(nums.begin(  ) , nums.begin()+ k); // last k element reverse -> 7654321 -> 567 change only the selected k element 
 reverse(nums.begin()+ k  , nums.end()) ;   // we changing the 4321 into 1234 in -place  reverse 

 
        
    }

    void reversepart (vector<int> & nums , int st, int end) { 
while (st < end){
    swap(nums[st], nums[end]) ; 
    st++; 
    end--; 

}
    }
    void rotateKelements (vector<int> & nums,int k ){
        int n = nums.size() ; 
k = k % n    ; 
reversepart(nums, 0, n-1) ; 
reversepart(nums, 0, k-1) ; 
reversepart(nums, k , n -1) ; 

    }

//     void rotoateByOne(vector<int> & nums) {
//         int n = nums.size() ; 

 

// vector<int> temp ; 

//          for (int i = 1; i <  n; i ++) {
        
//          }
//     }
int main()
{
    vector<int> nums = {1,2,3,4,5,6, 7} ; 
    int k = 3; 

  rotate(nums, k ) ; 

for (int  i = 0 ; i < nums.size() ; i ++){
    cout << nums[i] ; 
}
cout << endl; 



    return 0;
}
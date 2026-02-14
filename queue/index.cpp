#include <iostream> 
#include <vector> 
using namespace std; 
// sliding window maximum 
/// brute 
// 
vector<int> maxSlidingWindow(vector<int>& nums, int k) { 
    vector<int> result; 

for (int i = 0 ; i < nums.size( ) ; i++) { 
    int maxval  = nums[i] ;
    for (int j = i ; j < i+k ; j++){
        maxval = max(maxval , nums[j]); 
    }
    result.push_back(maxval) ; 
}
return result ; 
}
// optimal 

// we're using the double ended queue deque -> its a queue data struture with we can pop and push front both end and front we also peek form both side 
// viable ans => possible ans 
// curr -> window length not old element always curr element we;re going to store 
// 

int main () { 

    vector<int> n = {1, 3, -1,  -3,5, 3, 5 , 6, 7} ; 

    int target = 3; 

    vector<int> ans  = maxSlidingWindow(n, target) ;
    for (auto i : ans){ 
        cout << i << " "; 
    }
    cout << endl; 


}
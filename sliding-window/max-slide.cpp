#include <iostream>
#include <deque>
#include <vector>
using namespace std;
vector<int> MaxSlidingWindow(vector<int> &nums , int k){ 

    deque<int> dq; 
    vector<int> ans; 

    for (int i = 0; i <k ; i++) { 
       while(!dq.empty() &&  nums[dq.back()]  <= nums[i]) {
        dq.pop_back() ; 
       } 
       dq.push_back(i); 
    }

    for (int i = k; i < nums.size() ; i ++){ 
        ans.push_back(nums[dq.front()]); 

        // remove element which is not a part of curr window 
        while (!dq.empty() && dq.front() <= i -k){ 
           dq.pop_front();
        }


        while(!dq.empty() &&  nums[dq.back()]  <= nums[i]) {
        dq.pop_back() ; 
       } 
       dq.push_back(i); 

        
    }
    ans.push_back(nums[dq.front()]); 
    return ans; 


}
int main() {
   vector<int> a = {1, -1}; 
   int k = 1; 
   
   vector<int> res = MaxSlidingWindow(a, k); 
   for ( const auto i : res){ 
    cout << i << " "; 
   }
cout << endl; 
    return 0;
}
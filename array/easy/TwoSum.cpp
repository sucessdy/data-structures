#include <iostream>
#include <vector>
using namespace std;


    vector<int> twoSum(vector<int>& nums, int target) {
    vector <pair<int,int> >arr ; 
    for(int i = 0; i < nums.size( )  ; ++i){ 
        arr.push_back({nums[i], i}) ;
    }   
    sort(arr.begin() , arr.end()) ; 
 
int st = 0; 
int end = arr.size() -1; 
 while (st < end){
    int sum = arr[st].first + arr[end].first; 

    if (sum == target){ 
        return {arr[st].second, arr[end].second};  
    }
    else if (sum < target){ 
        st++;
    }
    else {
        end--; 

    }
   
 }      
  return {-1, -1} ;

};

int main() {
    vector<int> arr= {3,2, 4} ;
    int target = 6; 
    vector<int> ans = twoSum(arr, target) ; 
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl; 
    return 0;
}
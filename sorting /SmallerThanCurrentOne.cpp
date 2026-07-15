#include <iostream>
#include <vector>
using namespace std;
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
       vector<int> sorted = nums; 
       sort(sorted.begin(), sorted.end()) ; 
       vector<int> ans ; 
       for (auto i : nums) { 
        ans.push_back(lower_bound(sorted.begin(), sorted.end(), i )- sorted.begin() );
       } 
       return ans;  
    }

int main() {
    vector<int> arr = {8,1,2,2,3} ;
vector<int> ans = smallerNumbersThanCurrent(arr) ; 
for ( auto i : ans) { 
    cout << i << " ";
}
cout << endl;
    return 0;
}
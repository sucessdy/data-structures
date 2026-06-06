#include <iostream>
#include <vector>
using namespace std;
int LinearSearch (vector<int> &arr , int target , int st, int end)  {
for ( int i = st; i <= end ; i ++) {
    if(arr[i] ==target ) { 
        return arr[i] ; 
    }
}
return 0 ; 
}
int main() {
    vector<int> arr  = {1, 0,2 , 3, 4, 5} ; 
  cout <<  LinearSearch(arr, 3 , 1, 4) << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
// ceiling 
int binarySearch (vector<int> & arr , int target ) { 
int st = 0; 
int end = arr.size() ;
while (st <= end) { 
    int mid = st + (end - st ) / 2 ; 
if (arr[mid] == target){ 
    return mid;
}
else if ( arr[mid] < target)  {
    st = mid +1;
    
}
else {
    end = mid -1 ; 
}
}
 return end  ; 
}
int main() {
    vector<int> n= {1, 4, 5, 6,9, 12, 18, 29} ; 
    int target = 17;
    cout <<  "index : "<< binarySearch(n, target) << endl ; 

    return 0;
}
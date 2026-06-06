#include <iostream>
#include <vector>
using namespace std;
// https://www.geeksforgeeks.org/dsa/find-position-element-sorted-array-infinite-numbers/

int ans(vector<int> & arr, int target) {
    int start = 0;
    int end = 1;

    while ( target  > arr[end]) { 
        int newStart = end + 1 ; 
        // end next element became the start cuz  

    end = end + ( end - start + 1)  * 2;
        // previous end + size of the box * 2 
         start = newStart ; 

    }
    return binarySearch(arr, target , start  , end) ; 
}

int binarySearch (vector<int> & arr , int target, int st, int end ) { 

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
 return -1  ; 
}
int main() {
    vector<int>arr = {1, 2, 3, 4, 5, 6 , 7, 8, 9 , 10 ,11, 12 , 13, 14,15, 16} ;
    int target = 15; 
    cout << binarySearch(arr, target) << endl; 

    return 0;
}
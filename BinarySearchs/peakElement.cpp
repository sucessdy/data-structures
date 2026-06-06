#include <iostream>
#include <vector>
using namespace std;


int PeakMountainArray(vector<int> & arr) { 
int st = 0; 
int end = arr.size() -1;
while ( st < end) { 
    int mid = st + (end - st) /2 ;
    if( arr[mid] > arr[mid +1]){
        end=mid;
        // left hand side /
    }
    else { 
        st = mid + 1; 

        //  right hand side 
        // i know here my answer is laying...
    }

}
return st; 
}
int main() {
    vector<int> arr = {1, 2, 3,4, 2, 1}; 
    cout << PeakMountainArray(arr) << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// int Mountain(vector<int> &arr)
// {
//     int st = 0;
//     int end = 1;
//     while (st < end)
//     {
//         int mid = st + (end - st) / 2;

//         if (arr[mid] > arr[mid + 1])
//         {
//             end = mid;
//         }
//         else
//         {
//             st = mid + 1;
//         }
//     }
//     return binarySearch(arr, tar st,end) ;
// }


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


int PeakElement (vector<int> & arr) { 
int st = 0; 
int end = arr.size() -1; 

while (st <end) {
    int mid = st + (end - st) / 2; 
    if (arr[mid] > arr[mid +1 ] ) { 
        end = mid; 
    } 
    else {
        st = mid +1 ;
    }

}
return binarySearch(arr, target, st, end );
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 3, 1};
    int tar = 3;

    cout << BinarySearch(arr, tar) << endl;
    return 0;
}
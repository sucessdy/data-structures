#include <iostream>
#include <vector>
using namespace std;
// find the set bit 
     
int main() {

// vector<int> nums={3,0,1} 
 ; 
 
//  cout << missingNumber(nums) << endl; 
    // algo
    // while number not zero
    // check last bit
    // count if it is 1
    // remove the last bit

    int n = 9; 
    // int b = 1001; 
    int cnt = 0; 
//     while( n > 0){
//         if ( (n & 1 )== 1){
// cnt++;
//         }
//    n = n >> 1; 
    // }

while(n > 0){
cnt++; 
n -= (n & -n) ; 
}

    cout << cnt << endl; 
    return 0;
}
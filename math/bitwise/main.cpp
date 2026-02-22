// find the position of the right most set bit 
#include <iostream>
#include <vector> 

using namespace std; 

int singleNumberThrice(vector<int> &num) { 

int res = 0; 
vector<int> bit(32) ; 



for (int  n : num){ 
    for (int i = 0; i < 32 ; i++){ 
        if (n & ( 1<< i)) {
            bit[i]++ ; 
        }
    }
    
}

for (int i = 0 ; i< 32 ; i ++ ) { 
   if (bit[i] % 3 == 1){

    res|= (1<< i);
   } 
}

return res ; 

}


int countSetBit(int n ){
    int cnt = 0 ; 
    while (n > 0){ 
        cnt+= (n& 1); 
        n = n >> 1 ;

    }
    return cnt; 
}

int main (){ 


    vector<int> n = {1, 2, 3, 2, 3, 2, 3} ; 
    cout << singleNumberThrice(n)<< endl; 

    // int n= 13; 
    // cout << countSetBit(n) << endl; 
//     unsigned int num = 25; 

//     unsigned int mask = (1 << 0) |  (1 << 2 ) | (1 << 3) ; 
// num ^=mask; 
// cout << num << endl; 
return 0; 
}


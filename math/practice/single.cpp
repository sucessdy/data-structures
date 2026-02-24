#include <iostream> 
#include <vector> 
using namespace std; 
// single number 11 

int singleNumber(vector<int> &num){
    vector<int> bit(32) ; 
    for (int n : num){ 
        for (int i = 0; i < 32 ; i++){

            if(n & ( 1 << i)){
                 bit[i]++; 
            }

        }
    }
int ans =0 ; 

        for (int i = 0; i < 32 ; i ++){ 
            if (bit[i] % 3 == 1){ 
                ans |= (1 << i); 

            }
        }
    

    return ans; 

}

int main()
{ 

    vector<int> arr = {1, -2, 3, 1, -2, 1, -2}; 
    cout << singleNumber(arr) << endl; 

    return 0; 

}
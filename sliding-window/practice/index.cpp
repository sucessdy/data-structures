#include <iostream>
#include <vector>

using namespace std ; 

int Constant(vector<int> &arr , int k) { 
int maxSum = 0; 
int n = arr.size() ; 
for (int i = 0; i < k ; i ++){
    maxSum +=arr[i] ; 
}
int window = maxSum; 

for (int i = k; i < n; i++ ){
    window +=arr[i] ;
    window-=arr[i -k ]; 
    maxSum =max(maxSum, window) ; 

}
return maxSum; 
}


int main() { 
    vector<int> arr = {5, 2, -1, 0, 3};
    int k = 3;

    cout << Constant(arr, k) << endl; 

    return 0 
    ; 
}
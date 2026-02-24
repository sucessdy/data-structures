#include <iostream> 
#include <vector> 
using namespace std ; 

int windowSum(vector<int> & arr, int k) { 
int maxSum = 0; 

for (int i = 0; i <=k  ; i ++) { 
   maxSum += arr[i] ;  
}
int window = maxSum ; 

for (int i = k; i < arr.size() - k ; i++){ 
    window+= arr[i]; 
     window -= arr[i - k] ; 

     maxSum = max(window, maxSum ); 
}
return maxSum ; 
}

int factorial(int n){ 
    if (n == 0) { 
        return 1 ;
    }
   
return n * factorial(n -1) ;
}
int main () { 
    int n = 4;
    cout << factorial (n) << endl; 
vector<int> a = {2, 1, 5, 1, 3, 2} ; 
int k = 3; 

cout << windowSum (a, k) << endl; 
return 0; 

}
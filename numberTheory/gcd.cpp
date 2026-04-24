#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int gcd(int n1, int n2 ) { 
for ( int i = min(n1, n2) ; i >=0 ; --i){ 
    if ( n1 % i == 0 && n2 % i == 0){ 
return i; 

    }
} 
return -1; 
}

int main() {
    int n1 =11; 
    int n2 =  43;
  cout <<   gcd(n1, n2) << endl ; 


    return 0;
}
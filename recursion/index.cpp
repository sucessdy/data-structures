#include <iostream>
using namespace std ; 


void printDescending(int n ) { 
if (n == 0 ) return ; 

cout << n << endl; 
printDescending(n - 1) ; 


}
int main() { 
int n = 6;

printDescending(n) ; 
return  0 ; 
}
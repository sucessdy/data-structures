#include <iostream>
#include <vector>
using namespace std;

int addDigits(int n) {
        int num = 0; 
        // if (n == 0) return 0; 
        while (n != 0) {
  
            num +=  n % 10; 
            n/=10 ;
        }
        return ( num < 9 ) ? n : 0 ; 
    }
int main() {
    
    int n = 38;
    cout << addDigits(n) << endl; 
    return 0;
}
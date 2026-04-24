//   
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int n = 393; 
    while(n != 0) { 
      int dig = n% 10 ;   ///extracting the digits 
        n /= 10  //   making the number smaller 
    }
    return 0;
}
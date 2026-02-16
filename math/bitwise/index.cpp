#include <iostream>
#include <cmath> 
using namespace std; 
bool odd(int num){
    return (num & 1 ) == 1; 

 }

 int appearOnce(int num){

 }
int main() { 
    // decimal to binary 
    int n = 13; 
    string bin = ""; 

    while (n > 0){ 
bin = to_string(n % 2) + bin ;
n/= 2; 

    }
    cout << bin  << endl ;  

    // binary to decimal 

string binary = "10101"; 
int result = 0;
int power = 0; 
for (int i = binary.length() -1 ; i >= 0 ; i--){ 
    result += (binary[i] - '0')  * pow(2, power); 
power ++; 
}
cout << result << endl; 



int num = 23 ; 
// if (num & 1){
//     cout << "ODD" ;
// }
// else { 
//     cout << "EVEN " ; 
// }
cout << odd(num) << endl;


    return 0; 
}

#include <iostream>
#include <string>
using namespace std ; 



string addBinary(string a, string b) {
      string ans= "" ; 
int  i = a.length() -1; 
int j = b.length() -1; 
int carry = 0; 

while( i >= 0 || j >= 0 || carry){ 
int sum = carry ;
 if (i >= 0) sum += a[i--] - '0' ; 
 if (j >= 0) sum += b[j--] - '0' ; 
 // conversion to int to char 

 ans += (sum %2) + '0' ;
carry = sum/2 ; 


}
reverse(ans.begin(), ans.end()) ;
return ans; 


    
      
    }

int decimalToBinary(int dec ){
     int ans = 0; 
     int pow = 1; 
     while (dec > 0){ 
        int remainder = dec%2; 
        dec = dec/2; 
        ans += remainder*pow; 
        pow = pow * 10; 
     }
     return ans; 
}

int main( ) { 
string a = "1010";
    string b = "1011";
    cout << addBinary(a, b);
// int e = 1; 
// cout << decimalToBinary(r) << endl; 
return 0; 
}
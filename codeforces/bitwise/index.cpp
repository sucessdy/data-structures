#include <iostream>
#include <vector>
using namespace std;
string to_binary(int x) { 
    string s ;

    while ( x > 0) { 
        s+= (x % 2 )? "1" : "0"  ; 
        x/= 2 ; 
    }
    reverse(s.begin(), s.end()) ;

    return s ; 
}


int main() {
    int x = 14; 
cout << to_binary(x) << endl;
int y = 52; 
int z = 35 ; 

cout << "y: "  << to_binary(y)  << " z: " << to_binary(z) << endl; 
cout << "AND , Or , XOR "  << endl; 

cout <<  "AND: " << to_binary(y&z) << " OR:  " << to_binary(y | z) << " XOR: " <<to_binary(y ^ z) << endl; 

int a  = 13 ; 
for (int  i=0; i < 30 ; i ++){ 
    if ((a & (1 << i) ) != 0 ) {
        cout << i << " "; }
}

    return 0;
}
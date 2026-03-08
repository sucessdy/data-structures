#include <iostream>
#include <string>
using namespace std;

int main() {
    // 282A  
    // A. Bit++  
 ios::sync_with_stdio(false);
    cin.tie(NULL); 


    int n ; 
    cin >>  n ; 
    int x = 0; 
        string s; 
    while ( n--){ 
        

    cin >> s; 
    if (s[1] == '+'){ 
        x++;
    }
    else {
        x-- ; 
    }

    }
    cout << x << endl; 

    return 0;
}
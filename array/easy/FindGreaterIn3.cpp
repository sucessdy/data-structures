#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a =10, b= 45, c=90; 
    if (a >= b && a >= c){
        cout << a ;
    }
    else if (b>= a && b>= c){
        cout << b; 
    }
    else {
        cout << c ;
    }
    cout << endl;
    return 0;
}
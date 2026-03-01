#include <iostream>
#include <vector>
#include <string> 

using namespace std;

int main() {
    
    string  s = "banaa"; 
int cnt=0; 
    for (int i = 0; i < s.length() ; i++){
         if (s[i] == 'a'){
cnt++; 
         }
    }
    cout << cnt << "cnt " <<endl; 
    return 0;
}
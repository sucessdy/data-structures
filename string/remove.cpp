#include <iostream> 
#include <string> 
using namespace std ; 

//
//  s = daadacbcabc 
// part = abc 
 // str.find(part) <str.length; => we're finding the first element in the string which matches if not then if not then we can check the if ts in the str.length 
 // s.earse(st, end) =use for removing the part element form the string 

string RemoveAllOccurence (string s , string part) { 
while (s.length() > 0 && s.find(part) < s.length()){ 
s.erase(s.find(part) , part.length()) ; 

}

return s; 

}


int main() {
    string s = "addabcabcabc"  ;
string part = "abc" ; 
cout << RemoveAllOccurence(s, part) << endl; 

    return 0;
}
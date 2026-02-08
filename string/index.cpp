
// Given a string, check whether it is a palindrome.
// Rules:  
// Ignore case : 
// Ignore non-alphanumeric characters i'm not going to ingnore this 
// Example:
// Pattern: we can run a backward loop or revese the loop witht the build in fucntion i chose the build for simplist .. 
// Why:  I don't need to loop for reverse the string butfor alphnuberica i need to check and also i faced the problem how to filter the alpanumeic i was not able to where to fit the alpnumeirc fucntion so i create.a sepate fucntion 
// Edge Cases: "i think i handle this welll ", it can be a single value or i didnt check the lowecase 


#include <iostream>
#include <string>
using namespace std;

bool Alphnumeric (char ch){
return ((ch >='0' && ch <='9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) ; 
}

string FilterString(string s) {
    string filtered = "";
    for (char ch : s) {
        if (Alphnumeric(ch)) {
            filtered += tolower(ch);
        }
    }
    return filtered;
}

bool Palindrome(string s) { 

}

// bool Palindrome(string &s)
// {
//     // int reverse= 0;
//     // int str = s.length()-1 ;

//     // for (int i = str ; i >= 0; i--  ){

//     //     reverse+=i;

//     // }

//     // string str = s;
//     // reverse(str.begin(), str.end());
//     // return s == str  ;  
// }

int main()
{

    string s = "A man, a plan, a canal: Panama" ; 
    string filtered = FilterString(s);
    bool palindromeCheck = Palindrome(filtered);

    if (palindromeCheck)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
#include <iostream>
#include <string> 
using namespace std ; 
//palindrome is valid 
bool alphanumeric (char ch) {
    if ((ch >= '0' && ch <= '9' ) || (ch >= 'a' && ch <= 'z' ) || (ch  >= 'A' && ch <= 'Z')) {
        return true ;
    }
    return false; 

 }
    bool Palindrome(string s)
{
    int st = 0;
    int end = s.size() - 1;

    while (st < end)
    {
        if (!alphanumeric(s[st]))
        {
            st++;
            continue;
        }
        if (!alphanumeric(s[end]))
        {
            end--;
            continue;
        }
        if (tolower(s[st]) != tolower(s[end]))
        {
return false ; 
        }
        st++ ; 
        end--; 

    }

    return true ;
}

int main()
{

    string s = "racec%ar"; 
bool res = Palindrome(s) ; 
cout << (res ? "Palindrome " : "not a Palindrome") << endl; 

    return 0;
}
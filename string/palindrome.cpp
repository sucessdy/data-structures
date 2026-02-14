#include <iostream>

#include <string>

using namespace std;

// palindrome
bool Alphnumeric(char ch)
{
    if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        return true;
    }
    return false;
}
bool Palindrome(string s)
{

    int st = 0;
    int end = s.length() - 1;

    while (st < end)
    {
        if (!Alphnumeric(s[st]))
        {
            st++;
            continue;
        }
        if (!Alphnumeric(s[end]))
        {
            end--;
            continue;
        }

        if (tolower(s[st]) != tolower(s[end]))
        {
            return false;
        }

        st++;
        end--;
    }
    return true;
}

int main()
{
    string s = "mada*m";
    bool res = Palindrome(s);
    // cout << (res : true ? false ) << endl;
    if (!res)
    {
        cout << "not a plaindrome" << "\n";
    }
    else
    {
        cout << "palindrome" << "\n";
    }

    return 0;
}

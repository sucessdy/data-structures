#include <iostream>
#include <vector>
using namespace std;

bool checkString(string s)
{
    bool seenB = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a' && seenB)
        {
            return false;
        }
        else if (s[i] == 'b')
        {
            seenB = true;
        }
    }

    return true;
}

int main()
{

    string s = "bb";
    bool res = checkString(s);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
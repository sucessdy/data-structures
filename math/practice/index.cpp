#include <iostream>
using namespace std;


// 67. Add Binary
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given two binary strings a and b, return their sum as a binary string.

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"
string addBinary(string a, string b)
{
   
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string ans;
ans.reserve(max(a.size(), b.size()) + 1);

if (a[i] != '0' && a[i] != '1') return "not valid"; 
if (b[j] != '0' && b[j] != '1') return "not valid" ; 
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';

        ans.push_back((sum % 2) + '0');

        carry = sum / 2;
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string a = "11";
    string b = "1";
    cout << addBinary(a, b) << endl;
    return 0;
}
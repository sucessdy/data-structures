// QUESTION: Binary Flip Distance

// You are given two binary strings a and b of equal length.

// In one operation, you can flip exactly one bit in string a
// (0 → 1 or 1 → 0).

// 👉 Task

// Return the minimum number of operations required to make string a equal to string b.

// ✍️ Example 1
// a = "10101"
// b = "00111"

// Comparison:

// 1 vs 0 ❌
// 0 vs 0 ✅
// 1 vs 1 ✅
// 0 vs 1 ❌
// 1 vs 1 ✅

// Output:

// 2

// ✍️ Constraints

// 1 <= length <= 10^5

// Strings contain only '0' and '1'

// Length of a == length of b

// 🧠 Hints (don’t skip, but don’t overthink)

// You don’t need carry

// You don’t need conversion

// Think: “When do I actually need an operation?”

// 🎯 What I’m testing here

// String traversal

// Char vs char comparison

// Clean O(n) logic

// No unnecessary conversions

#include <iostream>
#include <string>
using namespace std;

int FlipNumber(string a, string b)

{
    int i = a.size() - 1;
    int j = b.size() - 1;
    int ans = INT_MAX;

    int cnt = 0;

    while (i >= 0 || j >= 0)
    {
        if (a[i] != b[j])
        {
            //  if ( i >= 0)  sum += a[i] -'0';
            ans += char(a[i--] - b[j--] - '0');

            cnt++;
        }

    }
    return cnt;
}
int main()
{
    string a = "10101";
    string b = "00111";
    cout << FlipNumber(a, b) << endl;

    return 0;
}
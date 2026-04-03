#include <iostream>
#include <vector>
using namespace std;

// 🔍 Meaning of T and F

// For every index i: 

// ✅ If str1[i] == 'T' 

// Then:

// word[i ... i+m-1] MUST == str2
// ❌ If str1[i] == 'F'

// Then:

// word[i ... i+m-1] MUST NOT == str2

// 😈 Next Level Challenge (slightly harder)

// Let’s go one step deeper:

// str1 = "TFTT"
// str2 = "ab"

// 👉 Try mentally:

// Build the word using T
// Check overlaps
// THEN handle F
/*

str1 = n.length = 4
str2 = m.length = 2
word = n+m -1
4 + 2 - 1 = 5

 _ _ _  _ _  =  word
index 0 (T):
str 1  (T) == str2
word = a b _ _ _

index 1 (F)
b != ab
already ok .. no change
same ..

index 2 (T)
we place a b at index 2
a b a b _

index 3 (T)
here its interesting part where the overlap happend

b is place at index 3 .. new one is a
_ needs to be b at index   3 but cuz a is not at the index of 3 so return " "

immedityl.. i think.. cuz we not satisfiy the index 3 condition ...


function generateString(str1, str2):

    n = length(str1)
    m = length(str2)

    word = array of size (n + m - 1) filled with '?'

    --------------------------------------------------
    STEP 1: Handle all 'T'
    --------------------------------------------------

    for i from 0 to n-1:
        if str1[i] == 'T':
            for j from 0 to m-1:

                if word[i + j] == '?':
                    word[i + j] = str2[j]

                else if word[i + j] != str2[j]:
                    return ""   // conflict → impossible

    --------------------------------------------------
    STEP 2: Handle all 'F'
    --------------------------------------------------

    for i from 0 to n-1:
        if str1[i] == 'F':

            isEqual = true

            for j from 0 to m-1:
                if word[i + j] != str2[j]:
                    isEqual = false
                    break

            if isEqual == true:

                // try to break it
                canBreak = false

                for j from 0 to m-1:

                    pos = i + j

                    // try changing only if it's not forced
                    original = word[pos]

                    for ch from 'a' to 'z':
                        if ch != str2[j]:

                            word[pos] = ch

                            // check if this breaks equality
                            isStillEqual = true
                            for k from 0 to m-1:
                                if word[i + k] != str2[k]:
                                    isStillEqual = false
                                    break

                            if isStillEqual == false:
                                canBreak = true
                                break

                    if canBreak:
                        break

                    word[pos] = original   // revert

                if canBreak == false:
                    return ""   // cannot break F

    --------------------------------------------------
    STEP 3: Fill remaining '?'
    --------------------------------------------------

    for i from 0 to word.length-1:
        if word[i] == '?':
            word[i] = 'a'

    return string(word)






*/

string generateString(string str1, string str2)
{

    int n = str1.length();
    int m = str2.length();
    // int word = n + m - 1;
    vector<char> word(n + m - 1, '?');
    vector<bool> locked(n + m - 1, false);
    // we handle the all t first
    for (int i = 0; i < n; ++i)
    {
        if (str1[i] == 'T')
        {
            for (int j = 0; j < m; ++j)
            {
                if (word[i + j] == '?')
                {
                    word[i + j] = str2[j];
                    locked[i + j] = true;
                }
                else if (word[i + j] != str2[j])
                {
                    return "";
                }
                else
                {
                    locked[i + j] = true; // already matches, still locked
                }
            }
        }
    }
  for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == '?')
        {
            word[i] = 'a';
        }
    } 
    // handle all  f

    for (int i = 0; i < n; ++i)
    {
        if (str1[i] == 'F')
        {
           bool isEqual = true;

for (int j = 0; j < m; ++j)
{
    if (word[i + j] != '?' && word[i + j] != str2[j])
    {
        isEqual = false;
        break;
    }
} 
            if (isEqual)
{
    bool changed = false;

    for (int j = m - 1; j >= 0; --j)
    {
        int pos = i + j;

        if (!locked[pos])
        {
            char original = word[pos];

            word[pos] = (str2[j] == 'a') ? 'b' : 'a';

            // verify it's now different
            bool stillEqual = true;
            for (int k = 0; k < m; ++k)
            {
                if (word[i + k] != str2[k])
                {
                    stillEqual = false;
                    break;
                }
            }

            if (!stillEqual)
            {
                changed = true;
                break;
            }

            word[pos] = original; // revert
        }
    }

    if (!changed) return "";
} 
        }
    }

  
    return string(word.begin(), word.end());
}

int main()
{
    string str1 = "TFTF";
    string str2 = "ab";

    cout << generateString(str1, str2) << endl;

    return 0;
}
// Count vowels in a string

#include <iostream>

#include <string>

using namespace std;

// we can just use a loop for iterate the string .and check if the particular char is present in our sting... we also chekc the lowecase and upppercase if u want i can write for that also... 
int main()
{
    string s = "education";
    int countVowel = 0; 
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){ 
countVowel++; 
        }
    }
    cout << "vowel: " << countVowel << endl; 

        return 0;
}
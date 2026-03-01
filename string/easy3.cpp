#include <iostream>

#include <string>
#include <cctype>
using namespace std;

// void alphanumeric(char ch ) {

// }

// here i used the inbuilt function for alphanumeric.. i don't want to write.... i can write so...for the explaination i used the bool function to return true and false .... and i use the two pointer apprach for the best optimal soultion ... and i use the while i check until my st pointer meet the end pointe... then remove overlap i exit form the loop.. not equal canbe..not a probelm i htink... cuz we can check the odd string like madam d is middle wjere st and end point to the same.. we can check ... its not a issue...  but here.. we don't need.. its anutomaly calaute so..not going .. with eaual ..to.o... if u want u can answer 
// ok .. so  check the st pointer and end pointer form end.. and increment st and deceremnt teh end.. and i use continue... for our code to check the below code..also..then conver to  lowecase for consitence if my st != end we return false and inside the loop st +++ and end--;; pointer..for tranversal and ten outside the loop return true.. ok.. any issue in my code feel free to correct them 

bool Palindrome(const string &s)
{
    int st = 0;
    int end = s.length() -1;
    while (st < end)
    {
        if (!isalnum(s[st]))
        {
            st++;
            continue;
        }
 if (!isalnum(s[end]))
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
    string s = "hell";
    bool res = Palindrome(s);
    cout << (res ? "true" : "false") << endl;

    return 0;
}
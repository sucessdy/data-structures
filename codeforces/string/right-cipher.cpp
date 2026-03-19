//  right Left Cipher 
#include <iostream>
#include <vector>
#include <string> 

using namespace std;

int main() {
    string t;
    cin >> t;

    int n = t.size();
    string s = "";

    int mid;

    if(n % 2 == 0)
        mid = (n - 1) / 2;
    else
        mid = n / 2;

    s += t[mid];

    int left = mid - 1;
    int right = mid + 1;

    bool goRight = true;

    while(left >= 0 || right < n){
        if(goRight && right < n){
            s += t[right++];
        }
        else if(left >= 0){
            s += t[left--];
        }
        goRight = !goRight;
    }

    cout << s;
}
// find the position of the right most set bit
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// int singleNumberThrice(vector<int> &num) {

// int res = 0;
// vector<int> bit(32) ;

// for (int  n : num){
//     for (int i = 0; i < 32 ; i++){
//         if (n & ( 1<< i)) {
//             bit[i]++ ;
//         }
//     }

// }

// for (int i = 0 ; i< 32 ; i ++ ) {
//    if (bit[i] % 3 == 1){

//     res|= (1<< i);
//    }
// }

// return res ;

// }

// int countSetBit(int n ){
//     int cnt = 0 ;
//     while (n > 0){
//         cnt+= (n& 1);
//         n = n >> 1 ;

//     }
//     return cnt;
// }

int magicNumber(int n)
{
    int ans = 0;
    int power = 1;

    while (n > 0)
    {

        power = power * 5;

        if (n & 1)
        { // last bt

            ans += power;
        }
        // right shift

        n = n >> 1;

        /* code */
    }

    return ans;
}


bool  PowerOf2(int n ){ 
    return( n > 0) && (n & (n - 1)) == 1; 
 

}
vector<int> convertToBase(int n, int b)
{
    vector<int> ans;

    while (n > 0)
    {
        ans.push_back(n % b);
        n /= b;
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    int n = 10;
    int b = 2;
    // cout << con(n) << endl;

    vector<int> ans = convertToBase(n, b);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    int x = 8;
    int y  = 2;
    int res = (int)(log(x) / log(y)) + 1 ; 
    cout << res << endl; 

    int a  = 27 ; 
    bool power = PowerOf2(a); 

    cout << (power  ? "true" : "false") << endl; 

        // vector<int> n = {1, 2, 3, 2, 3, 2, 3} ;
        // cout << singleNumberThrice(n)<< endl;

        // int n= 13;
        // cout << countSetBit(n) << endl;
        //     unsigned int num = 25;

        //     unsigned int mask = (1 << 0) |  (1 << 2 ) | (1 << 3) ;
        // num ^=mask;
        // cout << num << endl;
        return 0;
}

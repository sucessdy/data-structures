#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
// bool odd(int num)
// {
//     return (num & 1) ==1 ;
// }

int appearOnce(vector<int> num)
{

    int ans = 0;

    for (int i = 0; i < num.size(); ++i)
    {
        ans ^= num[i];
    }
    return ans;
}

int appearOncewithBruteForce(vector<int> &num)
{

    sort(num.begin(), num.end());

    int ans = 0;

    for (int i = 0; i < num.size(); ++i)
    {
        if (num[i] != num[i - 1] && num[i] != num[i + 1])
        {
            ans = num[i];
            return ans;
        }

        if (num[i - 1] != num[i - 2])
        {
            return num[i - 1];
        }
    }
    return 0;
}
int appearOnceBetter ( vector<int> &num ) {
    unordered_map<int, int> m; 
for ( int i = 0 ; i < num.size() ; i ++ ){
     m[num[i]]++ ; 


}
for ( auto it = m.begin() ; it != m.end() ; it++){
    if (it->second == 1){
        return it->first ; 
    }
}
return -1;
}

bool PowerofTwo(int n ){
    return n > 0 && (n & (n -1) ) == 0 ; 

 }


int main()
{
    int n = 1; 
   
bool check = PowerofTwo(n); 
if (check){ 
    cout << "True" << "\n"; 

}
else { 
    cout << "false"  << "\n"; 
}
    vector<int> a = {1, 1, 3, 3, 4 , 66};
    // cout << appearOncewithBruteForce(a) << endl;
    // cout << appearOnceBetter(a) << endl; 
    // decimal to binary
    //     int n = 13;
    //     string bin = "";

    //     while (n > 0){
    // bin = to_string(n % 2) + bin ;
    // n/= 2;

    //     }
    //     cout << bin  << endl ;

    //     // binary to decimal

    // string binary = "10101";
    // int result = 0;
    // int power = 0;
    // for (int i = binary.length() -1 ; i >= 0 ; i--){
    //     result += (binary[i] - '0')  * pow(2, power);
    // power ++;
    // }
    // cout << result << endl;

    // int num = 23 ;
    // if (num >> 1){
    //     cout << "ODD" ;
    // }
    // else {
    //     cout << "EVEN " ;
    // }
    // cout << odd(num) << endl;

    return 0;
}

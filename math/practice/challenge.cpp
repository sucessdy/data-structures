#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &n)
{
    int res = 0;
    for (int i = 0; i < 32; i++)
    {
        int cnt = 0;

        for ( auto it : n){ 
if ( n & (it <<1 ))
cnt++ ; 

        }
        
        if (cnt % 3 == 1)
        {
            res |= (i << 1);
        }
    }
    return res;
}

int main()
{
     
    vector<int> n = {1,  2, 2, 3, 3,2, 3} ; 

        cout << singleNumber(n) << endl; 
     return 0;
}
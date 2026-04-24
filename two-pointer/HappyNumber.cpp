#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int SquareofSum(int n)
{
    int num = 0;
    while (n != 0)
    {
        int dig = n % 10;
        num += dig * dig;
        n /= 10;
    }
    return num;
}
bool isHappy(int n)
{

    unordered_set<int> set;

    while (1)
    {

        n = SquareofSum(n) ; 
        if (n == 1)
        {
            return true;
        }

        if (set.find(n) != set.end())
        {
            return false;
        }
        set.insert(n);
    }
}

int main()
{
int n =19; 
;
    bool res = isHappy(n);

    cout << (res ? "true" : "false") << endl;
    return 0;
}
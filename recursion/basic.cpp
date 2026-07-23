#include <iostream>
#include <vector>
using namespace std;
void print(int n)
{
    if (n > 10) return; 
     cout << n << " ";
   print(n + 1);
}

int main()
{
    int n = 5;
 print(n) ;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// 28. Maximum Product of  two digits 
int maxProduct(int n)
{
    int maxPro = 0;
    int right = 0;
    int left = 0;
    int prod = 0;
    while (n != 0)
    {
        int dig = n % 10;
        // curr = dig * dig;
       
           
        // left = (left == 0 ? 1 : left ) * dig;
        // right = (right == 0 ? 1 : right)  * dig ;

        if (dig >  left)
        {
          right = left;
            left = dig ; 
        }
        else if (dig > right) 
        {
            right = dig;
        }

        n /= 10;
    }
    return left * right;
}

int maxProductSum(int n)
{
    int maxPro = 0;
    int maxP = 0;
    int minPro = 0;
    for (int i = 0; i < n; i++)
    { 
        if (n < 0)
        {
            int temp = minPro;
            minPro = maxPro;
            maxPro = temp;
        }
        maxPro = max(n, maxPro);
        minPro = min(n, minPro);
        maxP = max(minPro, maxPro);
    }
    return maxP;
}

int maxProduct(vector<int> &nums)
{
    int product = nums[0];
    int n = nums.size();
    int left = 0;
    int right = 0;

    for (int i = 0; i < n; i++)
    {
        left = (left == 0 ? 1 : left) * nums[i];
        right = (right == 0 ? 1 : right) * nums[n - i - 1];
        product = max(max(left, right), product);
        cout << right;
    }
    return product;
}

class Solution {
public:
    int maxProduct(int n) {
        int maxPro = 0;
        int curr = 0;
        int left = 0;
        int right = 0 ; 

        while (  n!=0 ){
            int dig = n%10; 
               if (dig  == 0) return 0; 
            left = (left == 0 ? 1 : left) * dig;
            right = (right == 0 ? 1 : right) * dig ; 
            curr = max(left, right) ; 
            maxPro = max(curr, maxPro) ; 
            n/=10;
        } 
        return maxPro;
    }
};

int main()
{
    int n = 269;
    cout << maxProduct(n) << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void MoveLeftPositiveandRightNegative(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;
    while (l < r)
    {
        if (nums[l] >= 0)
        {
            l++;
        }
        else if (nums[r])
        {
            r--;
        }
        else
        {
            swap(nums[l], nums[r]);
        }
    }

}
int main()
{
//     vector<int> a = { 1, -2, 4, 0 , -2 , 2}
// MoveLeftPositiveandRightNegative(a); 
// for ( int i = 0; i < a.size()  ; i++){ 
//     cout << a ;

// }
// cout << " "; 

    return 0;
}
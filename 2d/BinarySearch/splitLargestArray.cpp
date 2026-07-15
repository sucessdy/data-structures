#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int splitArray(vector<int> &nums, int m)
{
    int st = 0;
    int end = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        st = max(st, nums[i]);
        end += nums[i]; /// in the end of loop this will containn the max items for the array
    }
    while (st < end)
    {
        // try for the middle as potential ans
        int mid = st + (end - st) / 2;

        // calcute the max pirces you can divide this  with  max sum
        int sum = 0;
        int pices = 1;

        for (int num : nums)
        {
            if (sum + num >  mid)
            {
                // you can't add in this subarray u can add  , new one
                sum = num;
                pices++;
            }
            else
            {
                sum += num;
            }
        }
        if (pices > m)
        {
            st = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return end;
}
int main()
{

    vector<int> ans = {1,2,3,4,5};
    int m = 2;
    cout << splitArray(ans, m) << endl;

    return 0;
}
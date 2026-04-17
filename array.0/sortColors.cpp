#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << endl;
    }
}

void SortColorswithPointer(vector<int> &nums)
{
    int cnt = 0;
    int cnt2 = 0;
    int cnt3 = 0;

    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] == 0)
        {
            cnt++;
        }
        else if (nums[i] == 1)
        {
            cnt2++;
        }
        else
            cnt3++;
    }
    int index = 0;

    for (int i = 0; i < cnt; ++i)
    {
        nums[index++] = 0;
    }
    // cnt++;
    for (int i = 0; i < cnt2; ++i)
    {
        nums[index++] = 1;
    }
    // cnt2++;
    for (int i = 0; i < cnt3; ++i)
    {
        nums[index++] = 2;
    };
    // cnt3++;
}

void SortNumber(vector<int> &nums)
{
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == 0)
        {
            cnt0++;
        }
        else if (nums[i] == 1)
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
    }
    int index = 0;
    for (int j = 0; j < cnt0; j++)
    {
        nums[index++] = 0;
    }

    for (int i = 0; i < cnt1; i++)
    {
        nums[index++] = 1;
    }
    for (int i = 0; i < cnt2; i++)
    {
        nums[index++] = 2;
    }
}

void SortColor(vector<int> & nums) { 
    int 
}
int main()
{
    vector<int> nums = {0, 0, 0, 1, 2, 1, 2};

    SortColorswithPointer(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
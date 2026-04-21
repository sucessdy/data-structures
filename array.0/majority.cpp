#include <iostream>
#include <vector>
using namespace std;

int majorityBruteForce(vector<int> &nums)
{
    int cnt = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[i] == nums[j])
            {
                cnt++;
            }
        }
        if (cnt > nums.size() / 2)
        {
            return nums[i];
        }
    }
    return -1;
}

int majority(vector<int> &nums)
{
}
int main()
{
    vector<int> nums = {8, 8, 7, 7, 7};
    cout << majorityBruteForce(nums) << endl;
    return 0;
}
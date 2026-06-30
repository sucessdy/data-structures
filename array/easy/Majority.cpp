#include <iostream>
#include <vector>
using namespace std;

int Majority(vector<int> &nums)
{

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                cnt++;
            }
        }
        //    break ;

        if (cnt > nums.size() / 2)
        {
            return nums[i];
        }
    }

    return -1;
}
int majorityElement(vector<int> &nums)
{

    int freq = 0;
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        if (freq == 0)
        {
            ans = nums[i];
        }
        if (ans == nums[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }

    //    cout << nums[i] << endl;

    // else {
    return ans;
    // }
}

int majorityElementForOptimal(vector<int> &nums)
{
    int count = 0;
    int ans = 0;

    for (auto num : nums){
 if (count == 0){
            ans = num;
    }
count += (ans == num) ? 1 : -1;

    }
    return ans ;
}
int main()
{
    vector<int> nums = {2, 2, 1};
    cout << majorityElementForOptimal(nums) << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &nums, int st, int mid, int end)
{

    int right = mid + 1;
    int cnt = 0;

    for (int idx = st; idx <= mid; idx++)
    {
        while (right <= end && nums[idx] > 2LL * nums[right])
        {
           right++;
        }
        cnt += (right - (mid + 1));
    }
    int i = st ; 
    int j = mid + 1; 

    vector<int> ans;

    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
        {
            ans.push_back(nums[i++]);
        }
        else
        {
            ans.push_back(nums[j++]);
        }
    }
    while (i <= mid)
    { 
        ans.push_back(nums[i++]);
    }
    while (j <= end)
    {
        ans.push_back(nums[j++]);
    }
    for (int index = st; index <= end; index++)
    {
        nums[index] = ans[index - st];
    }
    return cnt;
}
int mergeSort(vector<int> &nums, int st, int end)
{
    if (st >= end)
    {
        return 0;
    }
    int mid = st + (end - st) / 2;
    int cnt = 0;
   cnt+= mergeSort(nums, st, mid) ;
          cnt+=    mergeSort(nums, mid + 1, end) ; 
   cnt+=  merge(nums, st, mid, end);

    return cnt;
}
 int reversePairs(vector<int>& nums) 
{

    return mergeSort(nums, 0, nums.size() - 1);
}

int main() 
{

    vector<int> nums = {1,3,2,3,1};
    cout << reversePair(nums) << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int mergeSort(vector<int> &nums, vector<int> &temp, int st, int end)
{
    int n = nums.size();
    int cnt = 0;
    int mid = st + (end - st) / 2;
    cnt += mergeSort(nums, temp, st, mid);
    cnt += mergeSort(nums, temp, mid + 1, end);
    int right = mid + 1;

    for (int idx = st; idx < mid; idx++)
    {
        while (right <= end && (long long)nums[idx] > 2 * nums[right])
        {
            right++;
        }
        cnt += right - (mid + 1);
    }
    int i = st;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {

        if (nums[i] <= nums[j])
        {

            temp[k++] = nums[i++];
        }
        else
        {
            temp[k++] = nums[j++];
        }
    }
    while (i < mid)
    {
        temp[k++] = nums[i++];
    }
    while (j < end)
    {

        temp[k++] = nums[j++];
    }

    for (int idx = st; idx < end; idx++)
    {
        nums[st] = temp[idx - st];
    }

    return -1;
}

int reversePair(vector<int> &nums)
{

    int n = nums.size();
    vector<int> temp(n);

    return mergeSort(nums, temp, 0, n - 1);
}

int main()
{
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << reversePair(nums) << endl;

    return 0;
}
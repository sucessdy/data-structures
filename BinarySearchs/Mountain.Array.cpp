#include <iostream>
#include <vector>
using namespace std;
// 1095. Find in Mountain Array
int peakElement(vector<int> &nums)
{
    int st = 0;
    int end = nums.size() - 1;
    while (st < end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid] > nums[mid + 1])
        {
            end = mid;
        }
        else
        {
            st = mid + 1;
        }
    }
    return st;
}
int binarySearch(vector<int> &nums, int target, int st, int end)
{

    bool orderArr = nums[st] < nums[end];
    while (st < end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }

        if (orderArr)
        {
            if (target < nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        {

            if (nums[mid] < target)
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
    }
    return -1;
}

int MoutainArray(vector<int> &nums, int target)
{
    int peak = peakElement(nums);

        int firstHalf = binarySearch(nums, target, 0, peak);

    if (firstHalf != -1)
    {
        return firstHalf;
    }
   return  binarySearch(nums, target, peak +1, nums.size()-1); 
}

int main()
{


    vector<int> arr = {1, 2, 3, 4, 5, 6, 4, 3, 1} ; 
    int target = 3;
    cout << MoutainArray(arr, target) << endl;
    return 0;
}
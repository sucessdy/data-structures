#include <iostream>
#include <vector>
using namespace std;

/// rotate sorted array

int BinarySearch(vector<int> &nums, int tar, int st, int end)
{
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid] == tar)
        {
            return mid;
        }
        if (nums[mid] < tar)
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

// we find the pivot but not work in duplicate

int FindPivot(vector<int> &nums)
{
    int st = 0;
    int end = nums.size() - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        // first case
        if (mid < end && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        // second case
        if (st < mid && nums[mid] < nums[mid - 1])
        {
            return mid - 1;
        }
        // third case
        if (nums[st] >= nums[mid])
        {
            end = mid - 1;
        }
        // fourth case
        else
        {
            st = mid + 1;
        }
    }
    return -1;
}

int FindPivotwithDuplicates(vector<int> &nums)
{
    int st = 0;
    int end = nums.size() - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        // first case
        if (mid < end && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        // second case
        if (st < mid && nums[mid] < nums[mid - 1])
        {
            return mid - 1;
        }
        // third case
        // if element at middle  start, end are equal we just skips that.
        if (nums[st] == nums[mid] && nums[mid] == nums[end])
        {

            // note :  what if these elementa at start and end he pivots
            // check if start is pivots first
            if (nums[st] > nums[st + 1])
            {
                return st; 

            }

            st++;

            if (nums[end] < nums[end - 1])
            {
                return end - 1;
            }

            end--;
        }
        // left side is sorted then the right pivots
        if (nums[st] < nums[mid] || (nums[st] == nums[mid] && nums[mid] > nums[end])){ 
st = mid + 1;
        }
        else
    {
        end = mid - 1;
    }
            
    }
    ;

    return -1;
}

int search(vector<int> &nums, int target)
{
    int pivot = FindPivotwithDuplicates(nums);
    if (pivot == -1)
    {
        return BinarySearch(nums, target, 0, nums.size() - 1);
    }
    if (nums[pivot] == target)
    {
        return pivot;
    }

    if (target >= nums[0])
    {
        return BinarySearch(nums, target, 0, pivot - 1);
    }

    return BinarySearch(nums, target, pivot + 1, nums.size() - 1);
}
int main()
{

    vector<int> nums = {3, 3, 5, 1};
    int target = 5;
    int index = search(nums, target);
    cout << "Target " << target << " found at index: " << index << endl;

    target = 3;
    index = search(nums, target);
    cout << "Target " << target << " found at index: " << index << endl;
    return 0;
}
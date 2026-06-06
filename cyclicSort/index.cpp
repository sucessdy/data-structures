#include <iostream>
#include <vector>
using namespace std;
// check -> swap -> move

void CyclicSort(vector<int> &nums)
{
    int i = 0;
    int n = nums.size();

    while (i < n)
    {
        int index = nums[i] - 1;
        if (nums[i] != nums[index])
        {
            swap(nums[i], nums[index]);
        }
        else
        {
            i++;
        }
    }
}

// 268. Missing Number

int missingNumber(vector<int> &nums)
{
    int i = 0;
    int n = nums.size();
    while (i < n)
    {
        if (nums[i] > 0 &&
            nums[i] <= n &&
            nums[i] != nums[nums[i] - 1])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }

    return i;
}
// 448. Find All Numbers Disappeared in an Array
vector<int> findDisappearedNumbers(vector<int> &nums)
{

    vector<int> ans;
    int i = 0;
    int n = nums.size();
    while (i < n)
    {
        int index = nums[i] - 1;

        if (nums[i] != nums[index])
        {
            swap(nums[i], nums[index]);
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            ans.push_back(i + 1);
        }
    }
    return ans;
}
// 287. Find the Duplicate Number
int findDuplicate(vector<int> &nums)
{
    int i = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            int index = nums[i] - 1;
            if (nums[i] != nums[index])
            {
                swap(nums[i], nums[index]);
            }
            else
            {
                return nums[i];
            }
        }
        else
        {
            i++;
        }
    }
    return -1;
}

//
// 442. Find All Duplicates in an Array

vector<int> findDuplicates(vector<int> &nums)
{
    int i = 0;
    vector<int> ans;
    int n = nums.size();
    while (i < n)
    {

        int index = nums[i] - 1;
        if (nums[i] != nums[index])
        {
            swap(nums[i], nums[index]);
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            ans.push_back(nums[i]);
        }
    }

    return ans;
}

// 645. Set Mismatch 
vector<int> findErrorNums(vector<int> &nums)
{

    int i = 0;
    int n = nums.size();
    vector<pair<int, int>> ans;
    while (i < n)
    {
        int index = nums[i] - 1;
        if (nums[i] != nums[index])
        {
            swap(nums[i], nums[index]);
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
        return {nums[i], i + 1 };
        }
    }
    return {-1, -1};
}

//  find missing positive

// CyclicSort
int firstMissingPositve(vector<int> &nums)
{
    int i = 1;
    int n = nums.size();
    while (i < n)
    {
        int index = nums[i] - 1;
        if (nums[i] != nums[index])
        {
            swap(nums[i], nums[index]);
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }
    return n;
}
int main() {
    vector<int> nums1 = {1, 2, 2, 4};
    vector<int> result1 = findErrorNums(nums1);
    cout << "Duplicate: " << result1[0] << ", Missing: " << result1[1] << endl;

    
    vector<int> nums2 = {1, 1};
    vector<int> result2 = findErrorNums(nums2);
    cout << "Duplicate: " << result2[0] << ", Missing: " << result2[1] << endl;
  
    
    return 0;
}
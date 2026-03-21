#include <iostream>
#include <vector>
#include <set>
using namespace std;
// tc : O(n log n)
// sc : O(n)

// at first we dont need to use the set there, the array is sorted ...
int RemoveDuplicate(vector<int> &n)
{
    set<int> s;
    vector<int> result;
    for (int i = 0; i < n.size(); i++)
    {
        if (s.find(n[i]) == s.end())

        {
            s.insert(n[i]);

            result.push_back(n[i]);

            // i++;
        }
    }
    n = result;
    return n.size();
}

int removeDuplicateOptimal(vector<int> &nums)
{
    int j = 0;
    if (nums.empty())
        return 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[j])
        {
            j++;
            nums[j] = nums[i];
        }
    }
    nums.resize(j + 1);
    return nums.size();
}

int RemoveDuplicateFaster(vector<int> &n)
{
    if (n.empty())
        return 0;

    int uniqueCount = 1; // first element is always unique

    for (int i = 1; i < n.size(); i++)
    {
        if (n[i] != n[uniqueCount - 1])
        {
            n[uniqueCount++] = n[i];
        }
    }

    n.resize(uniqueCount);
    return uniqueCount;
}

int removeDuplicateII(vector<int> &arr)
{

    int j = 2;
    int cnt = 0;
    if (arr.size() <= 2)
        return arr.size();
    for (int i = 2; i < arr.size(); i++)
    {

        if (arr[i] != arr[j - 2])
        {

            arr[j] = arr[i];
            cnt++;
            j++;
        }
    }
    if (cnt > 2)
    {
        arr[j] = 0;
    }

    arr.resize(j);

    return arr.size();
}

int removeDuplicates2(vector<int> &arr)
{

    int j = 2;

    if (arr.size() <= 2)
        return arr.size();
    for (int i = 2; i < arr.size(); i++)
    {

        if (arr[i] != arr[j - 2])
        {

            arr[j] = arr[i];

            j++;
        }
    }

    arr.resize(j);

    return arr.size();
}

// brute force time = (n logn )
// space complexity : 0(n) cz use set and also for storting the result i use vector
// this is brute... forve... i can think but set is not optimal cuz array is sorted.. not need to use. set
int removeDuplicateSet(vector<int> &arr)
{
    set<int> s;
    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.find(arr[i]) == s.end())
        {
            s.insert(arr[i]);
            result.push_back(arr[i]);
        }
    }
    arr = result;
    return arr.size();
}
// two pointer...apprach best
// time complexity = O(n)
// space complexity = O(1) just use j int... as a pointer
int removeDuplicates(vector<int> &arr)
{
    if (arr.empty()) return 0;

    int j = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }
    arr.resize(j + 1);

    return arr.size();
}
int main()
{
    vector<int> n = {};
    cout << removeDuplicates(n) << endl;

    for (auto i : n)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// brute force  apprach
// first is to create a temp to store the value non-zero value then after copying all the non-zero after u fill with remaing size of array with a zeros then we're copying all the value back to original

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp(n);

    int j = 0; // to keep track of the index in temp[]
    for (int i = 0; i < n; i++)
    {

        if (nums[i] != 0)
        {
            temp[j++] = nums[i];
            // j++;
        }
    }
    // remaining zero

    while (j < n)
    {
        temp[j++] = 0;
    }
    // copying back to nums

    for (
        int i = 0; i < nums.size(); i++)
    {
        nums[i] = temp[i];
    }
}

void moveZerosOptimal(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        cout << "empty"; // for edge case where nums is empty cuz i can't return anyting its void function
    }
    int j = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        if (nums[i] != 0)
        {
            swap(nums[i], nums[j++]);
        }
    }
}

int main()
{
    vector<int> num = {2, 4, 0, 5, 0, 5};
    moveZerosOptimal(num);

    for (auto i : num)
    {
        cout << i;
    }
    cout << endl;

    return 0;
}
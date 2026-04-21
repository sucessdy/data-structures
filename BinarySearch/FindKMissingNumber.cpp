#include <iostream>
#include <vector>
using namespace std;

int FindMissingKNumber(vector<int> &nums, int k)
{

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] <= k)
        {
            k++;
            ;
        }
        else
        {

            break;
        }
    }
    return k;
}

int findMissigNumber(vector<int> &nums, int k)
{
    int low = 0;
    int high = nums.size() - 1;
    int miss = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        miss = nums[mid] - (mid + 1);
        if (miss < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low + k; // or high + 1 + k 
}
int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    cout << findMissigNumber(arr, 5) << endl;
    return 0;
}
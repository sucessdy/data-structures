#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != nums[j])
        {
            j++;
            nums[j] = nums[i];
        }
    }
    return j + 1;
}
int main()
{
    vector<int> n = {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(n) << endl;
    return 0;
}
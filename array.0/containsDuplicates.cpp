#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; ++i)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
}

bool containsDuplicates(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++)
    {

        if (nums[i] == nums[i - 1])
        {

            return true;
        }
    }
    return false;
}

bool containsDuplicatesModdify(vector<int> &nums)
{
   for ( int i =0; i < nums.size() ; i ++) {
    int index = abs(nums[i]) ;
    if (nums[index ] < 0){ 
return true; 
    }
    nums[index] *= -1; 
   }
   return false; 
}



int main()
{
    vector<int> nums = {2, 1};
    bool res = containsDuplicatesModdify(nums);

    cout << (res ? "true" : "false") << endl;

    return 0;
}
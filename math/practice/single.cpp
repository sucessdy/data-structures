#include <iostream>
#include <vector>
#include <unordered_map> 
using namespace std;
// single number 11

int singleNumber(vector<int> &num)
{
    vector<int> bit(32);
    for (int n : num)
    {
        for (int i = 0; i < 32; i++)
        {

            if (n & (1 << i))
            {
                bit[i]++;
            }
        }
    }
    int ans = 0;

    for (int i = 0; i < 32; i++)
    {
        if (bit[i] % 3 == 1)
        {
            ans |= (1 << i);
        }
    }

    return ans;
}

int singleNumberII(vector<int> &nums)
{
    unordered_map<int, int> mp; 
    for (int i = 0; i < nums.size() ; ++i){
        mp[nums[i]]++;
    }
    for (const auto &val : mp){
        if ( val.second == 1){
         return val.first ; 
        }
    }return -1; 
}
// bit mamipulation 
int singleNumberIIoptimal (vector<int> & nums) { 
    int ones = 0; 
    int tows = 0; 
    for (auto val : nums) { 
        ones = (val ^ ones) & ~tows ;
        tows = (val ^ tows)  & ~ones ; 
    }
    return ones ; 
}

int main()
{

    vector<int> arr = {2, 2, 2,  1};
    cout << singleNumberIIoptimal(arr) << endl;
   


    return 0;
}
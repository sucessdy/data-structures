#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdint>
using namespace std;

class Solution
{
    static constexpr uint32_t SIZE = 1 << 19;
    static constexpr uint32_t MASK = SIZE - 1;

    static uint8_t table[SIZE];
    static uint8_t gen;

    static uint64_t hash(uint64_t v)
    {
        return v ^ (v << 2) ^ (v >> 19);
    }

public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        ++gen;

        for (int x : nums)
        {
            uint32_t h = hash(static_cast<uint64_t>(x)) & MASK;

            if (table[h] == gen)
                return true;

            table[h] = gen;
        }

        return false;
    }
};

uint8_t Solution::table[Solution::SIZE] = {};
uint8_t Solution::gen = 0;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        int x = nums[i];

        if (st.find(x) != st.end())
        {
            return true;
        }
        else
        {
            st.insert(x);
        }
    }
    return false;
}

bool containsDuplicated(vector<int> &nums)
{
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        if (s.find(nums[i]) != s.end())
        {
            return true;
        }
        else
        {
            s.insert(nums[i]);
        }
    }
    return false;
}

 bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for ( int i = 0; i < nums.size() ;  i ++) {
            for ( int j = k;  j < nums.size() ; j++) { 
                if (  i < j && nums[i] == nums[j] && abs(i-j) <= k )  { 
                    // if ( ) { 
                        return true; 
                    // } 
                }
            }
        }
        return false; 
    } 
int main()
{
vector<int> nums = {1,0,1,1} ;
bool res = containsNearbyDuplicate(nums , 1) ;

cout << (res? "true" : "false") << endl;
    return 0;
}
// Top K  frequent Element
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

vector<int> topKFrequent(vector<int> &nums, int k)
{
    k = sizeof(nums) / sizeof(nums[0]);
    sort(nums.begin(), nums.end());
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1] && k > nums.size())
        {
            ans.push_back(nums[i]);
        }
    }

    return ans;
}

vector<int> topk(vector<int> &nums, int k)
{

    vector<int> ans;
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto it : mpp)
    {
        pq.push({it.second, it.first});
    }
    for (int i = 0; i < k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequencies
        for (int num : nums)
            freq[num]++;

        // Bucket array
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto &it : freq)
            bucket[it.second].push_back(it.first);

        vector<int> ans;

        // Traverse from highest frequency
        for (int i = nums.size(); i >= 0 && ans.size() < k; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
}; 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;//nums[i] -> freq

        for(int x : nums) {
            mp[x]++;
        }

        //make a min-heap which stores a pair of (freq, num).
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto it : mp) {
            pq.push({it.second, it.first});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        while(pq.size() > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        
        return ans;
    }
};

int main()
{

    vector<int> nums = {1, 1};
    int k = 1;

    vector<int> res = topk(nums, k);
    for (auto const &i : res)
    {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
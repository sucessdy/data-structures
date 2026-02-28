#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int LongestSubarray(vector<int> &arr, int k)
{
    int l = 0;
    int maxSub = 0;
    int sum = 0;
    int r = 0;

    while (r < arr.size())
    {
        sum += arr[r];
        while (sum > k)
        {

            sum -= arr[l];
            l++;
        }

        if (sum <= k)
        {
            maxSub = max(maxSub, r - l + 1);
        }

        r = r + 1;
    }
    return maxSub;
}

int shortestSubarray(vector<int> &nums, int k)
{
   
    vector<int> result ; 

    int sum = 0; 

}

int main()
{

    vector<int> a = {2,-1,2};
    int k = 3;

    cout << LongestSubarray(a, k) << endl;
    cout << "jeje" << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
// fixed size window type
int ConstantWindow(vector<int> &arr, int k)
{
    int n = arr.size();

    int maxSum = 0;

    for (int i = 0; i < k; i++)
    {
        maxSum += arr[i];
    }
    int window = maxSum;

    for (int i = k; i < n; i++)
    {
        window += arr[i];     // add
        window -= arr[i - k]; // remove
        maxSum = max(maxSum, window);
    }
    return maxSum;
}
// Maximum Sum of a Subarray with K Elements
// this si where we Try every window
vector<int> MaximumSlidingWindow(vector<int> &arr, int k)
{
    int n = arr.size();


    vector<int> result;
    for (int i = 0; i <= n - k; i++)
    {    int maxsum = INT_MIN;
        int sum = arr[i];

        for (int j = 0; j <   k; j++)
        {
            sum = arr[ i + j]; // here its sum
            maxsum = max(sum, maxsum);
        }
        // here we get the max value

        result.push_back(maxsum);
    }

    return result; // return the max vale
}

vector<int> maxSubarray(vector<int> &a, int k)
{
    vector<int> ans;

    int windowSum = 0;
    for (int i = 0; i <= k; i++)
    {
        windowSum += a[i];
    }
    int maxSum = windowSum;
    for (
        int j = k;
        j < a.size(); j++)
    {
        windowSum += a[j];
        windowSum -= a[j - k];
        ans.push_back(maxSum);
        maxSum = max(windowSum, maxSum);
    }
    return ans;
}

int main()
{

    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> answer = MaximumSlidingWindow(arr, k);
    for (auto i : answer)
    {
        cout << i << " ";
    }
    cout << endl;

    //  cout <<  MaximumSubarray(arr , k) << endl;
    // cout << ConstantWindow(arr, k) << endl;

    return 0;
}
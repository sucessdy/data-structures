#include <iostream>
#include <vector>
using namespace std;

void merge(vector<pair<int, int>> &arr, vector<int> &ans, int st, int mid, int end)
{
    vector<pair<int, int>> temp(end - st + 1);
    int i = st;
    int j = mid + 1;
    int k = 0;

    int rightCounter = 0;
    while (i <= mid && j <= end)  // Fixed: changed 'right' to 'end'
    {
        if (arr[i].first <= arr[j].first)
        {
            ans[arr[i].second] += rightCounter;
            temp[k++] = arr[i++];
        }
        else
        {
            rightCounter++;
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        ans[arr[i].second] += rightCounter;
        temp[k++] = arr[i++];
    }

    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    
    for (int p = 0; p < temp.size(); p++)
    {
        arr[st + p] = temp[p];  // Fixed: copying from temp to arr
    }
}

void mergeSort(vector<pair<int, int>> &arr, vector<int> &ans, int st, int end)
{
    if (st >= end)
        return;

    int mid = st + (end - st) / 2;  // Moved mid calculation here

    mergeSort(arr, ans, st, mid);
    mergeSort(arr, ans, mid + 1, end);
    merge(arr, ans, st, mid, end);
}

vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, 0);
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back({nums[i], i});
    }
    mergeSort(arr, result, 0, n - 1);
    return result;
}

int main()
{
    vector<int> arr = {1, 7, 2, 5};
    vector<int> ans = countSmaller(arr);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;  // Added newline for better output
}
#include <iostream>
#include <vector>
using namespace std;

// brute force 
vector<int> countSmaller(vector<int> & nums ) { 

       int n = nums.size();
    vector<int> ans (n , 0); 

    for ( int i = 0;  i < nums.size() ; i++) { 
            int cnt = 0 ; 
        for ( int j = i + 1  ; j < nums.size() ; j ++) { 
            if ( nums[i] > nums[j]) {
                cnt++; 

                 
            }

        }
        ans[i] = cnt;
    }
    return ans; 
}
// opitamal. 
// time complexity  - O(n) 
// space complexity  - O(1) 
class Solution {
public:
   

void merge(vector<pair<int, int>> &arr, vector<int> &ans, int st, int mid, int end)
{
    vector<pair<int, int>> temp(end - st + 1);
    int i = st;
    int j = mid + 1;
    int k = 0;

    int rightCounter = 0;
    while (i <= mid && j <= end)  
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
        arr[st + p] = temp[p];  
    }
}

void mergeSort(vector<pair<int, int>> &arr, vector<int> &ans, int st, int end)
{
    if (st >= end)
        return;

    int mid = st + (end - st) / 2; 

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

  
};

int main() {
    vector<int > nums = {5,2,6,1} ;
    vector<int> ans = countSmaller(nums) ; 
    for (auto i : ans) {
        cout << i << " " ;
    }
    cout << endl; 
    return 0;
}
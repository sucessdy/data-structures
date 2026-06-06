#include <iostream>
#include <vector>
using namespace std;
// find the first and last position in Sorted array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array
int Search(vector<int> &arr, int k, bool startFirstIndex)
{
    int ans = -1;
    int st = 0;
    int end = arr.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (arr[mid] > k)
        {
            end = mid - 1;
        }
        else if (arr[mid] < k)
        {
            st = mid + 1;
        }
        else
        {
            ans = mid;

            if (startFirstIndex == true)
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
    }
    return ans;
}
vector<int> searchRange(vector<int> &arr, int k)
{
vector<int> ans = {-1, -1} ; 
int start = Search (arr, k, true); 
int end = Search(arr, k , false) ; 
ans[0] = start; 
ans[1] = end 
; 
return ans; 
}
int main()
{
    vector<int> arr = {5,7,7,8,8,10};
    int k = 8;
    vector<int> res = searchRange(arr, k);
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
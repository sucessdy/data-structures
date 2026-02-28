#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int maximumSubarraySum(vector<int> &arr, int k)
{
    
    int i = 0;
    int j = 0;
    unordered_map <int, int> m ; 
    int maxSub  = INT_MIN ; 
    int sum = 0;
    while (j < arr.size())
    {
        sum += arr[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            maxSub = max(sum, maxSub);
            sum -= arr[i];
          i++; 
          j++;   
        }

    }
    return maxSub;
}
int main()
{
    vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;
    cout << maximumSubarraySum(arr, k) << endl;
    return 0;
}
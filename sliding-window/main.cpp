#include <iostream>
#include <vector>
using namespace std;
// dyamic window 
int longestSubarray(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxLen = 0; 

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum <= k)
            {
                maxLen = max(maxLen , j - i + 1);
            }
            
        }
    }
    return maxLen;
}

int LongestSubarraywithBetter(vector<int> &arr , int k){ 
int l = 0;
int r =0 ; 
int maxLen =0;
     int sum =0; 
 while (r< arr.size()){ 

    sum+= arr[r] ; 

// i need ti check the invalid condition 
while (sum > k){
     sum-= arr[l];

     l++;

}

    if (sum <= k){
        maxLen = max(maxLen, r - l+1); 

    }

    r= r + 1;
 }
 return maxLen; 

}
int main()
{
 
 vector<int> arr = {10, 5, 2, 7, 1, 90};
int k = 15; 
cout << LongestSubarraywithBetter(arr, k) << endl; 
 return 0;
}
#include <iostream>
#include <vector>

using namespace std;

void subarray(vector<int> &arr)
{
    // vector<int> temp =0 ;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            // temp.push_back(arr[j]) ;
            for (int k = i; k <= j; k++)
            {
                cout << arr[k];
            }
            cout << " ";
        }
        cout << endl;
    }
}

int subarrayBetter(vector<int> &arr)
{
    vector<int> temp;
    int maxSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int curr = 0;

        for (int j = 0; j < arr.size(); j++)
        {
            curr += arr[j];
        }
        maxSum = max(curr, maxSum);

        if (maxSum > curr)
        {
            maxSum = curr;
        }
    }
    return maxSum;
}

int subarraySum(vector<int> &arr, int k)
{
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                cnt++;
            }

        }
    }
    return cnt;
}

vector<int> PrefixSum(vector<int> & arr){
    int n = arr.size(); 
    vector<int> Prefix(n) ;
Prefix[0] = arr[0]; 

    for (int i = 0; i < n;i ++){
Prefix[i] = Prefix[i - 1] + arr[i]; 

    }
    return Prefix; 

}

int maxSubArray(vector<int>& nums) {
        int maxSub = INT_MIN;

        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr += nums[i];
            maxSub = max(curr, maxSub);
             if (curr < 0 ){
            curr = 0; 
        }
        }
        return maxSub ;

    } 
int main()
{
vector<int> arr ={-2,1,-3,4,-1,2,1,-5,4} ; 
     cout << maxSubArray(arr) << endl;
    // vector<int> arr = {9, 4, 2, 10, 5};
    // cout << subarraySum(arr, 33) << endl;
    // subarray(arr) ;
    // cout << subarrayBetter(arr) << endl;
    // vector<int> res = PrefixSum(arr) ;
    // for (auto i : res){
    //     cout << i << " ";
    // }
    // cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
// int firstMissing(vector<int> &nums) {
// sort(nums.begin(), nums.end()) ;
// int res  = 1 ;

// for ( int i =0 ;i < nums.size() ; i ++) {
//     if ( res == nums[i]){
//         res++;
//     }
//     // else if (res > nums[i]) {

//     //     break;
//     // }
// }
vector<int> findMissingElements(vector<int> &nums)
{
    vector<int> ans;
int n = nums.size() ; 
    vector<bool> seen(n , false);
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int index = nums[i] - 1;
        if (i > 0 && nums[i] != nums[index])
        {
            seen[nums[i]] = true;
            // swap(nums[i] , nums[index]) ;
            sum += nums[i];
        }
        else
        {
            i++;
        };
    }

    for (int n = 0; n < sum; n++)
    {
        if (!seen[n] && nums[n] != n + 1)
        {
            ans.push_back(n + 1);
        }
    }

    return ans;
}

//  int firstMissingPositive(vector<int>& nums) {

//         int n = nums.size();
//         vector<bool>seen(n+1, false);

//         for ( int num : nums){
//             if(num>0 && num<=n){
//                 seen[num]=true;
//             }
//         }

//         for ( int i=1; i<=n; i++ ){
//             if(!seen[i]){
//                 return i;
//             }
//         }

//         return n+1;
//     }
// return res;
// }

int main()
{
    vector<int> nums = {1, 2, 0};
vector<int> ans = findMissingElements(nums) ;

     for( auto i : ans){
        cout <<i  << " ";
    }
    cout << endl; 
    return 0;
}
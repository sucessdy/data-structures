#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> SlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for ( int i = k ; i < nums.size() ; i++){ 
        ans.push_back(nums[dq.front()]) ;

        while (!dq.empty() && dq.front() <= i - k ){ 
           dq.pop_front() ; 
        }
        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front() ] ); 
    return ans;
}

int main()
{vector<int> a = {1, -2};
int k  =1; 
vector<int> res  = SlidingWindow(a,k);
for ( const auto i : res){
    cout << i << " " ; 
}
cout << endl; 

    return 0;
}
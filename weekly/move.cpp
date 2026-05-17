#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
// brute force

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp(n);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            temp[j++] = nums[i];
        }
    }

    while (j < n)
    {

        temp[j++] = 0;
    }

    for (int i = 0; i < n; i++)
    {

        nums[i] = temp[i];
    }
}

// / time complexity O(n)
//  space complexity O(1)
//  simple we use 2 pointer apprach here...
// we  see a zero value and swap with non-zero element and we find at the last our zero value is getting shift to the right.. means last...
// we  ingore the zero with non-zero element... and last we find that ..our zero is shifting to the right and non=zero a t left..


void moveZeroesTwoPointer(vector<int> &nums)
{
    int j = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j++]);
        }
    }
}

// void moveZeroesT (vector<int> & nums) {
// int j = nums.size() - 1;

//   int i = 0 ;
//   while ( i< j){
//     if (nums[i] != 0){
//       swap(nums[i] , nums[j]) ;
//     }

//       i++;
//       j--;
//   }

//   }

int main()
{
    vector<int> nums = {2, 7, 0, 0, 4, 5};
    moveZeroesTwoPointer(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
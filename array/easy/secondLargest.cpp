#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

int secondSmallFn(int nums[], int n)
{
    int small = 0;
    int secondSmall = 0;
    for (int i = 0; i < n; i++)
    {
        if (n > 2) return -1; 
        if (small > nums[i])
        {

            secondSmall = small;
            small = nums[i];
        }
        else if (secondSmall > nums[i] && nums[i] != small)
        {
          secondSmall = nums[i];
        }
    }
    return secondSmall;
}
int secondLargest(int nums[], int n)
{
    int largest = 0;
    int secondLargest = 0 ;
    for (int i = 0; i < n; i++)
    {
        
if ( n > 2 ) return -1; 
        if (largest < nums[i])
        {
            secondLargest = largest;
            largest = nums[i];
        }
        else if (secondLargest < nums[i] && largest != nums[i])
        {
             secondLargest = nums[i];
        }
    }
    return secondLargest;
}

int secondLargests (int nums[] , int n )   { 
    int secondL = INT_MIN; 
    int largest = INT_MIN; 
    if (n < 2) return -1 ; 
for (int i = 0; i < n ; i ++ ) {
    if (nums[i] > largest){ 
secondL= largest ; 
largest = nums[i]; 

    }
  else   if ( largest != nums[i] && secondL < nums[i]){ 
         secondL = nums[i] ; 
    } 
}
return ( secondL == INT_MIN ? -1 : secondL); 

}
int main()
{
    int nums[] = {-2, 10};
    int n = sizeof(nums) / sizeof(nums[0]);
cout << secondLargests(nums, n) << endl; 
    // cout << secondSmallFn(nums, n) << endl;
    // cout << secondLargest(nums, n) << endl;
    // cout << secondLargest(nums, n) << endl;
    return 0;
}
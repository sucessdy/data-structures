#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int st = 0;

    int end = nums.size() - 1;
    while (st < end)
    {
        int mid = st + (end - st) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        else if (nums[mid] < target)
        {
            st = mid + 1;
            continue;
        }
        else
        {
            end = mid;

            continue;
        }
    }
    return st;
}


bool isValid(vector<int> & nums, int n, int m, int mid){
    int pages = 0; // pages 
    int sT =1 ; // student 
    
    for ( int i = 0; i < n ; i++){ 

        if ( nums[i] > mid){
            return false; 
        }
        if (pages + nums[i] <= mid){

 pages += nums[i] ; 

        }
        else { 
            sT++; 
            pages = nums[i] ; 


        }
    }
return sT > m ? false : true ; 

}
int allocationBook(vector<int> &nums, int n, int m)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    int st = 0;
    int end = sum;
    int ans = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isValid( nums,  n, m, mid)) // vvalid  -> left 
        {
            ans = mid;
       end = mid -1 ;

        }
        else  {
             //  not valid  -> to right 
     st= mid + 1 ; 
        }
    }
    return ans;
}
int main()
{
    vector<int> num = {2, 1, 3, 4};
    int n = 4 ; 
    int m = 2;

    cout << allocationBook(num, n, m) << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void cylicSort(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;

    while (i < n)
    {
        int index = arr[i] - 1;
        if (arr[i] != arr[index])
        {
            swap(arr[i], arr[index]);
        }
        else
        {
            i++;
        }
    }
}

//  misig number

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        int index = nums[i];

        if (nums[i] != nums[index])
        {
            swap(nums[i], nums[index]);
        }
        else
        {
            i++;
        }
    }
    for (int index = 0; index < n; index++)
    {
        if (nums[index] != index)
        {
            return index;
        }
    }
    return i;
}

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    vector<int> ans ; 

    int n = nums.size() ; 
    int i = 0; 
    while ( i < n) {
        int index = nums[i] -1 ; 

        if ( nums[i] != nums[index]){ 
            swap(nums[i], nums[index]); 
        }
        else { 

            i++; 
        }
    }

    for ( int index = 0; index < n ; index ++){ 
        if( nums[index] != index + 1){
        ans.push_back( index + 1);
        }
    }
return ans; 
}

int binaryToDecimal (int num ) { 
int ans = 0 ;
int power = 1;
while (num > 0){
    int dig = num / 10 ; 
    power *= 2 ; 
    ans += (dig * power) ;
    num=/10;

}
return ans; 
}

string findDifferentBinaryString(vector<string>& nums) {
        
    } 


int main()
{
    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};
    //
    // cout << missingNumber(arr) << endl;
vector<int> ans = findDisappearedNumbers(arr); 
for ( auto i : ans){
    cout << i  << " " ;
}
cout << endl; 
    // cylicSort(arr);
    // for( int i = 0; i< arr.size() ; i ++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    return 0;
}
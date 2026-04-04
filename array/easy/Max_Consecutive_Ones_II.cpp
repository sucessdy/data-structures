#include <iostream>
#include <vector>
using namespace std;
// max_consecutive one 2

int longestOne(vector<int> &arr)
{
    int maxLen = 0;
    int zero_count = 0;
    int left = 0;

    for (int right = 0; right < arr.size(); right++)
    {
        if (arr[right] == 0)
        {
            zero_count++;
        }
        while (zero_count > 1)
        {
            if (arr[left] == 0)
            {
                zero_count--;
            }
            left++;
        }

        maxLen = max(maxLen, right - left+ 1) ; 
    }
    return maxLen ; 

}
int main()
{

    vector<int> arr= {0,1,0,1,1}; 
    cout << longestOne(arr) << endl; 

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
// max_consecutive one I

int longestOne(vector<int> &arr)
{
   int curr  = 0 ;
   int maxLen = 0; 
   for (int i = 0 ; i< arr.size() ; ++i){

    if (arr[i] == 1){
    curr++; 


        maxLen = max(curr, maxLen) ; 


    }else { 
curr = 0; 
    }
   }
   return maxLen ; 
} 
int main()
{

    vector<int> arr= {}; 
    cout << longestOne(arr) << endl; 

    return 0;
}
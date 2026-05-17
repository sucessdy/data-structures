#include <iostream>
#include <unordered_map> 
#include <vector> 
#include <algorithm>
using namespace std;
// brute force  

// outer loop -> buy stoock 
// inner loop -> sell stock 
// res   store value 
//   max profrofit =>. res , with sell - buy we get the max profit; 


  int maxProfit(vector<int>& prices) {
    int p = prices.size() ; 
    int res = 0; 
    for( int i= 0 ; i < p-1 ;  i ++) { 
      for ( int j = i + 1; j < p ; j++){
         res=max(res, prices[j] - prices[i]) ;
         
      }
    }
    return res; 
  }
 
 // optimal 
 int maxProfitOptimal (vector<int> & prices ) { 
   int maxProfit = 0; 
   int curr =  prices[0] ; 
   for (int i =1 ; i < prices.size() ; i ++){ 

     if (curr < prices[i]){
       maxProfit = max(maxProfit , prices[i ] - curr ) ; 
        // curr++;  
     } 
     
   
     curr= min(curr, prices[i]) ; 
   } 
   return maxProfit ; 
 } 
 
 // 
  int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=INT_MIN;
        int maxi=INT_MIN;
        for(int i=0;i<prices.size();i++){
            mini=min(prices[i],mini);
            profit=prices[i]-mini;
            maxi=max(profit,maxi);       
             
             }
             return maxi;
    }
    
int main() 
{
  vector<int> nums = {7,6,4,3,1} ; 
  // 7,6,4,3,1
  // 7,1,5,3,6,4/
cout << maxProfitOptimal(nums) <<endl; 
  // for (auto i : nums){
  //   cout << i << " ";
     
  // }
  // cout << endl; 
   
   
    return 0;
}
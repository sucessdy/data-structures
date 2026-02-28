#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

vector<int> FirstNegativeNumber(vector<int> & arr, int k){
    queue<int> q; 
    vector<int> ans; 
    int n = arr.size() ; 
//  first window 
    for (int i =0; i < k; i++ ) { 
        if (arr[i] < 0){
            q.push(i); 

        }
      


    }
ans.push_back(q.empty() ? 0 : arr[q.front()]) ; 
    // slide window 

    for (int i = k ; i < n ;i ++ ){
        while (!q.empty( )&& q.front() <= i -k){
            q.pop(); 

        } 

      
       if (arr[i] < 0){ 
        q.push(i);
       }


ans.push_back(q.empty() ? 0 : arr[q.front()]) ; 
    }
    return ans ; 
 }
int main() {
    
    vector<int> arr = {12, -1, -7, 8 , -15, 30, 16, 28} ;
    int k = 3 ; 
    vector<int> res = FirstNegativeNumber(arr, k) ;
    for (int x : res) {
    cout << x << " ";
}
cout << endl;
   
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> Pascal(int numsRow) { 
vector<vector<int>> res ; 
for ( int  i = 0 ; i < numsRow ; i++){
    vector<int>  row (i + 1, 1)  ; 
    for( int j = 1 ; j < i  ; j ++){
row[j] = res[i-1][j-1] + res[i-1][j] ; 
    }
    res.push_back(row) ;


}
return res ; 
}

int main() {
  int numsrow= 5; 
  vector<vector<int>>  res= Pascal(numsrow) ;

  for (auto i : res ){ 
    for ( auto it : i){
        cout << it << " " ;
    }
    cout << endl; 
  }  
    return 0;
}
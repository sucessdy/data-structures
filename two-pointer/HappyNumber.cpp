#include <iostream>
#include <vector>
#include <unordered_set> 
using namespace std;

  bool isHappy(vector< int> n) {
        unordered_set<int> set; 

        for (auto it : n){ 
if (set.find(it ) != set.end() ) {
     return false;
}
set.insert(it) ;
        }
        return true  ;
    }

int main() {
vector<int> n  = {2}; 
    bool res = isHappy(n); 

    cout << (res ? "true" : "false") << endl;    
    return 0;
}
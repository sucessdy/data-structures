#include <iostream>
#include <vector>
using namespace std;
int GasStation(vector<int> & gas , vector<int> & cost){ 
    int start = 0; 
    int currentGas = 0;   
    int totalGas = 0; 
    int totalCost = 0 ;   
    for (int i = 0 ; i < gas.size( ) ; ++i){ 
        totalGas += gas[i] ; 
    }
    for ( int i =0 ; i < cost.size() ; ++i)
    {
        totalCost += cost[i] ; 
    }

    if (totalGas < totalCost ) {
        return -1;
    }else { 
         for (int i =0 ; i < gas.size(); ++i){
            currentGas += gas[i] - cost[i] ; 
            if (currentGas < 0){
                start = i + 1; 
                currentGas = 0 ;
            }
         }
         
    } 
    return start ; 


}
// others code. 
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int cur = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            cur += gas[i] - cost[i];
            if (cur < 0) {
                start = i + 1;
                cur = 0;
            }
        }
        return total >= 0 ? start : -1;
int main() {
    vector<int> gas = {2,3,4} ;
    vector<int> cost = {3,4,3} ;
    cout << GasStation(gas, cost) << endl;
    return 0;
}
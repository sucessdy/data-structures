#include <iostream>
#include <vector>
using namespace std;

// 134 -> leetcode...
/*
gas = 2, 3,4
cost = [3, 4,3]
index -> 0 -> 2 gas -> but is 3  cost needs so, we can't able to travel cus the cost is more
index -> 1 -  3 gas -> but here cost is more than the gas needs 4 cost... can't bare it ..
index -> 2 = 4 gas -> but here we can travel the  next  station distance  -> still 1liters gas is still in the tank so..pass to next gas..station
step -> 2
index-> 0 ->  2gas + 1 gas (from previous ) and cost is 3 cost... we able to travel but no gas is left for the next statiom ...

index 1 -> 3 gas and cost is 4 here so.. (travel around the circuit once in the clockwise direction)  3 gas and 4 cost... we can't boorrrow here... so we not even able to complete the  round of a  trip so return -1 ;...

*/

/* 
dry run 

index:   0   1   2   3   4
gas:     1   2   3   4   5
cost:    3   4   5   1   2
diff:   -2  -2  -2  +3  +3

step -> 1 

index  =0 ;
curr < 0 ->reset

start = 1 

step 2 ->  index -> 2 

diff = -2
curr = -2
total = -4

❌ reset again

start = 2
curr = 0

step 3 -> index 2 

diff = -2 
curr = -2
 total -6 

 reset onece agiain 

 step 4 -> index 3 
 diff = +3 
 curr = 3
 total -3 
 can continue 

index -> 4 
diff = > + 3 
curr -> 6
total  0
continue 

*/

int GasStation(vector<int> &gas, vector<int> &cost)
{
    int start = 0;
    int currentGas = 0;
    int totalGas = 0;
    int totalCost = 0;
    for (int i = 0; i < gas.size(); ++i)
    {
        totalGas += gas[i];
    }
    for (int i = 0; i < cost.size(); ++i)
    {
        totalCost += cost[i];
    }

    if (totalGas < totalCost)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < gas.size(); ++i)
        {
            currentGas += gas[i] - cost[i];
            if (currentGas < 0)
            {
                start = i + 1;
                currentGas = 0;
            }
        }
    }
    return start;
}
// others code.
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int total = 0;
    int cur = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        total += gas[i] - cost[i];
        cur += gas[i] - cost[i];
        if (cur < 0)
        {
            start = i + 1;
            cur = 0;
        }
    }
    return total >= 0 ? start : -1;
}

int gasStationCodeOptimal(vector<int> &gas, vector<int> &cost)
{
    if (gas.empty())
        return -1;
    int n = gas.size();
    int curr = 0;
    int start = 0;
    int total = 0;

    for (int i = 0; i < n; ++i)
    {

        int diff = gas[i] - cost[i];
        total += diff;
        curr += diff;

        if (curr < 0  ){
            start = i + 1;
             curr = 0;

        }
    }
    return (total >= 0) ?  start : -1 ; 

}
int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3,4,5,1,2};
    cout << gasStationCodeOptimal(gas, cost) << endl;
    return 0;
}
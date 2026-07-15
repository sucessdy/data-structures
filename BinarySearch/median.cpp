#include <iostream>
#include <vector>
using namespace std;

double median(vector<int> &a, vector<int> &b)
{
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> c;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            c.push_back(a[i++]);
        }
        else
        {
            c.push_back(b[j++]);
        }
    }

    while (i < n1)
    {
        c.push_back(a[i++]);
    }
    while (j < n2)
    {
        c.push_back(b[j++]);
    }

    int n3 = c.size() ; 

    if ( n3  % 2 != 0){
        return  c[n3/ 2]; 
    }
    else {
        int mid = n3 / 2; 
       int m = (c[mid] + c[mid - 1]) / 2.0; 

        return m; 
    }
    // return {-1, -1};
    
}
int main()
{
    vector<int> a = {1, 2};
    vector<int> b = {3, 4};
    cout << median( a, b) << endl;

    // vector<int> ans = median(a, b);
    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    return 0;
}
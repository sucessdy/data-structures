// stock span problem

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> StockSpan(vector<int> &price)
{
    stack<int> st;
    int n = price.size() ; 
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && price[st.top()] <= price[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = (i + 1);
        }
        else
        {

          ans[i]=    (i - st.top());
        }

        st.push(i) ; 
    }
    return ans;
}
int main()
{

    vector<int> price = {100, 80, 60, 70, 60, 75, 85} ;
    vector<int> res= StockSpan(price) ;  
    for (auto i : res) { 
        cout << i << " " ; 
    }
    cout << endl; 
    return 0;
}
// A. Fibonacciness ->/2060/A
#include <iostream>

#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--)
    {
        int a1, a2, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;

        int x1 = a1 + a2;
        int x2 = a4 - a2;

        int x3 = a5 - a4;

        map<int, int> m;
        int ans = 0;
        m[x1]++;
        m[x2]++;
        m[x3]++;

        for (auto p : m)
        {
            ans = max(ans, p.second);
        }

        cout << ans << endl;
    }
    return 0;
}
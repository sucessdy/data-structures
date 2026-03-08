#include <iostream>
#include <vector>
using namespace std;
// C. Where's My Water?/2207/problem/C

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long h;
        cin >> n >> h;

        vector<long long> a(n + 1);
        vector<long long> water(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            water[i] = h - a[i];
        }
        vector<long long> pref(n + 1);

        for (int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + water[i];
        }
        long long ans = pref[n];

        for (int i = 1; i < n; i++)
        {
            long long left = pref[i];
            long long right = pref[n] - pref[i];
            ans = max(ans, left + right);
        }
        cout << ans << endl;
    }

    return 0;
}
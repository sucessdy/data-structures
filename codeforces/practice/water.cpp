#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// C. Where's My Water?/2207/problem/C

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long h;
        cin >> n >> h;

        vector<long long> a(n+1), water(n+1), pref(n+1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            water[i] = h - a[i];
        }

        for (int i = 1; i <= n; i++)
            pref[i] = pref[i-1] + water[i];

        vector<int> L(n+1), R(n+1);
        stack<int> st;

        // nearest smaller to left
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && a[st.top()] >= a[i])
                st.pop();
            L[i] = st.empty() ? 0 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // nearest smaller to right
        for (int i = n; i >= 1; i--) {
            while (!st.empty() && a[st.top()] >= a[i])
                st.pop();
            R[i] = st.empty() ? n+1 : st.top();
            st.push(i);
        }

        vector<long long> best(n+1);

        for (int i = 1; i <= n; i++) {
            int l = L[i] + 1;
            int r = R[i] - 1;

            best[i] = pref[r] - pref[l-1];
        }

        long long ans = 0;

        for (int i = 1; i <= n; i++)
            ans = max(ans, best[i]);

        for (int i = 1; i <= n; i++)
            for (int j = i+1; j <= n; j++)
                ans = max(ans, best[i] + best[j]);

        cout << ans << "\n";
    }
}
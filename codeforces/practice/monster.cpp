#include <iostream>
#include <vector> 
#include <algorithm>
 using namespace std; 
  
using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> strength(n + 1), strikes(n + 1);
        for(int i = 1; i <= n; i++) cin >> strength[i];
        for(int i = 1; i <= n; i++) cin >> strikes[i];
        
        // Sort strengths in descending order
        sort(strength.begin() + 1, strength.end(), greater<int>());
        
        int levels_completed = 0;
        ll total_strikes = 0;
        ll max_score = 0;
        
        // Try using 'i' strongest swords
        for(int swords_used = 1; swords_used <= n; swords_used++) {
            // Can we complete more levels?
            while(levels_completed < n && 
                  total_strikes + strikes[levels_completed + 1] <= swords_used) {
                levels_completed++;
                total_strikes += strikes[levels_completed];
            }
            
            // strength[swords_used] is the weakest sword we're using
            ll current_score = (ll)strength[swords_used] * levels_completed;
            max_score = max(max_score, current_score);
        }
        
        cout << max_score << "\n";
    }
    
    return 0;
}
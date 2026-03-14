#include <iostream>
#include <vector>
using namespace std;

// 2193/D  monster game
/*
a = swords
b = monster

n swords -> once -> 1strickes
n -level = to defeat a monster  u need to choose the difficulty (a[i] > x is usable swords) and if a[i] < x
 difficulty level -> most important

score = x * level of completed

trade off

bigger x = fewer levels => fewer swrds
smaller x = more level => more swords

a = 2, 5, 3
b = 1, 2, 1

case 1 = when i have 3 swords
 2, 5, 3 = total 3 swords  x = 2

 3 - 1 (monster ) = 2 swords left
 2 (swards ) - 2 ( monster) = 0 elft
 not hit the monster we don't have swords


 case 2 when i 2 swords ( 3, 5)
x = 3
left 2 swords
2  -1 = 1 left swords

not hit the monster we don't ahve swords

score 3 * 1 = 3 ans

case 3  (5) one swords
x = 5
 1 -1 (monster ) = 0 left (swords)

 score = 5 * 1 = 5 ans (maximum score)




 */
using  ll  =long long; 
void solve () { 
int n;
    cin >> n;
    vector<long long> stength(n)  , strikes(n) ; 
    for(int i = 0 ;i < n ; i ++) cin >>stength[i] ; 
    for (int i = 0 ; i < n ; i++) cin >> strikes[i] ; 

    vector<pair<int, int>> swords ; 

    //sword = strength + original values 
    for (int i = 0; i < n ; i ++) {
swords.push_back({stength[i], i}) ; 

    }

    sort(swords.begin() , swords.end()) ; 

ll  max_score = 0 ; 
// For each possible number of levels to complete

for (int level = 1; level <= n ; level ++){
ll strikes_need = 0; 
// Calculate total strikes needed for these levels
for ( int i =  0 ; i < level  ; i++) { 
strikes_need += strikes[i] ; 

}
if ( strikes_need > n) continue; 


// Collect strengths of swords in first 'levels' positions
vector<int> strength_range ; 
for ( int i = 0 ; i < n ; i++){
if (swords[i].second < level) { 
    strength_range.push_back(swords[i].first) ; 

}

}

 // If we don't have enough swords in these positions
 if (strength_range.size() < strikes_need ) continue ; 
  /// sort in descreding order 
  sort(strength_range.begin(), strength_range.end(), greater<int>());
  // The difficulty must be at least the strikes_needed-th strongest sword
        ll difficulty = strength_range[strikes_need - 1];

max_score = max(max_score , difficulty * level ) ; 
}
cout << max_score << endl; 

}
   
 
int main()
{

   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    

    

    return 0;
}
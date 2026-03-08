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

int main()
{

    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ; 

    int n;
    cin >> n;
    vector<long long> a(n)  , b(n) ; 
    for(int i = 0 ;i < n ; i ++) cin >> a[i] ; 
    for (int i = 0 ; i < n ; i++) cin >> b[i] ; 

    long long ans = 0; 

for (int i = 0; i < n ; i++){ 
    
}
    return 0;
}
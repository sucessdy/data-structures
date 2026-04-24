#include <iostream>
#include <vector> 
#include <cmath>
using namespace std;

int  countDigits (int n ) { 
    int cnt= 0; 
while (n != 0){ 
//  int dig =    n % 10; 
 cnt++; 
n/= 10; 
}
return cnt; 
}

int Palindrome (int n ) {
int rev =0;
int dup = n; 
    while (n != 0){ 

        int num = n%10;
rev = (rev *10) + num;  
       n/=10; 

 
    }return (rev == dup ) ? 1 : 0;  

 }
 int Armstrong (int n ) {
    int num =0;
    while ( n!=0 ) { 
        int dig= n %10; 
        num += dig * dig * dig; 

        n/=10; 
 
    }
    return num; 
  }

void  printDivisor(int n ) { 
for ( int i =1 ; i < n ; i ++){ 
    if (n % i ==0) {
cout << i << endl; 
    }
}

  }
  // not optimal -> brute force 
bool  printDivisorForPefectNumber(int n ) { 
    int sum =0;
    int dup = n; 
for ( int i =1 ; i < n ; i ++){ 
    if (n % i ==0) {
sum+= i ;
    }

}
return (sum == dup )  ? true : false ; 

  }

  // optimal 

void divisor(int n ) {  
    for ( int i= 1 ; i <= n/i ; i ++){
        if (n % i ==0){ 
            cout << i  << " ";
            if (  i != n/i){ 
                cout <<n /i  << " "; 

            }
        } 
    }
  }

void divisorSortedOrder(int n ) {  /// Time complexity -> O (n logn)  
    vector<int> ls; 
    for ( int i= 1 ; i <= n/i ; i ++){
        if (n % i ==0){ 
           ls.push_back(i) ; 
            if (  i != n/i){ 
              ls.push_back(n/i) ; 

            }
        } 
    }

    sort(ls.begin(), ls.end()) ; 
    for (auto it : ls) cout << it << " " ; 
  }
   // more best soltuoiion for thisn 

   void divisorSortedOptimse(int n)  { // O(n)
vector<int> small, large; 
for ( int  i = 1; i<= n/i; i ++){ 
   if ( n % i == 0) { 
    small.push_back(i) ;
   }
   if ( i != n/i){ 
    large.push_back(n /i) ;
   }

}
for ( int i = 0; i < small.size() ; i++){ 
    cout << small[i] <<  " ";
}
for ( int i = large.size() -1 ; i >=0 ; i--){ 
    cout << large[i] << " " ; 
}

   }
   
int main() {

    int n = 36; 
 divisorSortedOptimse(n) ; 
    // cout << res << endl;
    // int number= 7; 
    // bool res = printDivisorForPefectNumber(number) ; 
    // cout << (res ? "true" : "false") << endl;
    // int n = 923 ; 
    // cout << countDigits( n ) << endl;
// int cnt = (int)(log10(n) + 1) ;

// cout << cnt << endl;

// int num = 44; 
// cout << Palindrome(num) << endl;
// if (num == Palindrome(num)){
//     cout << "Its a palindrome" << endl;
     
// }
// else { 
//     cout << "its not a palindrome" << endl; 

// }

// int num = 153 ; 
// if ( num == Armstrong(num)){
//     cout << "Its a Armstrong number"  << endl; 

// }
// else { 
//     cout <<" ITs not a Armstrong number"  << endl;
// }
// int n = 28; 
// printDivisor(n) ; 
    return 0;
}
#include <iostream>
#include <vector>
#include <list> 
using namespace std;
// stack using the veector 
class Stack{ 

  vector<int> v; 
  public : 
  void push(int val ){ v.push_back(val) ;
  }  
  void pop() { 
    v.pop_back() ;
  }
  int top() { 
    return v[v.size() -1] ; 
  }
 bool empty () { 
    return v.size() == 0; 

  }
} ; 

// stack using the linkedlist  

class List  { 
    list<int> ll; 

    public : 
    void push(int val ) {
         ll.push_front(val) ; 
    }
    void pop() {
        ll.pop_front() ;
    }
    int top(){
        return ll.front(); 
    }
    bool empty (){ 
       return ll.size() == 0 ;
    }

 } ; 
int main() {
 List ll;
    ll.push(1) ;
    ll.push(2) ;
    ll.push(3) ;
while (!ll.empty() ){
   cout <<  ll.top()  << endl;
    ll.pop() ;  

}

cout << endl; 

    return 0;
}
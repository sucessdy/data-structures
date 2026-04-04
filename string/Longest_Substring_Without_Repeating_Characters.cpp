#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//  Longest Substring Without Repeating Characters  

// better  

int longestSubtring(string s){
    int left = 0; 
    int maxLen = 0; 
    unordered_set<int> st;
    for (int right = 0;right < s.size() ; ++right){
        while (st.count(s[right])){
            st.erase(s[left]) ; 
            left++; 
        }
        st.insert(s[right]);
        maxLen = max(maxLen , right - left+1);

    }
    return maxLen; 

}

// optimal -> 256 ascii 
int longestSubtring (string s ){
    int hashValue = 256 ; 
    int n = s.length() ; 
    int hash[hashValue] ;
     
}
int main() {
    string s = "abcaa";
    cout << longestSubtring(s) << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

    string genHash(string s) {
        vector<int> freq(26, 0);
        for (char x : s) freq[x - 'a']++;

        string hash = "";
        for (int i=0; i<26; i++) {
            hash += (to_string(freq[i]) + "#");
        }

        return hash; 
    }

    bool isAnagram(string s, string t) {    
        string sHash = genHash(s);
        string tHash = genHash(t);

        return (sHash == tHash);
    }

// groups of anagrams  
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vvs;
        unordered_map<string, int> m;
        int idx = 0;
        for (string& s: strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            auto it = m.find(tmp);
            if (it == m.end()) {
                vvs.push_back({s});
                m[tmp] = idx;
                idx++;
            } else {
                vvs[it->second].push_back(s);
            }
        }

        return vvs;
    }
}; 

// my thought process   

 class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> groups ; 
       for (auto const & i : strs) { 
        string store = i;
        sort(store.begin(), store.end()) ;


        groups[store].push_back(i) ; 


       }

vector< vector<string>>  result ; 

for (auto const & pair : groups ){ 
    result.push_back(pair.second); 

}
return result; 

    }
}; 
int main() {
    
    return 0;
}
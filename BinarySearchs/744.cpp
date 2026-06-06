#include <iostream>
#include <vector>
using namespace std;


// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

// 744. Find Smallest Letter Greater Than Target  


    char nextGreatestLetter(vector<char>& letters, char target) {

        int st = 0;
        int end = letters.size() -1;

        while(st <= end){
            int mid = st+(end-st)/2;

            if(letters[mid] >= target){
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }

      return letters[st % letters.size()] ;   
    }


    int main () { 
        vector<char> letter = { 'c','f','j'} ; 
        char k = 'a' ; 

        cout << nextGreatestLetter(letter, k) << endl; 

        return 0; 
    }


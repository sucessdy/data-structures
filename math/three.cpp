#include <iostream>
#include <vector>
using namespace std;

int maximumProduct (vector<int> & nums) { 
  sort(nums.begin(), nums.end());
      int l = nums.size();
      int a = nums[l - 1], b = nums[l - 2], c = nums[l - 3], d = nums[0], e = nums[1];
      return max(a * b * c, d * e * a);

}

int maximumProductSum(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        
        for (int n : nums) {
            if (n <= min1) {
                min2 = min1;
                min1 = n;
            } else if (n <= min2) {
                min2 = n;
            }
            
            if (n >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n >= max2) {
                max3 = max2;
                max2 = n;
            } else if (n >= max3) {
                max3 = n;
            }
        }
        
        return max(min1 * min2 * max1, max1 * max2 * max3);
    } 


    int maxProductTwo(vector<int> &nums) { 

    }


int main() {
    vector<int> n = {1, 2, 3} ; 
    cout << maximumProduct(n) << endl;
    return 0;
}
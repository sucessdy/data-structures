class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        
        // Store pairs of (value, original_index)
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        
        mergeSort(arr, result, 0, n - 1);
        return result;
    }
    
    void mergeSort(vector<pair<int, int>>& arr, vector<int>& result, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        mergeSort(arr, result, left, mid);
        mergeSort(arr, result, mid + 1, right);
        merge(arr, result, left, mid, right);
    }
    
    void merge(vector<pair<int, int>>& arr, vector<int>& result, int left, int mid, int right) {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left;      // pointer for left half
        int j = mid + 1;   // pointer for right half
        int k = 0;         // pointer for temp array
        
        // Count smaller elements
        int rightCounter = 0;
        while (i <= mid && j <= right) {
            if (arr[i].first <= arr[j].first) {
                // When taking from left, add the count of elements already taken from right
                result[arr[i].second] += rightCounter;
                temp[k++] = arr[i++];
            } else {
                // Element from right is smaller
                rightCounter++;
                temp[k++] = arr[j++];
            }
        }
        
        // Handle remaining elements in left half
        while (i <= mid) {
            result[arr[i].second] += rightCounter;
            temp[k++] = arr[i++];
        }
        
        // Handle remaining elements in right half
        while (j <= right) {
            temp[k++] = arr[j++];
        }
        
        // Copy back to original array
        for (int p = 0; p < temp.size(); p++) {
            arr[left + p] = temp[p];
        }
    }
};
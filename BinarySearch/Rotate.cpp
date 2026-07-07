//
#include <iostream>
#include <vector>
using namespace std;
// / Rotote binary search

int Rotate(vector<int> &arr)
{
    int st = 0;
    int end = arr.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (mid < end && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        if (mid > st && arr[mid] < arr[mid - 1])
        {
            return mid - 1;
        }
        if (arr[mid] <= arr[st])
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return -1;
}

// int FindMin (vector<int> arr) { 
//     int min = -1; 
//     int rotate = Rotate(arr) ; 
//     if ( rotate == -1){ 
//         return BinarySearch(arr,  0, arr.size() -1) ; 
//     }
//     if ( rotate > min){
//         return BinarySearch(arr,   mid + 1l, )
//     }

// }

int BinarySearch(vector<int> arr, int target, int st, int end)
{

    while (st < end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] < target)
        {
            st = mid + 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int search(vector<int> &arr, int target)
{
    int pivot = Rotate(arr);

    if (pivot == -1)
    {
        return BinarySearch(arr, target, 0, arr.size() - 1);
    }

    if (arr[pivot] == target)
    {
        return pivot;
    }

    if (arr[0] < target && arr[pivot] >= target)
    {
        return BinarySearch(arr, target, 0, pivot);
    }
    return BinarySearch(arr, target, pivot + 1, arr.size() - 1);
}

int count (vector<int> & arr){
           
    int pivot = search(arr);
    return pivot + 1; 
}

int main()
{

     vector<int> arr = {4, 5, 6, 6, 7, 0, 1, 2};
    int pivot = count(arr);
    cout << "Pivot index: " << pivot << endl;
    cout << "Pivot value: " << arr[pivot] << endl;
    
    // Test search function
    int target = 6;
    int index = search(arr, target);
    cout << "Target " << target << " found at index: " << index << endl;
    
    target = 3;
    index = search(arr, target);
    cout << "Target " << target << " found at index: " << index << endl;
    
    return 0;
}
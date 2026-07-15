#include <iostream>
#include <vector>
using namespace std;

void merge (vector<int> &arr , int st, int mid , int end ) {
    vector<int> temp ;

    int  i=st;
    int j = mid +1;

    while ( i <= mid && j <= end)  {
        if ( arr[i] < arr[j]) {
temp.push_back(arr[i]) ;
i ++;

        }
        else {
            temp.push_back(arr[j]) ;
        j++;

        }
    }

    while ( i <= mid) {
        temp.push_back(arr[i]) ;
        i++;

    }
    while( j <= end) {
        temp.push_back(arr[j]) ;
        j++;
    }

    for (int idx = 0 ; idx  < temp.size() ; idx ++) {
       arr[idx + st] =  temp[idx] ;
    }

}
void mergeSort (vector<int> &arr,int st, int end) {
    if (st < end) {
int mid  = st  + (end - st) /2 ;
mergeSort(arr, st , mid) ;
mergeSort(arr, mid + 1 , end) ;
merge (arr, st, mid, end) ;

    }
}

// void merge(vector<int> &arr, int st, int mid, int end)
// {
//     int i = st;
//     int j = mid + 1;

//     vector<int> ans;
//     //  int k = 0;
//     while (i <= mid && j <= end)
//     {
//         if (arr[i] < arr[j])
//         {
//             ans.push_back(arr[i]);
//             i++;
//         }
//         else
//         { 
//             ans.push_back(arr[j]);
//             j++;
//         }
//     }

//     while (arr[i] <= mid)
//     {
//         ans.push_back(arr[i]);
//         i++;
//     }
//     while (arr[j] <= end)
//     {
//         ans.push_back(arr[j]);
//         j++;

//     }

//     for (int index = 0; index < ans.size(); index++)
//     {
//         arr[st + index] = ans[index];
//     }
// }

// void mergeSort(vector<int> &arr, int st, int end)
// {
//     if (st < end)
//     {
//         int mid = st + (end - st) / 2;
//         mergeSort(arr, st, mid);
//         mergeSort(arr, mid + 1, end);
//         merge(arr, st, mid, end);
//     }
// }

int main()
{
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    int st = 0;
    int end = arr.size() - 1;

    mergeSort(arr, st, end);

    for (int index = 0; index < arr.size(); index++)
    {
        cout << arr[index] << " ";
    }
    cout << endl;
    return 0;
}
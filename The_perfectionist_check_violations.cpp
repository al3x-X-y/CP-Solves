#include <bits/stdc++.h>
using namespace std;

int conquer_and_count (int arr[], int starting_index , int mid , int ending_index){
    int merged [ending_index - starting_index + 1];
    int count = 0;

    int i = starting_index, j = mid + 1, k = 0;
    while (i <= mid && j <= ending_index){
        if (arr[i] < arr[j]){
            merged[k++] = arr[i++];
        }
        else{
            merged[k++] = arr[j++];
            count += ( mid - i + 1 );
        }
    }
    while (i <= mid){
        merged[k++] = arr[i++];
    }
    while (j <= ending_index){
        merged[k++] = arr[j++];
    }
    for (int i = starting_index, k = 0; i <= ending_index; i++, k++){
        arr[i] = merged[k];
    }
    return count;
}

int divide_and_violation (int arr[], int starting_index, int ending_index){
    if  (starting_index >= ending_index){
        return 0;
    }

    int mid =  (starting_index + ending_index) / 2;
    int count = 0;
    count += divide_and_violation (arr, starting_index, mid);
    count += divide_and_violation (arr, mid + 1, ending_index);
    count += conquer_and_count (arr, starting_index, mid, ending_index);
    return count;
}

int main (){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << divide_and_violation (arr, 0, n - 1) << endl;
    return 0;
}

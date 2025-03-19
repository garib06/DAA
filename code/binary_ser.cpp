//code for binary search alogrithm
#include<iostream>

using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        
        if (arr[mid] == x)
            return mid;

        
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        
        return binarySearch(arr, mid + 1, r, x);
    }

    
    return -1;
}

int main(){
    int l,x;
    cout << "Enter the no of element in the array: ";
    cin >> l;
    int arr[l];
    for(int i = 0; i < l; i++){
        cout<<"Enter the "<<i+1<<" element: ";
        cin >> arr[i];
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Enter the element to find: ";
    cin >> x;    
    int result = binarySearch(arr, 0, n - 1, x);
    if(result == -1){
        cout << "Element is not present in array";
    }else{
        cout << "Element is present at index " << result;
    }
    return 0;  
}
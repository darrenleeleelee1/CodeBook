#include <iostream>
#include <algorithm>
using namespace std;

int key;
void quick_sort(int arr[] , int left , int right )
{
    if(right - left <= 1){
        if ( arr[left] > arr[right])swap(arr[left], arr[right]);
        return;
    }
    key = arr[left];
    int i = left;
    int j = right;

    do{
        
        do {
            i++;
        } while(arr[i] < key && i < right);
        do {
            j--;
        } while (arr[j] > key && j >= left);
        cout << "arr[i] = " << arr[i] << endl;

        if ( i >= j )break;
        //1. find larger on the left and smaller on the right. And (i < j) Then swap them
        swap(arr[i] , arr[j]);

        for (int k = left; k < right; k++){
            if (k == j || k == i) cout << ">";
            cout << arr[k] << " ";
        }
        cout << endl;
    }while(i < j);

    //2. Else  (i >= j), then swap [left](the "key") with [j], because [j] is rightest one that smaller than [left](the "key").
    //After swap, the "key"([left]) come to middle of array, left of key is all smaller than key, and right of key is all larger than key.
    swap(arr[left], arr[j]);
    
    for (int k = left; k < right; k++){
        if (k == j || k == left) cout << ">";
        cout << arr[k] << " ";
    }
    cout << "one round over" << endl << endl;
    quick_sort(arr, left , j);
    quick_sort(arr, j + 1 , right);

}

int main()
{
    //input from std
    int count = 0;
    cin >> count;
    int arr[count];
    for (int i = 0; i < count; i++)
        cin >> arr[i];

    for (int i = 0; i < count; i++)
        cout << arr[i] << " ";
    cout << endl << endl;
    //O(nlogn)
    
    quick_sort(arr, 0 , count);

    //output
    int sum = 0;
    for (int i = 0; i < count; i++){
        sum += arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << sum;
    

    

    return 0;
}

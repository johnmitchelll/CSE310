#include <iostream>

using namespace std;

void swap(int arr[], int index_1, int index_2){
    int temp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = temp;
}


void bubble_sort(int arr[], int arr_len){

    bool swapped = true;

    while(swapped == true){
        swapped = false;

        for (int index = 0; index < arr_len - 1; index++){
            if(arr[index] > arr[index + 1]){
                swap(arr, index, index+1);
                swapped = true;
            }
        }
    }
}

void printArr(int arr[], int arr_len){
    for(int index = 0; index < arr_len; index++){
        cout << arr[index] << " ";
    }

    cout << endl;
}

int main(){
    int arr_len = 0;
    cin >> arr_len;

    for (int index = 0; index < input_string; index++){
       cin >> arr[index];
    }
    
    bubble_sort(arr, arr_len);
    printArr(arr, arr_len);
}
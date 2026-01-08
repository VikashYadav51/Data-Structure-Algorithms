#include<iostream>
using namespace std;

void hepify_algo(int arr[], int index, int size){
    while(index < size){
        int leftIndex = 2*index;
        int rightIndex = 2*index + 1;
        int largest = index;

        if(leftIndex <= size && arr[index] < arr[leftIndex]){
            largest = leftIndex;
        }

        if(rightIndex <= size && arr[largest] < arr[rightIndex]){
            largest = rightIndex;
        }

        if(largest == index){
            break;
        }

        if(largest != index){
            swap(arr[largest], arr[index]);
            hepify_algo(arr, largest, size);
        }
    }

    return ;
}

void print_heap(int arr[], int size){
    for(int i = 1; i < size; i++){
        cout << arr[i]<< ",  ";
    }

    cout << endl;

    return ;
}


void sort_heap(int arr[], int size){
    int index = size - 1;

    while(index > 0){
        swap(arr[1], arr[index]);
        index--;
        hepify_algo(arr, 1, index);
    }

    return ;
}



int main(){
    int arr[] = {-1, 7, 10, 4, 3, 20, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    int index = size / 2;

    while(index > 0){
        hepify_algo(arr, index, size);
        index--;
    }

    cout <<"Print the maxi heap before sorting "<< endl;
    print_heap(arr, size);
    cout << endl;

    sort_heap(arr, size);

    cout <<"Print the maxi heap after sorting "<< endl;
    print_heap(arr, size);

    int k;
    cout <<"Enter the value of k "<< endl;
    cin>> k;

    if(k > size){
        cout <<"No element is persent in the array "<< endl;
    }

    cout << "First smallest elememt "<< arr[k]<< endl;
}
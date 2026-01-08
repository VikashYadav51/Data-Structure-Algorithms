#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int element){
        size = size + 1;
        arr[size] = element;

        int index = size;

        while(index > 1){
            int parent = index  / 2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = index / 2;
            }

            else {
                return ;
            }
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << ",  ";
        }
        cout << endl;
    }

    void delete_element(){
        arr[1] = arr[size];
        size--;

        int index  = 1;

        while(index < size){
            int leftIndex = 2 *index;
            int rightIndex = 2 * index + 1;
            int largest = index;

            if(leftIndex <= size && arr[index] < arr[leftIndex]){
                largest = leftIndex;
            }

            if(rightIndex <= size && arr[largest] < arr[rightIndex]){
                largest = rightIndex;
            }

            if(largest != index){
                swap(arr[index], arr[largest]);
                index = largest;
            }

            else{
                break;
            }
        }
    }
};

int main(){
    heap h1;
    h1.insert(55);
    h1.insert(53);
    h1.insert(54);
    h1.insert(52);
    h1.insert(50);
    h1.insert(51);
    h1.insert(52);

    cout <<"Print the heap data "<< endl;
    h1.print();

    h1.delete_element();
    h1.print();
}
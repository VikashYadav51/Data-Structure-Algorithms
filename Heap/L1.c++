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
};

int main(){
    heap h1;
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);
    // h1.insert(40);
    // h1.insert(45);

    cout <<"Print the heap data "<< endl;
    h1.print();
}
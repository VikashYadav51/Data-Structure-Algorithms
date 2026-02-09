#include<iostream>
#include<vector>

using namespace std;

int findKRotation(vector<int> &arr) {
    int k = 0;
    
    int size = arr.size();
    
    int mini = INT32_MAX;
    
    for(int i = 0; i < size; i++){
        if(arr[i] < mini){
            mini = arr[i];
        }
    }
    
    for(int i = 0; i < size; i++){
        if(mini == arr[i]){
            return i;
        }
    }
    
    return 0;
    
    
}

int main(){

}
#include<iostream>
#include<map>

using namespace std;

int main(){
    map<int, int> mapping;

    mapping[1] = 10;
    mapping[2] = 20;
    mapping[3] = 5;

    mapping[5] = 4;

    mapping[6] = 5;

    mapping.emplace(6,55);

    int count = 0;

    for(int i = 1; i < 7; i++){
        if(mapping[i] < 7){
            cout <<  i << ",  "<< mapping[i] << endl;
            count++;
        }
    }
    
    cout << count;
}
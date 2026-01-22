#include<iostream>
using namespace std;

int main(){
    int n;
    cout <<"Enter the value of n "<< endl;
    cin >> n;

    int ans = 0;
    int i = 1;

    while(n != 0){
        int bits = n % 2;
        ans = bits * i + ans;
        i = i * 10;
        n = n / 2;
    }

    cout << "Binary number of n "<< ans << endl;
}
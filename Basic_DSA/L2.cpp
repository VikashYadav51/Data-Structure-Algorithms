#include<iostream>
using namespace std;

int main(){
    // int n;
    // cout <<"Enter the value of n "<< endl;
    // cin >> n;

    // int ans = 0;
    // int i = 1;

    // while(n != 0){
    //     int bits = n % 2;
    //     ans = bits * i + ans;
    //     i = i * 10;
    //     n = n / 2;
    // }

    // cout << "Binary number of n "<< ans << endl;


    // int n;
    // cout <<"Enter the value of n "<< endl;
    // cin >> n;

    // int i = 1;
    // int ans = 0;

    // while(n != 0){
    //     int bits = n % 10;
    //     ans = ans + bits * i;
    //     i = i*2;
    //     n = n  / 10;
    // }

    // cout <<"Decimal number is "<< ans << endl;

    int n;
    cout <<"Enter the value of n "<< endl;
    cin >> n;

    switch(n){
        case 3:{
            cout <<"You are not allowed for the addmission "<< endl;
        }

        case 6:{
            cout <<"You are allowed for the addmision of less than 1 class "<< endl;
            break;
        }

        case 10:{
            cout << "Eligibles for less than 5 "<< endl;
            break;
        }

        case 15:{
            cout <<"Eligibles for less than 10 class "<< endl;
            break;
        }

        case 18 :{
            cout <<"Eligibles for less than 12 class "<< endl;
            break;
        }

        case 20:{
            cout <<"Eligibles for everywhere "<< endl;
            break;
        }

        default:{
            cout <<"Enter a valid ages.."<< endl;
        }
    }
}
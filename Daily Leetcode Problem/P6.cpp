#include<iostream>
#include<algorithm>

using namespace std;

void reverse(string &s1){
    reverse(s1.begin(), s1.end());

    int start = 0;
    int end = 0;

    for(int i = 0; i < s1.length(); i++){
        if(s1[i] != ' '){
            end++;
        }

        else{
            // while(s1[start] == ' '){
                start++;
            // }

            while(start < end){
                swap(s1[start++], s1[end]);
                start++;
                end--;
            }

            start = i;
            end = i;
        }
    }

    return ;
}

int main(){
    string s1 = "Hello world ";
    reverse(s1);
    cout << s1 << endl;
}
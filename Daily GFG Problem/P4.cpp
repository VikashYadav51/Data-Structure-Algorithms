#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool check(vector<int> arr, int k, int mid){
    int time = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] <= mid){
            time++;
        }
        
        else{
            int t1 = arr[i] % mid;
            time = time + (arr[i] / mid);
            if(t1 > 0){
                time++;
            }
        }
    }
    
    if(time <= k){
        return true;
    }
    
    return false;
    
}

int kokoEat(vector<int>& arr, int k) {
    int size = arr.size();
    
    int low = 1;
    
    int high = *max_element(arr.begin(), arr.end());
    
    int res = high;
    
    while(low <= high){
        int mid = low + (high - low) / 2;
        
        if(check(arr, k, mid)){
            res = mid;
            high = mid - 1;
        }
        
        else{
            low = mid + 1;
        }
    }
    
    return res ;
    
}

int main(){

}

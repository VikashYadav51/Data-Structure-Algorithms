#include<iostream>
#include<vector>

using namespace std;

// Divide an Array Into Subarrays With Minimum Cost I

int minimumCost(vector<int>& nums) {
    int size = nums.size();

    int cost1 = nums[0];
    int cost2 = nums[1];
    int cost3 = nums[2];

    int index = 1;

    for(int i = 3; i < size; i++){
        if(nums[i] < cost2){
            index = i;
            cost2 = nums[i];
        }
    }

    for(int i = 1; i < size; i++){
        if(index != i && nums[i] < cost3){
            cost3 = nums[i];
        }
    }

    int cost = cost1 + cost2 + cost3;

    return cost;
}

int main(){

}
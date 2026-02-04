#include<iostream>
#include<vector>

using namespace std;

long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long res = INT32_MIN;
        int i = 1;
        while(i<n)
        {
            long long curr = 0;
            while(i<n && nums[i]<=nums[i-1]) i++; // skipping unwanted
            if(i>=n) continue;
            while(i<n && nums[i]>nums[i-1]) // increase part 1
            {
                while(i<n && nums[i]>nums[i-1] && nums[i]<=0)i++; // finding 1st +Ve
                if(i>=n)break;
                if(nums[i]>nums[i-1])
                {
                    if(nums[i-1]>0)curr+=nums[i-1];
                    while(i<n && nums[i]>nums[i-1]) curr+=nums[i++];
                    if(i>=n)break;
                }
                else curr+=nums[i-1]+nums[i-2]; // no +ve
            }
            if(i>=n)continue;
            if(nums[i-1]>0 && nums[i-2]<=0) curr=nums[i-1]+nums[i-2]; // 1 +ve case
            if(nums[i]==nums[i-1])continue; // invalid trionic subarray
            while(i<n && nums[i]<nums[i-1]) // decrease part 2
            {
                curr+=nums[i];
                i++;
            }
            if(i>=n)continue;
            if(nums[i]==nums[i-1])continue; // invalid trionic subarray
            int st = i;
            long long tempmax = INT32_MIN, tempcurr = 0;
            while(i<n && nums[i]>nums[i-1])
            {
                tempcurr += nums[i];
                tempmax = max(tempmax,tempcurr);
                i++;
            }
            curr+=tempmax;
            i=st; // start from start of previous trionic subarray's end
            res = max(curr,res);
        }
        return res;
    }

int main(){

}
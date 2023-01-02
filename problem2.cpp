//https://leetcode.com/problems/maximum-subarray/submissions/869404103/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0,fl=0,maxiSum = nums[0];
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>0) {
                fl=1;
            }
        }
        if(fl==0) {
            for(int i=0;i<nums.size();i++) {
                if(maxiSum<nums[i]) {
                    maxiSum = nums[i];
                }
            }
            if(maxiSum<0) {
                return maxiSum;
            }
        }
        
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            if(sum<0) {
                sum = 0;
            }
            if(sum>maxiSum) {
                maxiSum = sum;
            }
        }
        return maxiSum;
    }
};

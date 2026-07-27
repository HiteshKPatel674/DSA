class Solution {
    int solve(vector<int>&nums,int target,int initial_sum,int index)
    {   
        //if(index>=nums.size()) return 0;

        if(index==nums.size() && initial_sum==target)
        {
            return 1;
        }

        if(index==nums.size() && initial_sum!=target)
        {
            return 0;
        }
        
        int add=solve(nums,target,initial_sum+nums[index],index+1);
        int sub=solve(nums,target,initial_sum-nums[index],index+1);

        return  add+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

  
        int ans=solve(nums,target,0,0);
        return ans;
        
    }
};
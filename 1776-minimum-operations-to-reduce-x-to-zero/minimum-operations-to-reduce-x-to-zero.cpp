class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int total=accumulate(nums.begin(),nums.end(),0);
        int sum=total-x;
        int n=nums.size();


        if(sum==0) return n;
       
        int len=-1;
        int left=0;
        int s=0;

        for(int right=0;right<nums.size();right++)
        {   
            s+=nums[right];
            while(s>sum && left<right)
            {
                s=s-nums[left];
                left++;
            }

           if(s == sum) len = max(len, right-left+1);
        }

        if(len==-1) return -1;

        return n-len;
        
    }
};
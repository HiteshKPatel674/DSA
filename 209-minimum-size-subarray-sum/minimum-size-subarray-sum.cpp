class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left=0;
        int right=0;
        int n=nums.size();
        int sum=nums[left];
        int min_size=INT_MAX;

        while( left<n && right<n)
        {
            if( right+1<n && sum<target)
            {
                right++;
                sum+=nums[right];
            } 

            else if(sum>=target) 
            {   
                min_size=min(min_size,right-left+1);
                sum-=nums[left];
                left++;
            }
            else break;
            

        }  

        return min_size==INT_MAX ? 0: min_size;      
    }
};
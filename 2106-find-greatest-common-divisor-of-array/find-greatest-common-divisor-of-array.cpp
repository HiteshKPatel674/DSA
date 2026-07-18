class Solution {
public:
    int findGCD(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int n=nums[0];
        int m=nums[nums.size()-1];
        
        int greatest=-1;
        for(int i=1;i<=m;i++)
        {
            if(n%i==0 && m%i==0) greatest=i;
        }  

        return greatest;      
    }
};
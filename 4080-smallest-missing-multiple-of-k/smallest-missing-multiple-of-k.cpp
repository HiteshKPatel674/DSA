class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        set<int>s(nums.begin(),nums.end());
        int ans=-1;

        for(int i=1;i<102;i++)
        {   
            int mul=k*i;
            if(s.find(mul)==s.end())
            {
                ans=mul;
                break;
            }
        }

        return ans;
        
    }
};
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int n=nums.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        set<int>s;

        for(int i=0;i<n;i++)
        {   
            s.insert(nums[i]);
            if(nums[i]>maxi) maxi=nums[i];
            if(nums[i]<mini) mini=nums[i];
           
        }

        vector<int>miss;
        for(int i=mini;i<=maxi;i++)
        {
            if(s.find(i)==s.end()) miss.push_back(i);
        }

        sort(miss.begin(),miss.end());

        return miss;


        
        
    }
};
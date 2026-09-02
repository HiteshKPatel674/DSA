class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int even=0;
        int odd=0;
        int n=nums1.size();

        for(int i=0;i<n;i++)
        {
            if(nums1[i]%2==0) even++;
            else odd++;

        }

        if(even==n || odd==n) return true;

        if(odd>0) return true;
        return false;

        
    }
};
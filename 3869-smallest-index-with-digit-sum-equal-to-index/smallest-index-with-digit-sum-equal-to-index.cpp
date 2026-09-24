class Solution {
private:
 int sum(int n)
    {
        int x=n;
        int total=0;
        while(x>0)
        {
            int rem=x%10;
            total+=rem;
            x=x/10;
        }
        
        return total;
    }
public:
    int smallestIndex(vector<int>& nums) {
        
        int smallest=-1;
        
        for(int i=0;i<nums.size();i++)
        {
             if(sum(nums[i])==i)
             {
             smallest=i;
            return smallest; 
             }
        }
        return smallest;
        
    }
};
class Solution {
int findgcd(int n, int m)
{
    if(m == 0) return n;
    return findgcd(m, n % m);
}
public:
    long long gcdSum(vector<int>& nums) {

        vector<int>prefixgcd;

        int max=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>max) max=nums[i];
            long long gcd=findgcd(nums[i],max);
            prefixgcd.push_back(gcd);
        }

        sort(prefixgcd.begin(),prefixgcd.end());

        int len=prefixgcd.size();
        long long sum=0;
        for(int i=0;i<len/2;i++)
        {
            sum+=findgcd(prefixgcd[i],prefixgcd[len-i-1]);
        }

        return sum;

        
    }
};
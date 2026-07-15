class Solution {
int gcd(int n,int m)
{
    if(n<m) gcd(m,n);
    if(n==1 || m==1) return 1;
    return (m,n%m);
}
public:
    int gcdOfOddEvenSums(int n) {

        int sum_even=0;
        // int itr1=0,itr2=0;
        // for(int i=2;itr1<n ;i=i+2)
        // {
        //     sum_even+=i;
        //     itr1++;
        // }

        int sum_odd=0;
        // for(int i=1;itr2<n ;i=i+2)
        // {
        //     sum_odd+=i;
        //     itr2++;
        // }

        sum_even=(1+n)*n;
        sum_odd=n*n;

        int ans=gcd(sum_even,sum_odd);
        return ans;
        
    }
};
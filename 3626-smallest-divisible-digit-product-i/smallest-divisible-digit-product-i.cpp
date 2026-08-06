class Solution {
public:
    int smallestNumber(int n, int t) {

        int ans;
        for(int i=0;i<10;i++)
        {
            int product=1;
            int number=n+i;
            int num=number;
            while(number)
            {
                int digit=number%10;
                product*=digit;
                number=number/10;
            }

            if(product%t==0)
            {
                ans=num;
                break;
            }
        }
        return ans;
        
    }
};
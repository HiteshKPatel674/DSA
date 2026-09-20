class Solution {
public:
    int reverseDegree(string s) {

        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            int t='z'-s[i] + 1;
            sum+=t*(i+1);
        }

        return sum;
        
    }
};
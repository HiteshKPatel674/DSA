class Solution {
public:
    int numberOfSubstrings(string s) {

        int result=0;
        int n=s.size();

        vector<int>mp(3,0);//0->a,1->b,2->c
        int i=0;
        int j=0;
        while(j<n)
        {
            char ch =s[j];
            mp[ch-'a']++;

            while(mp[0]>0 && mp[1]>0 &&mp[2]>0)//getting a vlid window
            {
                result+=(n-j);//all the possible substring
                mp[s[i]-'a']--;//ith index mein jo bhi character uska frequency decrease by 1
                i++;//incrementing the vlaue of i
            }
            j++;
        }
        return result;


        
    }
};
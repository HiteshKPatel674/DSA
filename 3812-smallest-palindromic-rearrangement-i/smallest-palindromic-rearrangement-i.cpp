class Solution {
public:
    string smallestPalindrome(string s) {
        
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++)
        {
            int idx=static_cast<int>(s[i])-97;//char to ascii
            freq[idx]++;
        }

        string left;
        for(int i=0;i<26;i++)
        {
            while(freq[i]/2!=0)
            {
                char ch=char(97+i);
                left.push_back(ch);
                freq[i]=freq[i]-2;
            }
        }


        string middle;
        if(s.size()%2!=0)
        {
            for(int i=0;i<26;i++)
            {
                if(freq[i]==1)
                {
                    middle.push_back(char(97+i));
                }
            }
        }

        string right=left;
        reverse(right.begin(),right.end());

        string ans=left+middle+right;
        return ans;
    }
};
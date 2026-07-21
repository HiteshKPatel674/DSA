class Solution {
public:
    bool isPalindrome(string s) {

        int n=s.size();
        string str;
        for(int i=0;i<n;i++)
        {
            if(isalnum(s[i])) str.push_back(tolower(s[i]));
        }
        
        string ori=str;
        reverse(str.begin(),str.end());

        return ori==str;
    }
};
class Solution {
public:
    bool isSubsequence(string s, string t) {

        int i=s.size()-1,j=t.size()-1;

        while(i>=0 && j>=0)
        {
            if(s[i]==t[j])
            {
                s.pop_back();
                t.pop_back();
                i--;
            }
            j--;
            
        }

        return s.size()==0? true:false;
        
    }
};
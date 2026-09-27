class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string,string>mp;

        string temp;

        for(auto it:knowledge)
        {
            string key=it[0];
            string val=it[1];

            mp[key]=val;
        }

        int ptr=0;
        stack<int>st;

        while(ptr!=s.size())
        {
            if(s[ptr]=='(' || s[ptr]==')') st.push(ptr);

            if(st.empty())
            {
                temp+=s[ptr];
            }

            if(st.size()==2)
            {   
                int j=st.top();
                st.pop();
                int i=st.top();
                st.pop();
                string sub=s.substr(i+1,j-i-1);

                if(mp.find(sub)!=mp.end())
                {
                    //s.erase(i,j);
                    string val=mp[sub];
                    temp+=mp[sub];
                    //s.append(val,i,val.size());
                }
                else
                {
                    //s.earse(i,j);
                    temp+='?';
                    //s.append('?',1);
                }

            }

            

            ptr++;
        }

        return temp;

        
    }
};
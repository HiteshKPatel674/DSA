class Solution {
public:
    string reverseParentheses(string s) {

        stack<char>st;
      
       for(int i=0;i<s.size();i++)
       {
        if(s[i]==')')
        {     string str;
            while(st.top()!='(')
            {   
                char ch=st.top();
                str.push_back(ch);
                st.pop();
            }
            st.pop();//popping open bracket

            for (char c : str) //pushing back the reversed string
            {
                st.push(c);
            }
        }
        else
        {
            st.push(s[i]);
        }
    }
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
       
    return result;
    }
};
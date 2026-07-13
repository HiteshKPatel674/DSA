class Solution {
public:
    int calPoints(vector<string>& operations) {
         stack<int>st;

        for(int i=0;i<operations.size();i++)
        {
           if (operations[i] == "C") {
                if (!st.empty()) {
                    st.pop();
                }
           }
            else if(operations[i]=="D")
            {
                int x=2*st.top();
                st.push(x);
            }
            else if(operations[i]=="+")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.push(x);
                st.push(x+y);
            }
            else
            {
                st.push(stoi(operations[i]));//string to integer
            }
        }
        int sum=0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();     
        }
        return sum;
    }

};
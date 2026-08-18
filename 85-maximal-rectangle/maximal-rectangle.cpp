class Solution {
private:
vector<int>next_smaller(vector<int>&heights,int n)
{
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);

    for(int i=n-1;i>=0;i--)
    {   
        int curr=heights[i];
        while(s.top()!=-1 && heights[s.top()]>=curr)
        {
            s.pop();
        }
        ans[i]=s.top();//Giving the index of next smaller element of curr
        s.push(i);//Inserting the index of the next smaller element
    }

    return ans;
}

vector<int>prev_smaller(vector<int>&heights,int n)
{
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);

    for(int i=0;i<n;i++)
    {   
        int curr=heights[i];
        while(s.top()!=-1 && heights[s.top()]>=curr)
        {
            s.pop();
        }
        //ans is in the top of stack
        ans[i]=s.top();
        s.push(i);//Inserting the index of the prev smaller element
    }

    return ans;
}


int largest_area_rectangle(vector<int>curr_heights)
{
    vector<int>next;
    next=next_smaller(curr_heights,curr_heights.size());

    vector<int>prev;
    prev=prev_smaller(curr_heights,curr_heights.size());

    int max_area=INT_MIN;

    for(int i=0;i<curr_heights.size();i++)
    {
        int len=curr_heights[i];

        if(next[i]==-1) next[i]=curr_heights.size();

        int base=next[i]-prev[i]-1;

        max_area=max(max_area,len*base);
    }
    return max_area;
}
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        vector<int>col(matrix[0].size(),0);
        int max_area=INT_MIN;

        for(auto row:matrix)
        {
            for(int i=0;i<matrix[0].size();i++)
            {
                if(row[i]=='1') col[i]++;
                else col[i]=0;
            }

            int area=largest_area_rectangle(col);
            max_area=max(max_area,area);

        }

        return max_area;
        
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({grid[0][0],0,0});//Maximumelelevation,row,column

        vector<vector<int>>visited(n,vector<int>(m,0));

        int mini=INT_MAX;
        while(!pq.empty())
        {
            auto [elevation,row,col]=pq.top();
            pq.pop();

            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};

            if(row==n-1 && col==m-1) mini=min(mini,elevation);

            for(int i=0;i<4;i++)
            {
                int nx=row+dr[i];
                int ny=col+dc[i];
                
                if(nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0)
                {
                    int maxi=max(elevation,grid[nx][ny]);
                    pq.push({maxi,nx,ny});//pushing maximum elevation encounterred so far
                    visited[nx][ny]=1;
                }
            }

        }

        return mini;
        
    }
};
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;

        vector<vector<int>>d(n,vector<int>(m,-1));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && (i==n-1 || j==m-1 || i==0 || j==0))
                {
                    q.push({i,j});
                    grid[i][j]=2;
                }
            }
        }
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto[x,y]=q.front();
                grid[x][y]=2;//denoted that from that cell we can walk towards boundary
                visited[x][y]=1;
                q.pop();

                for(int i=0;i<4;i++)
                {
                    int nx=x+dr[i];
                    int ny=y+dc[i];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0 && grid[nx][ny]==1)
                    {
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        visited[nx][ny]=1;
                    }
                }

            }
        }

        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) count++;
            }
        }

        return count;

        
    }
};
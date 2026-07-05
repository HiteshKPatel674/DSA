class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;

        vector<vector<int>>d(n,vector<int>(m,-1));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    d[i][j]=0;
                }
            }
        }

        int distance=1;

        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto[x,y]=q.front();
                visited[x][y]=1;
                q.pop();

                for(int i=0;i<4;i++)
                {
                    int nx=x+dr[i];
                    int ny=y+dc[i];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0 && d[nx][ny]==-1)
                    {
                        d[nx][ny]=distance;
                        q.push({nx,ny});
                        visited[nx][ny]=1;
                    }
                }

            }
            distance++;
        }

        return d;
        
    }
};
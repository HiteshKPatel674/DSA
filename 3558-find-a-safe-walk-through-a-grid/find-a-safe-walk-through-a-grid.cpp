class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n=grid.size();
        int m=grid[0].size();
        queue<tuple<int,int,int>>q;

        int starth = health - grid[0][0];
        if(starth <= 0) return false;

        q.push({0,0,starth});

        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};

        vector<vector<int>> best_health(n, vector<int>(m, -1));
        best_health[0][0]=starth;

        while(!q.empty())
        {   
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                auto[x,y,z]=q.front();
                q.pop();

                if(x==n-1 && y==m-1) return true;//destination

                for(int i=0;i<4;i++)
                {
                    int nx=x+dr[i];
                    int ny=y+dc[i];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && z>0)
                    {   
                        int nz=z-grid[nx][ny];
                        if(nz<=0) continue;

                        if(nz > best_health[nx][ny])//Comparing with neighbours to move towards neighbour
                        {   
                            best_health[nx][ny] = nz;
                            q.push({nx,ny,nz});
                        }
                    
                    }
                }
            
            }

        }
        return false;
        
    }
};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        int initialColor = image[sr][sc];
        
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};

        q.push({sr,sc});
        image[sr][sc]=color;

        while(!q.empty())
        {
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                auto [x,y]=q.front();
                q.pop();

                for(int i=0;i<4;i++)
                {
                    int nx=x+dr[i];
                    int nc=y+dc[i];

                    if(nx<n && nx>=0 && nc<m && nc>=0 && visited[nx][nc]==0 && image[nx][nc]==initialColor)
                    {
                        visited[nx][nc]=1;
                        q.push({nx,nc});
                        image[nx][nc]=color;
                    }
                }
            }
        }

        return image;
        
    }
};
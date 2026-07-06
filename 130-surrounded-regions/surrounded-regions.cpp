class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;

        vector<vector<int>>d(n,vector<int>(m,-1));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && (i==n-1 || j==m-1 || i==0 || j==0))
                {
                    q.push({i,j});
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
                board[x][y]='S';//S->safe
                visited[x][y]=1;
                q.pop();

                for(int i=0;i<4;i++)
                {
                    int nx=x+dr[i];
                    int ny=y+dc[i];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0 && board[nx][ny]=='O')
                    {
                        board[nx][ny]='S';
                        q.push({nx,ny});
                        visited[nx][ny]=1;
                    }
                }

            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                board[i][j]='X';

                else if(board[i][j]=='S')
                board[i][j]='O';
            }
        }




        
    }
};
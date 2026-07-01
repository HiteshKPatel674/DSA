class Solution {
private:
bool solve(vector<vector<int>>&distance,int X)
{   
    int n=distance.size();
    if(distance[0][0]<X) return false;

    queue<pair<int,int>>q;
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    q.push({0,0});
    visited[0][0]=true;

    int dr[]={1,-1,0,0};
    int dc[]={0,0,1,-1};   

    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            auto front=q.front();
            int x=front.first;
            int y=front.second;

            q.pop();

            if(x==n-1 && y==n-1) return true;//destination

            for(int i=0;i<4;i++)
            {
                int nx=x+dr[i];
                int ny=y+dc[i];

                if(nx>=0 && nx<n && ny>=0 && ny<n && visited[nx][ny]==false && distance[nx][ny]>=X)
                {
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }
        }
    } 

    return false;
}
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int r=grid.size();
        int c=grid[0].size();

        queue<pair<int,int>>thief;
        vector<vector<int>>distance(r,vector<int>(c,-1));
        //initializing the distance vector with -1 marking as not visited.

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    thief.push({i,j});
                    distance[i][j]=0;//Initilaizig the thief distnace 0
                }
            }
        }

        int d=1;
        while(!thief.empty())
        {   //for the thieves in the queue..
            int size=thief.size();
            for(int i=0;i<size;i++)
            {   
                auto front=thief.front();
                thief.pop();//Removing the processed element
                int x=front.first;
                int y=front.second;

                //Neighbours of thief and not visited one
                if(y-1 >= 0 && distance[x][y-1] == -1)
                {
                    distance[x][y-1] = d;
                    thief.push({x, y-1});
                }
                if(y+1<c && distance[x][y+1] == -1)
                {
                    distance[x][y+1] = d;
                    thief.push({x, y+1});
                }

                if(x-1>=0 && distance[x-1][y] == -1)
                {
                    distance[x-1][y] = d;
                    thief.push({x-1, y});
                }

                if(x+1<r && distance[x+1][y] == -1)
                {
                    distance[x+1][y] = d;
                    thief.push({x+1, y});
                }
            }
            d++;
        }
        
        //Possible value of X
        int low=0;
        int high=0;

        int ans=0;
        for(auto &row:distance)
        {
            for(int x:row)
                high=max(high,x);
        }

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(solve(distance,mid))
            {   
                ans=mid;
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return ans;
    }

     
};
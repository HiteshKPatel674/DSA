// class Solution{
// bool winner(vector<int>&piles,int i,int j,int alice,int bob,int turn)
// {
//     if(i>j) return alice>bob;

//     if(turn)//Alice turn
//     {
//         bool first=winner(piles,i+1,j,alice+piles[i],bob,0);
//         bool last =winner(piles,i,j-1,alice+piles[j],bob,0);
//         return first || last;
//     }
//     else
//     {
//         bool first=winner(piles,i+1,j,alice,bob+piles[i],1);
//         bool last =winner(piles,i,j-1,alice,bob+piles[j],1);
//         return first && last;
//     }

//     return false;


// }
// public:
//     bool stoneGame(vector<int>& piles) {

//         return winner(piles,0,piles.size()-1,0,0,1);
        
//     }
// };

class Solution {
    int winner(vector<int>& piles, int i, int j, int turn,
               vector<vector<vector<int>>>& dp)
    {
        if(i > j)
            return 0;

        if(dp[i][j][turn] != -1)
            return dp[i][j][turn];

        if(turn) { // Alice's turn
            int first = piles[i] + winner(piles, i + 1, j, 0, dp);
            int last  = piles[j] + winner(piles, i, j - 1, 0, dp);

            return dp[i][j][turn] = max(first, last);
        }
        else { // Bob's turn
            int first = -piles[i] + winner(piles, i + 1, j, 1, dp);
            int last  = -piles[j] + winner(piles, i, j - 1, 1, dp);

            return dp[i][j][turn] = min(first, last);
        }
    }

public:
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2, -1)));

        return winner(piles, 0, n - 1, 1, dp) > 0;
    }
};
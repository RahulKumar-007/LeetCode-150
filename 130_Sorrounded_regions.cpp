/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
Example 2:

Input: board = [["X"]]
Output: [["X"]]

*/

class Solution {
public:
    void change(vector<vector<char>>& board , int i , int j)
    {
        board[i][j]='T';
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};

        for(int x=0;x<4;x++)
        {
            int cx=i+dx[x];
            int cy=j+dy[x];

            if(cx>=0 && cx<board.size() && cy>=0 && cy<board[0].size() && board[cx][cy]=='O')
            {
                change(board,cx,cy);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0 || i==0 || i==m-1 || j==n-1)
                {
                    if(board[i][j] == 'O') {
                        change(board ,i,j);
                    }
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }

        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='T')
                {
                    board[i][j]='O';
                }
            }
        }

    }
};

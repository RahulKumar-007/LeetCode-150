/*
 


   Given an m x n matrix, return all elements of the matrix in spiral order.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


*/

class Solution {
public:
   vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int rr[] = {0, 1, 0, -1};
    int cc[] = {1, 0, -1, 0};
    int row = 0;
    int col = 0;

    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<int> ans;
    visited[0][0] = 1;
    ans.push_back(matrix[0][0]);

    int index = 0;
    int count = 1;

    while (count < m * n)
    {
        int r = row + rr[index];
        int c = col + cc[index];

        if (r < n and c < m and r >= 0 and c >= 0 and !visited[r][c])
        {
            count++;
            ans.push_back(matrix[r][c]);
            visited[r][c] = 1;
            row = r;
            col = c;
        }
        else
        {
            index = (index + 1) % 4;
        }
    }
    return ans;
}
};

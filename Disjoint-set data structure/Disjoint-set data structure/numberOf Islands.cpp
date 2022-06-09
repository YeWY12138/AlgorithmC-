//题目200：岛屿数量
// leetcode 代码
// https://leetcode.cn/problems/number-of-islands/
/*-------------------------------------------------------------------------------
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1

输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
-------------------------------------------------------------------*/


// class Solution {
// public:
//     int n, m;

//     vector<int> parent;
    
//     void init(int n) {
//         fa = vector<int>(n);
//         for (int i = 0; i < n; i ++) {
//             parent[i] = i;
//         }
//     }

//     int get(int x) {
//         return x == parent[x] ? x : parent[x] = get(parent[x]);
//     }

//     void merge(int x, int y) {
//         parent[get(x)] = get(y);
//     }

//     int reflect(int x, int y) {
//         return x * m + y;
//     }

//     int numIslands(vector<vector<char>>& grid) {
//         if (grid.empty()) return 0;
//         n = grid.size(), m = grid[0].size();

//         init(n * m);

//         for (int i = 0 ; i < n; i ++) {
//             for (int j = 0; j < m; j ++) {
//                 if (grid[i][j] == '0') continue;
//                 if (i && grid[i - 1][j] == '1') merge(reflect(i, j), reflect(i - 1, j));
//                 if (j && grid[i][j - 1] == '1') merge(reflect(i, j), reflect(i, j - 1));
//             }
//         }

//         int ans = 0;
//         for (int i = 0; i < n; i ++) {
//             for (int j = 0; j < m; j ++) {
//                 if (grid[i][j] == '0') continue;
//                 else if (parent[reflect(i, j)] == reflect(i, j)) {
//                     ans ++;
//                 }
//             }
//         }
//         return ans;
//     }
// };
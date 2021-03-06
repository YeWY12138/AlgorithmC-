//题目：990 等式方程的可满足性
/*----------------------------------------------题目描述----------------------------------------------------------------------
给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。
在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。

输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。

输入：["b==a","a==b"]
输出：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。

输入：["a==b","b==c","a==c"]
输出：true
----------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------题目思路----------------------------------------------------------------------
并查集：先根据 == 关系构建并查集， 再根据 ！= 判断是否存在冲突
----------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------代码-------------------------------------------------------------------------
class Solution {
public:
    vector<int> parent;
    void init(vector<int> &parent, vector<string>& equations){
        parent = vector<int>(26,-1);
        for(int i = 0; i < equations.size(); i++){
            parent[equations[i][0] - 'a'] = equations[i][0] - 'a';
            parent[equations[i][3] - 'a'] = equations[i][3] - 'a';
        }
    }

    int find(int x){
        return x == parent[x] ? x : find(parent[x]);
    }

    void Union(int x, int y, vector<int> &parent){
        parent[find(x)] = find(y);
    }

    bool equationsPossible(vector<string>& equations) {
        init(parent, equations);
        for(int i = 0; i < equations.size(); i++){
            if(equations[i][1] == '='){
                    Union(equations[i][0] - 'a', equations[i][3] - 'a', parent);
            }            
        }
        

        for(int i = 0; i < equations.size(); i++){
            if(equations[i][1] == '!'){
                if(find(equations[i][0] - 'a') == find(equations[i][3] - 'a'))
                return false;
            }
        }

        return true;;
    }
};
-------------------------------------------------------------------------------------------------------------*/
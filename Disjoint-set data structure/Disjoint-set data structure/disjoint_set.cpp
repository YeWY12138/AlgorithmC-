#include <iostream>
#include <vector>

class DisjSet{
private: 
    std::vector<int> parent;
    std::vector<int> rank;
public:
    //初始化
    DisjSet(int max_size) : parent(std::vector<int>(max_size)), rank(std::vector<int>(max_size)){
        for(int i = 0; i < max_size; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    ~DisjSet(){
        parent.clear();
    }
    //查找
    int find(int x){
        return parent[x] == x ? x : find(parent[x]);
    }
    //合并
    void to_union(int x1, int x2){
        parent[find(x1)] == parent[x2];
    }
    //判断两个元素是否属于同一个集合
    bool is_same(int e1, int e2){
        return find(e1) == find(e2);
    }

    //路径压缩
    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    //按秩合并
    void to_union(int x1, int x2){
        int rank1 = find(x1), rank2 = find(x2);
        if(rank[rank1] != rank[rank2]){
            if(rank[rank1] <= rank[rank2]) parent[rank2] = rank1;
            else parent[rank1] = rank2;
            if(rank[rank1] == rank[rank2]) rank[rank1]++;
        }
    }
    

};

#include <iostream>
#include <vector>

class DisjSet{
private: 
    std::vector<int> parent;
public:
    //初始化
    DisjSet(int max_size) : parent(std::vector<int>(max_size)){
        for(int i = 0; i < max_size; i++){
            parent[i] = i;
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
};

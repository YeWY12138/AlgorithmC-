/*设计哈希集合------------------------------------------------------------------------
题目：705. 设计哈希集合
不使用任何内建的哈希表库设计一个哈希集合（HashSet）。

实现 MyHashSet 类：

void add(key) 向哈希集合中插入值 key 。
bool contains(key) 返回哈希集合中是否存在这个值 key 。
void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/design-hashset
*/

/*代码实现*/

class MyHashSet {
private:
    vector<list<int>> data;
    static int const base = 769;
    static int hash(int i){
        return i % base;
    } 
public:
    MyHashSet():data(base) {
    }
    
    void add(int key) {
        int h = hash(key);
        for(auto it = data[h].begin(); it != data[h].end(); it++){
            if((*it) == key){
                return;
            }
        } 
        data[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        for(auto it = data[h].begin(); it != data[h].end(); it++){
            if((*it) == key){
                data[h].erase(it);
                return;
            }
        }        
    }
    
    bool contains(int key) {
        int h = hash(key);
        for(auto it = data[h].begin(); it != data[h].end(); it++){
            if((*it) == key){
                return true;;
            }
        } 
        return false;
    }
};
#include<iostream>
#include<vector>
namespace heap_sort{
    //图片参考：https://blog.csdn.net/weixin_42109012/article/details/91668543
    void maxHeapify(std::vector<int>& nums, int i, int len){
        for(;(i << 1) + 1 <= len;){
            int lson = (i<<1) +1;               //根节点和叶子节点的关系：i i*2+1 i*2+2
            int rson = (i<<1) +2;
            int large;
            if(lson <= len && nums[lson] > nums[i]){
                large = lson;
            }else{
                large = i;
            }
            if(rson <= len && nums[rson] > nums[large]){
                large = rson;
            }

            if(large != i){
                std::swap(nums[i], nums[large]);//若发生交换，则意味着低层的大顶堆也需要更新
                i = large;                      //重新进入循环，更新低层大顶堆
            }else{
                break;                          //不发生交换
            }

        }
    }
    
    void buildMaxHeap(std::vector<int>& nums, int len){
        for(int i = len/2; i >= 0; i--){        //由低到高构建大顶堆
            heap_sort::maxHeapify(nums, i, len);
        }
    }

    void heapSort(std::vector<int>& nums){
        int len = nums.size()-1;
        heap_sort::buildMaxHeap(nums,len);
        for(int i = len; i >= 1; i--){
            std::swap(nums[i],nums[0]);
            len-=1;
            heap_sort::maxHeapify(nums,0,len);
        }
    }

}

int main(){
    std::vector<int> nums = {9,8,6,7,10,23,43,1,2,3,4,5};
    heap_sort::heapSort(nums);
    for(auto n:nums){
        std::cout<<n<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
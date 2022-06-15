#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<time.h>

namespace quick_sort{
    int partition(std::vector<int>& nums, int left, int right){
        int pivot = nums[right];
        int i = left - 1;
        for(int j = left; j <= right - 1; j++){
            if(nums[j] <= pivot){
                i = i + 1;
                std::swap(nums[i],nums[j]);
            }
        }
        std::swap(nums[i+1],nums[right]);
        return i+1;
    } 
    
	int randomizedPartition(std::vector<int>& nums, int left, int right){
        int i = rand()%(right - left + 1) + left;
        std::swap(nums[i],nums[right]);
        return quick_sort::partition(nums,left,right);
    }
    
    void randomizedQuicksort(std::vector<int>& nums, int left, int right){
        if(left < right){
            int pos = randomizedPartition(nums,left,right);
            quick_sort::randomizedQuicksort(nums,left,pos-1);
            quick_sort::randomizedQuicksort(nums,pos+1,right);
        }
    }
}

int main(){
    std::vector<int> nums = {9,8,6,7,10,23,43,1,2,3,4,5};
    std::srand((unsigned)time(NULL));
    quick_sort::randomizedQuicksort(nums,0,nums.size());
    for(auto n:nums){
        std::cout<<n<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
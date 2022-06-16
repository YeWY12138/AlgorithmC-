/*题目：数组中第K个最大元素*/
/*217
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

1 <= k <= nums.length <= 104
-104 <= nums[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/kth-largest-element-in-an-array*/

/*思路：
堆排序

class Solution {
public:
    void heap(vector<int>& nums, int index, int len){
        for(;(index<<1)+1 <= len;){
            int lch = (index<<1)+1;
            
            int rch = (index<<1)+2;
            int large = index;
            if(lch <= len && nums[lch] > nums[large]){
                large = lch;
            }
            if(rch <= len && nums[rch] > nums[large]){
                large = rch;
            }
            if(large != index ){
                swap(nums[index],nums[large]);


                index = large;
            }
            else{
                break;
            }
        }    
    }

    void buildHeap(vector<int>& nums, int len){
        for(int i = len/2; i>= 0; i--){
            heap(nums,i,len);
        // cout<<i<<endl;
        // for(auto n:nums){
        //     cout<<n<<" ";
        // }
        //     cout<<endl;
        }

    }

    int findKthLargest(vector<int>& nums, int k) {
        for(int i = 0; i < k; i++){
            buildHeap(nums,nums.size()-i-1);
            swap(nums[0],nums[nums.size()-i-1]);
        }
        return nums[nums.size()-k];
    }
};
*/
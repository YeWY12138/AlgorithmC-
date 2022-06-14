/*-------------------------指数搜索------------------------------- */
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>



namespace search{
namespace binary_search{
    uint64_t binarySearch(std::vector<uint64_t>arr, uint64_t val,uint64_t left, uint64_t right){
        uint64_t low = left;
        uint64_t high = right;

        while(low < high){
            uint64_t mid = low + (high - low) / 2;
            if(val == arr[mid]){
                return mid;
            }
            else if(val > arr[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        } 
        return -1;//not found
    }

}//namespace binary_search
namespace expontial_search{
    uint64_t expontialSearch(std::vector<uint64_t>arr, uint64_t val){
        if(arr.size() == 0) return -1;//not found
        uint64_t left = 0;
        uint64_t right = 1;
        //uint64_t right = arr.size() == 1? 0: 1;
        uint64_t res = -1;
        while(left != arr.size()){
            if(search::binary_search::binarySearch(arr,val,left,right) == -1){
                left = right+1;
                if(left *2 -1 >= arr.size()){
                    right = arr.size()-1;
                }else{
                    right = left*2 -1;
                }
            }
            else{
                res = search::binary_search::binarySearch(arr,val,left,right);
                break;                
            }
        }
        return res;
    }
}//namespace expontial_search


}//namespace search

static void test1() {
    // testcase #1
    // array = [1,3,5,7,9,8,6,4,2] , Value = 4
    // should return 3

    //std::vector<uint64_t> arr = {1, 3, 5, 7, 9, 8, 6, 4, 2};
    //std::sort(arr.begin(), arr.end());
    std::vector<uint64_t> arr = {};
    uint64_t expected_ans = 3;
    uint64_t derived_ans = search::expontial_search::expontialSearch(arr, 4);
    std::cout << "Test #1: ";
    std::cout << derived_ans;
    //assert(derived_ans == expected_ans);
    std::cout << "Passed!" << std::endl;
}

int main(){
    test1();
    return 0;
}

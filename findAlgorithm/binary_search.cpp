#include<algorithm>
#include<cassert>
#include<iostream>
#include<vector>

namespace search{
namespace binary_search{
    uint64_t binarySearch(std::vector<uint64_t> arr, uint64_t val){
        uint64_t low = 0;
        uint64_t high = arr.size() - 1;

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
}//namespace search

static void test1() {
    // testcase #1
    // array = [1,3,5,7,9,8,6,4,2] , Value = 4
    // should return 3

    std::vector<uint64_t> arr = {{1, 3, 5, 7, 9, 8, 6, 4, 2}};
    std::sort(arr.begin(), arr.end());
    uint64_t expected_ans = 3;
    uint64_t derived_ans = search::binary_search::binarySearch(arr, 4);
    std::cout << "Test #1: ";
    if(expected_ans == derived_ans)
    assert(derived_ans == expected_ans);
    std::cout << "Passed!" << std::endl;
}

int main(){
    test1();
    return 0;
}
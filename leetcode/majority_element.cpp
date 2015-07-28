#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());            
    return nums[nums.size()/2];
}

int main() {
    int num[] = {1,2,2,3,3,3,2,3,2,2,2};
    vector<int> nums(num, num+sizeof(num)/sizeof(int));
    cout << majorityElement(nums) << endl;
    return 0;
}

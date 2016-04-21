#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        vector<int> res_vec;
        int  limit = nums.size() / 3;

        if (nums.size() <= 5)
            return nums;

        return res_vec;
    }
};
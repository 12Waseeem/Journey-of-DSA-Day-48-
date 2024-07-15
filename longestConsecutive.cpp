#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0;
         set<int> mySet;
        for(auto num:nums){
            mySet.insert(num);
        }
        int i=0;
        for(auto num:mySet){
           nums[i++]=num;
        }
        int maxLen=0;
        int left=0;
        int j = 1;
        for (; j <i; j++) {
            
            if (nums[j] - nums[j - 1] != 1) {
                maxLen = max(maxLen, j - left);
                left = j;
            }
        }
        
        // Check the last sequence
        maxLen = max(maxLen, (i - left));
        
        return maxLen;
    }
};


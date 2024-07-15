
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int n=nums.size();
        int mini=INT_MAX;
        int sum=0;
        for (int right = 0; right < n; ++right) {
            sum += nums[right];

            while (sum >= target) {
                mini = min(mini, right - left + 1);
                sum -= nums[left++];
            }
        }
        if(mini==INT_MAX) return 0;
        return mini;
    }
};

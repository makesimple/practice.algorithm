#if 0
给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。

#endif

// 解读如下：
// (1) dp[i] count[i]均是统计以第i个数字为结尾的LIS的最长值和最长值的个数。
// (2) 由于我们的定义是第i个数字为结尾的LIS，如果nums[i] <= nums[j] && i > j,
//    根据定义我们要做如下处理，dp[i] = 1, count[i] = 1,但是我们初始化的时候，全部初始化成1了，
//    所以我们只考虑nums[i]>nums[j]的处理。
// (3) dp[i]值等于[0...i)中最长的递增子串 + 1，但是dp[i]值初始值是1，用[0,i)中每一个元素+1与dp[i]比较
//	多次取值得到dp[i]，最后一次是最大的一个。如果只考虑最长，不考虑最长的个数，用O(n)的时间就可以解决，因为第二重
//	循环不需要，一重循环中记住[0,i)中最长的子串的长度就可以了。
//	一开始必定是这个状态：dp[j] + 1 > dp[i]   （nums[i] > nums[j] 所以+1）
//	在这个状态下，不断用[0,i)的子串刷新dp[i]
//	直到刷新到dp[i] == dp[j] + 1 （dp[i] = dp[j] + 1的值是在dp[j] + 1 > dp[i]状态下取得）
//	再次遇到这个情况dp[i] == dp[j] + 1说明在[0,i)中又遇到一个长度跟前面一样的子串，那这个时间
//	count[i] += count[j]

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 0) return n;
        vector<int> dp(n, 1);
        vector<int> count(n,1);
        for(int i = 1; i < n; i++) {
            // dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if(dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
            }
        }
        int max = *max_element(dp.begin(), dp.end());
        int res = 0;
        for(int i=0; i<n; i++) {
            if(dp[i] == max)
                res += count[i];
        }
        return res;
    }
};

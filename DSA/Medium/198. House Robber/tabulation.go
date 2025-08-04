func rob(nums []int) int {
    n := len(nums)
    if n == 1 { return nums[0] }
    dp := make([]int, n)
    dp[0] = nums[0]
    dp[1] = max(nums[1], nums[0])
    for i := 2;i < n;i++ {
        dp[i] = max(nums[i] + dp[i-2],  dp[i-1])
    }
    return dp[n-1]
}

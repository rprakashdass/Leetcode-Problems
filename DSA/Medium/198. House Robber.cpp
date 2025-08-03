func recursiveRob(dp []int , nums []int, n int) int {
    if n < 0 { return 0 }
    if dp[n] != -1 { return dp[n] }
    rob := nums[n] + recursiveRob(dp, nums, n-2)
    dontRob := recursiveRob(dp, nums, n-1)
    dp[n] = max(rob, dontRob)
    return dp[n];
}

func rob(nums []int) int {
    n := len(nums)
    dp := make([]int, n)
    for i, _ := range dp { dp[i] = -1 }
    return recursiveRob(dp, nums, n-1)
}

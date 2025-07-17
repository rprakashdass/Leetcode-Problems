func climb(dp []int, n int) int {
    if n < 0 { return 0 }
    if n == 0 { return 1 }
    if(dp[n] != -1) { return dp[n] }

    left := climb(dp, n-1)
    right := climb(dp, n-2)

    dp[n] = left + right
    return dp[n]
}

func climbStairs (n int) int {
    dp := make([]int, n+1)
    for i, _ := range dp {
        dp[i] = -1
    }
    return climb(dp, n)
}

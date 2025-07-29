func lengthOfLongestSubstring(s string) int {
    lastSeen := make(map[rune]int)
    left, maxLen := 0, 0
    for right, ch := range s {
        if indx, ok := lastSeen[ch]; ok && indx >= left {
            left = indx + 1
        }
        lastSeen[ch] = right
        maxLen = max(maxLen, right-left+1)
    }
    return maxLen
}

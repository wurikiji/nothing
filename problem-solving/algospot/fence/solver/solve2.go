package solver

func solve2(arr []int, begin, end int) int {
	if end == begin {
		return 0
	}
	if begin+1 == end {
		return (arr)[begin]
	}

	mid := (end + begin) / 2
	leftMax := solve2(arr, begin, mid)
	rightMax := solve2(arr, mid, end)
	midMax := findMidMax(arr, begin, end)

	return max(leftMax, max(rightMax, midMax))
}

func findMidMax(arr []int, begin, end int) int {
	mid := (begin + end) / 2
	left, right := mid-1, mid
	minHeight := min(arr[left], arr[right])
	ret := minHeight * 2
	for left > begin || right+1 < end {
		if left > 0 && (right+1 == len(arr) || arr[left-1] > arr[right+1]) {
			left--
			minHeight = min(minHeight, arr[left])
		} else {
			right++
			minHeight = min(minHeight, arr[right])
		}
		ret = max(ret, minHeight*(right-left+1))
	}
	return ret
}

func min(a int, b int) int {
	if a > b {
		return b
	}
	return a
}
func max(a int, b int) int {
	if a < b {
		return b
	}
	return a
}

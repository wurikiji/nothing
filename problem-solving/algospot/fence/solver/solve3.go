package solver

func solve3(arr []int) int {
	ret := 0
	for j := 1; j <= 10000; j++ {
		width := 0
		for i := 0; i < len(arr); i++ {
			if arr[i] < j {
				ret = max(ret, width*j)
				width = 0
			} else {
				width++
			}
		}
	}
	return ret
}

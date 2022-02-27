package main

import (
	"fmt"
	"strconv"
	"strings"
)

func optimalDivision(nums []int) string {
	n := len(nums)
	if n == 1 {
		return strconv.Itoa(nums[0])
	}
	if n == 2 {
		return fmt.Sprintf("%d/%d", nums[0], nums[1])
	}

	res := &strings.Builder{}

	res.WriteString(fmt.Sprintf("%d/(%d", nums[0], nums[1]))

	for i := 2; i < n; i++ {
		res.WriteByte('/')
		res.WriteString(strconv.Itoa(nums[i]))
	}

	res.WriteByte(')')

	return res.String()
}

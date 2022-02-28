package main

func minSteps(s string, t string) int {
    ms, mt := [26]int{}, [26]int{}
    for _, c := range s {
		idx := int32(c) - int32('a')
        ms[idx]++
    }
    for _, c := range t {
        idx := int32(c) - int32('a')
        mt[idx]++
    }

    res := 0
    for i := 0; i < 26; i++ {
        res += Abs(ms[i], mt[i])
    }

    return res
}

func Abs(x, y int) int {
    if x > y {
        return x - y
    } 
    return y - x
}
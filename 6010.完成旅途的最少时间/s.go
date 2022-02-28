package main

import "math"

func minimumTime(time []int, totalTrips int) int64 {
    lo := int64(0)
    _, vMin := MinElement(time)
    hi := int64(totalTrips) * int64(vMin)

    for lo < hi {
        mi := (hi - lo) / 2 + lo
        k := int64(0)
        for _, t := range time {
            k += mi / int64(t)
        }
        if k < int64(totalTrips) {
            lo = mi + 1
        } else {
            hi = mi
        }
    }

    return lo
}

func MinElement(arr []int) (idx, val int) {
    idx = -1
    val = math.MaxInt

    for i, v := range arr {
        if v < val {
            idx = i
            val = v
        }
    }
    return
}
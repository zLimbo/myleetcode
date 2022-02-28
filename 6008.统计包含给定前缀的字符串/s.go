package main

func prefixCount(words []string, pref string) int {
    res := 0
    for _, w := range words {
        // if strings.HasPrefix(w, pref) {
        //     res += 1
        // }

        if len(w) < len(pref) {
            continue
        }
        isPrefix := true
        for i, n := 0, len(pref); i < n; i++ {
            if w[i] != pref[i] {
                isPrefix = false
            }
        }
        if isPrefix {
            res += 1
        }
    }
    return res
}   
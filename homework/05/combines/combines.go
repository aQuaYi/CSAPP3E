package combines

func combine0(a []int, dest *int) {
	*dest = 0
	for _, n := range a {
		*dest += n
	}
}

func combine1(a []int, dest *int) {
	*dest = 0
	for i := 0; i < len(a); i++ {
		*dest += a[i]
	}
}

func combine2(a []int, dest *int) {
	*dest = 0
	size := len(a)
	for i := 0; i < size; i++ {
		*dest += a[i]
	}
}

func combine4(a []int, dest *int) {
	size := len(a)
	t := 0
	for i := 0; i < size; i++ {
		t += a[i]
	}
	*dest = t
}

func combine6(a []int, dest *int) {
	size := len(a)
	t0, t1 := 0, 0
	i := 0
	for ; i < size; i += 2 {
		t0 += a[i]
		t1 += a[i+1]
	}

	if i < size-1 {
		t0 += a[size-1]
	}

	*dest = t0 + t1
}

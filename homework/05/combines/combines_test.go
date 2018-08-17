package combines

import "testing"

var size = 1000000
var a []int
var dest int

func init() {
	a = make([]int, size)
	for i := range a {
		a[i] = i
	}
	return
}

func Benchmark_combine0(b *testing.B) {
	b.ResetTimer()
	for i := 1; i < b.N; i++ {
		combine0(a, &dest)
	}
}

func Benchmark_combine1(b *testing.B) {
	b.ResetTimer()
	for i := 1; i < b.N; i++ {
		combine1(a, &dest)
	}
}

func Benchmark_combine2(b *testing.B) {
	b.ResetTimer()
	for i := 1; i < b.N; i++ {
		combine2(a, &dest)
	}
}

func Benchmark_combine4(b *testing.B) {
	b.ResetTimer()
	for i := 1; i < b.N; i++ {
		combine4(a, &dest)
	}
}

func Benchmark_combine6(b *testing.B) {
	b.ResetTimer()
	for i := 1; i < b.N; i++ {
		combine6(a, &dest)
	}
}

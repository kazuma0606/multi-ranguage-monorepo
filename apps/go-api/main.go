package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println("🐹 Hello from Go in Turborepo!")
	fmt.Println("Go and Turborepo integration is working!")

	// 現在時刻を表示
	now := time.Now()
	fmt.Printf("Current time: %s\n", now.Format("2006-01-02 15:04:05"))

	// 簡単な計算
	numbers := []int{1, 2, 3, 4, 5}
	sum := 0
	for _, num := range numbers {
		sum += num
	}
	fmt.Printf("Sum of %v = %d\n", numbers, sum)

	// Go のバージョン情報
	fmt.Println("✅ Go app completed successfully!")
}

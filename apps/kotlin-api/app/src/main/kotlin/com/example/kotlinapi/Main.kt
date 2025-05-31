// app/src/main/kotlin/com/example/kotlinapi/Main.kt
package com.example.kotlinapi

import kotlinx.datetime.Clock
import kotlinx.serialization.Serializable
import kotlinx.serialization.encodeToString
import kotlinx.serialization.json.Json
import kotlin.system.measureTimeMillis

@Serializable
data class HealthStatus(
    val service: String = "kotlin-api",
    val status: String = "healthy",
    val timestamp: String,
    val language: String = "Kotlin",
    val version: String = KotlinVersion.CURRENT.toString(),
    val uptime: String,
    val system: SystemInfo
)

@Serializable
data class SystemInfo(
    val os: String = System.getProperty("os.name"),
    val jvmVersion: String = System.getProperty("java.version"),
    val memoryUsage: MemoryInfo
)

@Serializable
data class MemoryInfo(
    val totalMemory: Long,
    val freeMemory: Long,
    val usedMemory: Long,
    val maxMemory: Long
)

fun main(args: Array<String>) {
    println("🟣 Kotlin CLI Health Checker in Turborepo!")
    // println("="  50)
    
    val startTime = System.currentTimeMillis()
    
    // メモリ情報取得
    val runtime = Runtime.getRuntime()
    val memoryInfo = MemoryInfo(
        totalMemory = runtime.totalMemory(),
        freeMemory = runtime.freeMemory(),
        usedMemory = runtime.totalMemory() - runtime.freeMemory(),
        maxMemory = runtime.maxMemory()
    )
    
    // システム情報
    val systemInfo = SystemInfo(memoryUsage = memoryInfo)
    
    // ヘルスチェック実行
    val executionTime = measureTimeMillis {
        performHealthChecks()
    }
    
    // ヘルスステータス作成
    val healthStatus = HealthStatus(
        timestamp = Clock.System.now().toString(),
        uptime = "${System.currentTimeMillis() - startTime}ms",
        system = systemInfo
    )
    
    // 結果出力
    println("\n📊 Health Check Results:")
    // println("-" * 30)
    println("✅ Service: ${healthStatus.service}")
    println("✅ Status: ${healthStatus.status}")
    println("✅ Language: ${healthStatus.language} ${healthStatus.version}")
    println("✅ OS: ${systemInfo.os}")
    println("✅ JVM: ${systemInfo.jvmVersion}")
    println("✅ Execution Time: ${executionTime}ms")
    
    // メモリ使用量（MB単位）
    println("\n💾 Memory Usage:")
    println("   Used: ${memoryInfo.usedMemory / 1024 / 1024} MB")
    println("   Free: ${memoryInfo.freeMemory / 1024 / 1024} MB")
    println("   Total: ${memoryInfo.totalMemory / 1024 / 1024} MB")
    println("   Max: ${memoryInfo.maxMemory / 1024 / 1024} MB")
    
    // JSON形式での出力（オプション）
    if (args.contains("--json")) {
        println("\n📋 JSON Output:")
        val json = Json { prettyPrint = true }
        println(json.encodeToString(healthStatus))
    }
    
    // 簡単な計算デモ
    performCalculationDemo()
    
    println("\n✅ Kotlin health check completed successfully!")
    println("🟣 Kotlin CLI is working perfectly in Turborepo!")
}

fun performHealthChecks() {
    println("\n🔍 Performing Health Checks...")
    
    // CPU集約的なタスク
    print("   CPU Test... ")
    val result = (1..1000000).map { it * it }.sum()
    println("✅ (Sum: $result)")
    
    // メモリテスト
    print("   Memory Test... ")
    val largeList = (1..100000).toList()
    println("✅ (Created list of ${largeList.size} items)")
    
    // ファイルシステムテスト
    print("   File System Test... ")
    val tempDir = System.getProperty("java.io.tmpdir")
    println("✅ (Temp dir: $tempDir)")
    
    // ネットワーク簡易テスト
    print("   System Properties Test... ")
    val userHome = System.getProperty("user.home")
    println("✅ (User home: $userHome)")
}

fun performCalculationDemo() {
    println("\n🧮 Kotlin Features Demo:")
    
    // データクラスとコレクション
    data class NumberStats(val value: Int, val square: Int, val cube: Int)
    
    val numbers = (1..5).map { 
        NumberStats(it, it * it, it * it * it) 
    }
    
    println("   Numbers with squares and cubes:")
    numbers.forEach { stats ->
        println("     ${stats.value} -> square: ${stats.square}, cube: ${stats.cube}")
    }
    
    // 関数型プログラミング
    val evenSquares = numbers
        .filter { it.value % 2 == 0 }
        .map { it.square }
    
    println("   Even number squares: $evenSquares")
    
    // Null安全性デモ
    val nullableValue: String? = if (System.currentTimeMillis() % 2 == 0L) "value" else null
    println("   Null safety demo: ${nullableValue?.uppercase() ?: "NULL"}")
}
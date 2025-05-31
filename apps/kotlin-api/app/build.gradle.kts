plugins {
    kotlin("jvm") version "1.9.20"
    application
}

repositories {
    mavenCentral()
}

dependencies {
    implementation("org.jetbrains.kotlin:kotlin-stdlib")
    
    // JSON処理（軽量）
    implementation("org.jetbrains.kotlinx:kotlinx-serialization-json:1.6.0")
    
    // 日時処理
    implementation("org.jetbrains.kotlinx:kotlinx-datetime:0.4.1")
    
    // CLI引数処理（オプション）
    implementation("org.jetbrains.kotlinx:kotlinx-cli:0.3.6")
    
    testImplementation("org.jetbrains.kotlin:kotlin-test-junit5")
    testImplementation("org.junit.jupiter:junit-jupiter-engine:5.9.3")
}

application {
    mainClass.set("com.example.kotlinapi.MainKt")
}

tasks.named<Test>("test") {
    useJUnitPlatform()
}

kotlin {
    jvmToolchain(17)
}
const std = @import("std");
const print = std.debug.print;

pub fn main() !void {
    print("Zig Next-Gen System Tools in Turborepo!\n", .{});
    print("=========================================\n", .{});

    // 現在の日時を取得・表示
    try displayCurrentDateTime();

    // アロケータの取得
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer _ = gpa.deinit();
    const allocator = gpa.allocator();

    // システムツール機能
    try performSystemInfo();
    try performDateTimeTools(allocator);
    try performMemoryAnalysis(allocator);
    try performZigFeatures();

    print("\n[OK] Zig system tools completed successfully!\n", .{});
    print("Next-generation system programming in Turborepo!\n", .{});
}

fn displayCurrentDateTime() !void {
    print("\nCurrent Date/Time Tools:\n", .{});

    // Unix timestamp取得
    const timestamp = std.time.timestamp();
    print("   [OK] Unix timestamp: {}\n", .{timestamp});

    // ミリ秒単位の時間
    const millis = std.time.milliTimestamp();
    print("   [OK] Milliseconds since epoch: {}\n", .{millis});

    // 今日の日付計算（簡易版）
    const days_since_epoch = @divTrunc(timestamp, 86400);
    const days_since_2000 = days_since_epoch - 10957; // 2000年1月1日からの日数
    print("   [OK] Days since 2000-01-01: {}\n", .{days_since_2000});

    // 現在の年の概算計算
    const approximate_year = 2000 + @divTrunc(days_since_2000, 365);
    print("   [OK] Approximate current year: {}\n", .{approximate_year});
}

fn performDateTimeTools(allocator: std.mem.Allocator) !void {
    _ = allocator; // unused parameter
    print("\nDate/Time Calculation Tools:\n", .{});

    // 様々な時間単位の計算
    const timestamp = std.time.timestamp();

    const seconds_in_day = 24 * 60 * 60;
    const seconds_in_hour = 60 * 60;
    const seconds_in_minute = 60;

    const current_day_seconds = @mod(timestamp, seconds_in_day);
    const hours = @divTrunc(current_day_seconds, seconds_in_hour);
    const minutes = @divTrunc(@mod(current_day_seconds, seconds_in_hour), seconds_in_minute);
    const seconds = @mod(current_day_seconds, seconds_in_minute);

    print("   [OK] Current time (UTC): {d:0>2}:{d:0>2}:{d:0>2}\n", .{ hours, minutes, seconds });

    // 時間計算ツール
    const milliseconds_in_day = 24 * 60 * 60 * 1000;
    const current_millis = std.time.milliTimestamp();
    const today_start = current_millis - @mod(current_millis, milliseconds_in_day);

    print("   [OK] Today started at timestamp: {}\n", .{@divTrunc(today_start, 1000)});
    print("   [OK] Milliseconds since midnight: {}\n", .{current_millis - today_start});
}

fn performSystemInfo() !void {
    print("\nSystem Information:\n", .{});

    // コンパイル時情報
    const builtin = @import("builtin");
    print("   [OK] Target OS: {s}\n", .{@tagName(builtin.target.os.tag)});
    print("   [OK] Target CPU: {s}\n", .{@tagName(builtin.target.cpu.arch)});
    print("   [OK] Build mode: {s}\n", .{@tagName(builtin.mode)});
    print("   [OK] Zig version: {s}\n", .{builtin.zig_version_string});

    // パフォーマンスカウンター
    const start = std.time.nanoTimestamp();
    // 簡単な計算
    var sum: u64 = 0;
    var i: u32 = 0;
    while (i < 1000000) : (i += 1) {
        sum += i;
    }
    const end = std.time.nanoTimestamp();

    print("   [OK] Million iterations in {} nanoseconds\n", .{end - start});
    print("   [OK] Calculated sum: {}\n", .{sum});
}

fn performMemoryAnalysis(allocator: std.mem.Allocator) !void {
    print("\nMemory Analysis:\n", .{});

    // 動的配列
    var numbers = std.ArrayList(u32).init(allocator);
    defer numbers.deinit();

    // データ生成
    var i: u32 = 1;
    while (i <= 50000) : (i += 1) {
        try numbers.append(i * i); // 平方数
    }

    print("   [OK] Generated {} square numbers\n", .{numbers.items.len});
    print("   [OK] First few: {any}\n", .{numbers.items[0..5]});
    print("   [OK] Last few: {any}\n", .{numbers.items[numbers.items.len - 5 ..]});

    // メモリ使用量概算
    const memory_used = numbers.items.len * @sizeOf(u32);
    print("   [OK] Approximate memory used: {} bytes\n", .{memory_used});
}

fn performZigFeatures() !void {
    print("\nZig Language Features:\n", .{});

    // コンパイル時計算
    const comptime_result = comptime blk: {
        var sum: u32 = 0;
        var i: u32 = 1;
        while (i <= 100) : (i += 1) {
            sum += i;
        }
        break :blk sum;
    };

    print("   [OK] Compile-time sum(1..100): {}\n", .{comptime_result});

    // エラーハンドリング
    const division_result = safeDivision(100, 5) catch |err| {
        print("   [ERROR] Division failed: {}\n", .{err});
        return;
    };

    print("   [OK] Safe division 100/5: {}\n", .{division_result});

    // Optional handling
    const maybe_number: ?u32 = 42;
    if (maybe_number) |number| {
        print("   [OK] Optional unwrapped: {}\n", .{number});
    }

    // Array operations
    const fibonacci = [_]u32{ 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };
    var fib_sum: u32 = 0;
    for (fibonacci) |fib| {
        fib_sum += fib;
    }
    print("   [OK] Fibonacci sum: {}\n", .{fib_sum});

    // String handling
    const language_name = "Zig";
    print("   [OK] Language: {s} (length: {})\n", .{ language_name, language_name.len });
}

fn safeDivision(a: u32, b: u32) !u32 {
    if (b == 0) return error.DivisionByZero;
    return a / b;
}

// Tests
test "date calculations" {
    const timestamp = 1704067200; // 2024-01-01 00:00:00 UTC
    const days = @divTrunc(timestamp, 86400);
    try std.testing.expect(days > 19000); // Should be reasonable
}

test "safe division" {
    const result = try safeDivision(10, 2);
    try std.testing.expect(result == 5);

    const error_result = safeDivision(10, 0);
    try std.testing.expectError(error.DivisionByZero, error_result);
}

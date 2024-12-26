const std = @import("std");

fn lessThan(context: void, a: i32, b: i32) std.math.Order {
    _ = context;
    return std.math.order(a, b);
}

pub fn main() !void {
    const path = "input.txt";
    var file = try std.fs.cwd().openFile(path, .{});
    defer file.close();

    var bufReader = std.io.bufferedReader(file.reader());
    var in = bufReader.reader();

    var buf: [1024]u8 = undefined;

    var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    defer arena.deinit();
    const allocator = arena.allocator();

    var safeLevels: u32 = 0;
    safeLevels = safeLevels;
    while (try in.readUntilDelimiterOrEof(&buf, '\n')) |line| {
        var arr = std.ArrayList(i32).init(allocator);
        defer arr.deinit();

        var it = std.mem.split(u8, line, " ");
        while (it.next()) |str| {
            const num = try std.fmt.parseInt(i32, str, 10);
            try arr.append(num);
        }

        var items = arr.items;
        // Convert all lists to ascending
        if (items[0] > items[items.len - 1]) {
            for (items, 0..) |_, i|
                items[i] *= -1;
        }

        // Calculate differences
        var diffs = std.ArrayList(i32).init(allocator);
        defer diffs.deinit();
        for (items[1..], 1..) |cur, i| {
            const prev = items[i - 1];
            try diffs.append(cur - prev);
        }

        // Check safe levels
        items = diffs.items;
        std.debug.print("{any}\n", .{items});
        var unsafe = false;
        for (items, 0..) |cur, i| {
            _ = i;
            if (isOutsideRange(cur)) {
                unsafe = true;
                break;
            }
        }
        if (!unsafe)
            safeLevels += 1;
    }

    // Print result
    const stdout = std.io.getStdOut().writer();
    try stdout.print("{d}\n", .{safeLevels});
}

fn isOutsideRange(val: i32) bool {
    return val < 1 or val > 3;
}

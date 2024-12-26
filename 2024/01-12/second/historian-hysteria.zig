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

    var left = std.PriorityQueue(i32, void, lessThan).init(allocator, {});
    var right = std.PriorityQueue(i32, void, lessThan).init(allocator, {});
    defer left.deinit();
    defer right.deinit();

    while (try in.readUntilDelimiterOrEof(&buf, '\n')) |line| {
        var it = std.mem.split(u8, line, " ");
        var word = it.next() orelse "";
        const leftValue = try std.fmt.parseInt(i32, word, 10);
        try left.add(leftValue);

        // Skip empty values
        word = it.next() orelse "";
        while (word.len <= 0)
            word = it.next() orelse "0";

        const rightValue = try std.fmt.parseInt(i32, word, 10);
        try right.add(rightValue);
    }

    // Add everything together
    var sum: i32 = 0;
    while (left.count() > 0) {
        const base = left.remove();
        var num = base;
        var mul: i32 = 1;
        // Left side
        while (left.peek() == base) {
            _ = left.remove();
            mul += 1;
        }
        // Right side
        var found = false;
        while (right.peek() orelse base + 1 <= base) {
            if (right.remove() == base) {
                found = true;
                num += base;
            }
        }
        num -= base;
        if (found)
            num *= mul;
        sum += num;
    }

    // Print result
    const stdout = std.io.getStdOut().writer();
    try stdout.print("{d}\n", .{sum});
}

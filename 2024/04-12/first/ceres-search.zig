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

    var mat = std.ArrayList([]u8).init(allocator);
    defer mat.deinit();
    var count: usize = 0;
    while (try in.readUntilDelimiterOrEof(&buf, '\n')) |line| {
        try mat.append(try std.mem.Allocator.dupe(allocator, u8, line));
    }

    const rows = mat.items.len;
    const cols = mat.items[0].len;
    for (mat.items, 0..) |row, i| {
        for (row, 0..) |_, j| {
            var r: isize = -1;
            while (r < 2) : (r += 1) {
                var c: isize = -1;
                while (c < 2) : (c += 1) {
                    if (r != 0 or c != 0)
                        count += checkString(mat.items, i, j, r, c, rows, cols);
                }
            }
        }
    }

    // Print result
    const stdout = std.io.getStdOut().writer();
    try stdout.print("{d}\n", .{count});
}

fn checkString(mat: []const []u8, row: usize, col: usize, rowDir: isize, colDir: isize, rows: usize, cols: usize) usize {
    const xmas = "XMAS";
    const size: isize = xmas.len;

    const lastRow: isize = @as(isize, @intCast(row)) + (size - 1) * rowDir;
    if (lastRow < 0 or lastRow >= rows) return 0;
    const lastCol: isize = @as(isize, @intCast(col)) + (size - 1) * colDir;
    if (lastCol < 0 or lastCol >= cols) return 0;

    var k: isize = 0;
    while (k < size) : (k += 1) {
        const r: usize = @intCast(@as(isize, @intCast(row)) + k * rowDir);
        const c: usize = @intCast(@as(isize, @intCast(col)) + k * colDir);
        if (xmas[@intCast(k)] != mat[r][c])
            break;
    }
    return if (k == 4) 1 else 0;
}

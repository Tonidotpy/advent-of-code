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
        for (row, 0..) |chr, j| {
            if (chr == 'M') {
                var dir: isize = -1;
                while (dir < 2) : (dir += 2) {
                    count += checkHorizontal(mat.items, i, j, 1, dir, rows, cols);
                }
                dir = -1;
                while (dir < 2) : (dir += 2) {
                    count += checkVertical(mat.items, i, j, dir, 1, rows, cols);
                }
            }
        }
    }

    // Print result
    const stdout = std.io.getStdOut().writer();
    try stdout.print("{d}\n", .{count});
}

fn checkHorizontal(mat: []const []u8, row: usize, col: usize, rowDir: isize, colDir: isize, rows: usize, cols: usize) usize {
    const gridSize: isize = 3;
    const lr = @as(isize, @intCast(row)) + (gridSize - 1) * rowDir;
    const lc = @as(isize, @intCast(col)) + (gridSize - 1) * colDir;
    if (lr < 0 or lr >= rows or lc < 0 or lc >= cols)
        return 0;

    const lastRow: usize = @intCast(lr);
    const lastCol: usize = @intCast(lc);
    const centerRow: usize = @intCast(@as(isize, @intCast(row)) + rowDir);
    const centerCol: usize = @intCast(@as(isize, @intCast(col)) + colDir);

    if (mat[lastRow][col] == 'M' and mat[row][lastCol] == 'S') {
        if (mat[centerRow][centerCol] == 'A' and mat[lastRow][lastCol] == 'S') {
            return 1;
        }
    }
    return 0;
}
fn checkVertical(mat: []const []u8, row: usize, col: usize, rowDir: isize, colDir: isize, rows: usize, cols: usize) usize {
    const gridSize: isize = 3;
    const lr = @as(isize, @intCast(row)) + (gridSize - 1) * rowDir;
    const lc = @as(isize, @intCast(col)) + (gridSize - 1) * colDir;
    if (lr < 0 or lr >= rows or lc < 0 or lc >= cols)
        return 0;

    const lastRow: usize = @intCast(lr);
    const lastCol: usize = @intCast(lc);
    const centerRow: usize = @intCast(@as(isize, @intCast(row)) + rowDir);
    const centerCol: usize = @intCast(@as(isize, @intCast(col)) + colDir);

    if (mat[row][lastCol] == 'M' and mat[lastRow][col] == 'S') {
        if (mat[centerRow][centerCol] == 'A' and mat[lastRow][lastCol] == 'S') {
            return 1;
        }
    }
    return 0;
}

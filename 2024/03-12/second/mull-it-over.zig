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

    var buf: [4096]u8 = undefined;

    var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    defer arena.deinit();
    const allocator = arena.allocator();

    var sum: u32 = 0;
    var enabled = true;
    while (try in.readUntilDelimiterOrEof(&buf, '\n')) |line| {
        var state: u8 = 0;
        var lStr = std.ArrayList(u8).init(allocator);
        var rStr = std.ArrayList(u8).init(allocator);
        for (line) |c| {
            switch (state) {
                0 => {
                    if (c == 'd') {
                        state = 6;
                    } else if (enabled and c == 'm') {
                        state += 1;
                    }
                },
                1 => {
                    if (c == 'u') {
                        state += 1;
                    } else {
                        state = 0;
                    }
                },
                2 => {
                    if (c == 'l') {
                        state += 1;
                    } else {
                        state = 0;
                    }
                },
                3 => {
                    if (c == '(') {
                        state += 1;
                    } else {
                        state = 0;
                    }
                },
                4 => {
                    if (std.ascii.isDigit(c) and lStr.items.len < 3) {
                        try lStr.append(c);
                    } else if ((lStr.items.len >= 1 and lStr.items.len <= 3) and c == ',') {
                        state += 1;
                    } else {
                        state = 0;
                        lStr.clearRetainingCapacity();
                    }
                },
                5 => {
                    if (std.ascii.isDigit(c) and rStr.items.len < 3) {
                        try rStr.append(c);
                    } else if ((rStr.items.len >= 1 and rStr.items.len <= 3) and c == ')') {
                        const l = try std.fmt.parseInt(u32, lStr.items, 10);
                        const r = try std.fmt.parseInt(u32, rStr.items, 10);
                        sum += l * r;
                        state = 0;
                        lStr.clearRetainingCapacity();
                        rStr.clearRetainingCapacity();
                    } else {
                        state = 0;
                        lStr.clearRetainingCapacity();
                        rStr.clearRetainingCapacity();
                    }
                },
                6 => {
                    if (c == 'o') {
                        state += 1;
                    } else {
                        state = 0;
                    }
                },
                7 => {
                    if (c == '(') {
                        state += 1;
                    } else if (c == 'n') {
                        state = 9;
                    } else {
                        state = 0;
                    }
                },
                8 => {
                    if (c == ')') {
                        enabled = true;
                    }
                    state = 0;
                },
                9 => {
                    if (c == '\'') {
                        state += 1;
                    } else {
                        state = 0;
                    }
                },
                10 => {
                    if (c == 't') {
                        state += 1;
                    } else {
                        state = 0;
                    }
                },
                11 => {
                    if (c == '(') {
                        state += 1;
                    } else {
                        state = 0;
                    }
                },
                12 => {
                    if (c == ')') {
                        enabled = false;
                    }
                    state = 0;
                },
                else => state = 0,
            }
        }
    }

    // Print result
    const stdout = std.io.getStdOut().writer();
    try stdout.print("{d}\n", .{sum});
}

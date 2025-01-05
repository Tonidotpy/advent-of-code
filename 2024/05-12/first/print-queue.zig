const std = @import("std");

fn LessThan(context: void, a: i32, b: i32) std.math.Order {
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

    const Page = u8;
    var map = std.AutoHashMap(Page, std.ArrayList(Page)).init(allocator);
    while (try in.readUntilDelimiterOrEof(&buf, '\n')) |line| {
        if (line.len == 0)
            break;

        var aux = std.mem.split(u8, line, "|");
        const l: Page = @intCast(try std.fmt.parseInt(Page, aux.next().?, 10));
        const r: Page = @intCast(try std.fmt.parseInt(Page, aux.next().?, 10));
        if (map.get(l) == null) {
            try map.put(l, std.ArrayList(Page).init(allocator));
        }
        if (map.get(r) == null) {
            try map.put(r, std.ArrayList(Page).init(allocator));
        }

        const dependencies = map.getPtr(r);
        if (dependencies) |dep| {
            try dep.*.append(l);
        }
    }

    var it = map.iterator();
    while (it.next()) |x| {
        std.debug.print("{}: {any}\n", .{ x.key_ptr.*, x.value_ptr.*.items });
    }

    var sum: usize = 0;
    sum = 0;

    while (try in.readUntilDelimiterOrEof(&buf, '\n')) |line| {
        var aux = std.mem.split(u8, line, ",");
        var pages = std.ArrayList(Page).init(allocator);
        var printed = std.AutoHashMap(Page, bool).init(allocator);
        while (aux.next()) |x| {
            const num = try std.fmt.parseInt(Page, x, 10);
            try pages.append(num);
            try printed.put(num, false);
        }

        var correct = true;
        for (pages.items) |page| {
            try printed.put(page, true);

            std.debug.print("{} ", .{page});

            const deps = map.get(page).?;
            for (deps.items) |dep| {
                const print = printed.get(dep);
                if (print) |p| {
                    if (!p) {
                        correct = false;
                        break;
                    }
                }
            }

            if (!correct)
                break;
        }
        std.debug.print("\n", .{});
        if (correct)
            sum += pages.items[pages.items.len / 2];
    }

    // Print result
    const stdout = std.io.getStdOut().writer();
    try stdout.print("{d}\n", .{sum});
}

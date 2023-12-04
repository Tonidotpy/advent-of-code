package advent.of.code

import java.io.File

fun main() {
    try {
        var cnt = 0
        File("input.txt").forEachLine { s ->
            val row = s.split(":")[1].trim()
            val set = row.split("|")

            // Iterate over winning numbers
            val win = hashSetOf<Int>()
            for (num in set[0].trim().split("\\s+".toRegex()).map { it.trim().toInt() })
                win.add(num)

            val nums = set[1].trim().split("\\s+".toRegex()).map { it.trim().toInt() }
            var points = 0
            for (num in nums) {
                if (win.contains(num))
                    points = if (points == 0) 1 else points * 2
            }
            cnt += points
        }

        println(cnt)
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

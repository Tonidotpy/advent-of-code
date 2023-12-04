package advent.of.code

import java.io.File

fun main() {
    try {
        val matches = mutableListOf<Int>()
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
                    ++points
            }
            matches.add(points)
        }

        // Count copies of cards
        val len = matches.size
        val cards = MutableList(len) { 1 }
        for (i in 0..(len - 1)) {
            for (j in 0..(matches[i] - 1)) {
                cards[i + j + 1] += cards[i]
            }
        }
        println(cards.sum())
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

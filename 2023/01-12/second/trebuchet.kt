package advent.of.code

import java.io.File

enum class Numbers(val value: String) {
    ONE("one"),
    TWO("two"),
    THREE("three"),
    FOUR("four"),
    FIVE("five"),
    SIX("six"),
    SEVEN("seven"),
    EIGHT("eight"),
    NINE("nine");

    companion object {
        val map = Numbers.values().associateBy { it.value }
    }
}

fun main() {
    var cnt = 0
    try {
        File("input.txt").forEachLine { s ->
            // Check first
            val (fs, fmatch) = s.findAnyOf(Numbers.map.keys, ignoreCase = true) ?: Pair(Int.MAX_VALUE, "")
            var fi = s.indexOfFirst { it.isDigit()  }
            if (fi < 0) fi = Int.MAX_VALUE
            val first = (if (fi < fs) s[fi] else Numbers.map[fmatch]!!.ordinal + 1).toString()

            
            // Check last
            val (ls, lmatch) = s.findLastAnyOf(Numbers.map.keys, ignoreCase = true) ?: Pair(-1, "")
            var li = s.indexOfLast { it.isDigit() }
            val last = (if (li > ls) s[li] else Numbers.map[lmatch]!!.ordinal + 1).toString()

            // Get number and add to sum
            val num = (first + last).toInt()
            cnt += num

            // print("$first  ")
            // print("$last  ")
            // println(num)
        }
        println(cnt)
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

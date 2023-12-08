package advent.of.code

import java.io.File

enum class Direction(val value: String) {
    LEFT("L"),
    RIGHT("R");

    companion object {
        private val map = Direction.values().associateBy { it.value }
        infix fun from(value: String) = map[value]
    }
}

fun main() {
    try {
        val map = mutableMapOf<String, Pair<String, String>>()

        val input = File("input.txt").readLines()
        val dirs: String = input[0]

        for (i in 2..(input.size - 1)) {
            val aux = input[i].split("=")
            val src = aux[0].trim()

            val aux2 = aux[1].replace("(", "").replace(")", "").split(",")
            val l = aux2[0].trim()
            val r = aux2[1].trim()

            map[src] = Pair(l, r)
        }

        var cur = "AAA"
        val end = "ZZZ"
        var i = 0
        var cnt = 0
        while (cur != end) {
            when(dirs[i]) {
                'L' -> cur = map[cur]?.first ?: cur
                'R' -> cur = map[cur]?.second ?: cur
                else -> println("Sus");
            }
            i = (i + 1) % dirs.length
            ++cnt
        }

        println(cnt)
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

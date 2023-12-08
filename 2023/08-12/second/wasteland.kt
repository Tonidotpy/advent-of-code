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
fun gcd(a: Long, b: Long): Long {
    var f = a
    var s = b
    while (s > 0) {
        val temp: Long = s
        s = f % s
        f = temp
    }
    return f
}
fun lcm(a: Long, b: Long): Long {
    return (a * b) / gcd(a, b)
}

fun main() {
    try {
        val map = mutableMapOf<String, Pair<String, String>>()

        val input = File("input.txt").readLines()
        val dirs: String = input[0]

        val sources = mutableListOf<String>()

        for (i in 2..(input.size - 1)) {
            val aux = input[i].split("=")
            val src = aux[0].trim()

            if (src.last() == 'A')
                sources.add(src)

            val aux2 = aux[1].replace("(", "").replace(")", "").split(",")
            val l = aux2[0].trim()
            val r = aux2[1].trim()

            map[src] = Pair(l, r)
        }

        val firstHits = mutableListOf<Long>()
        for (i in 0..(sources.size - 1)) {
            var cnt = 0L
            var dirIndex = 0
            while (sources[i].last() != 'Z') {
                when(dirs[dirIndex]) {
                    'L' -> sources.set(i, map[sources[i]]?.first ?: sources[i])
                    'R' -> sources.set(i, map[sources[i]]?.second ?: sources[i])
                    else -> println("Sus");
                }
                dirIndex = (dirIndex + 1) % dirs.length
                ++cnt
            }
            firstHits.add(cnt)
        }
        
        var out = firstHits[0]
        for (i in 1..(firstHits.size - 1)) {
            out = lcm(out, firstHits[i])
        }
        println(out)
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

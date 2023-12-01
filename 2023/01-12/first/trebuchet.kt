package advent.of.code

import java.io.File

fun main() {
    var cnt = 0
    try {
        File("input.txt").forEachLine {
            val s = it
            val first = s.first { it.isDigit() }.toString()
            val last = s.last { it.isDigit() }.toString()

            val num = (first + last).toInt()
            cnt += num
        }

        println(cnt)
    }
    catch(e: Exception) {
        System.err.println("Cant find file input.txt")
    }
}

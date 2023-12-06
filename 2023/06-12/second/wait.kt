package advent.of.code

import java.io.File

fun main() {
    try {
        val input = File("input.txt").readLines()
        var tot: Long = 1
    
        val time = input[0].split(":")[1].trim().replace("\\s+".toRegex(), "").toLong()
        val record = input[1].split(":")[1].trim().replace("\\s+".toRegex(), "").toLong()

        val half: Long = time / 2
        val odd: Long = time % 2

        var start: Long = 0
        var end: Long = half
        var tPress: Long = 0
        
        // Binary search
        while(start <= end) {
            tPress = start + ((end - start) / 2)
            val tRun = time - tPress

            if (tPress * (tRun + odd) <= record)
                start = tPress + 1
            else
                end = tPress - 1
        }
        while (tPress <= half && tPress * (time - tPress) <= record)
            ++tPress

        val cur = (half - tPress + 1) * 2 - (1 - odd)
        tot *= cur

        println(tot)
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

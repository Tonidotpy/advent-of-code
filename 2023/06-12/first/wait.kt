package advent.of.code

import java.io.File

fun main() {
    try {
        val input = File("input.txt").readLines()
        var tot = 1
    
        val times = input[0].split(":")[1].trim().split("\\s+".toRegex()).map { it.toInt() }
        val distances = input[1].split(":")[1].trim().split("\\s+".toRegex()).map { it.toInt() }
        val len = times.size

        for (i in 0..(len - 1)) {
            val time = times[i]
            val record = distances[i]
    
            val half = time / 2
            val odd = time % 2

            var start = 0
            var end = half
            var tPress = 0
            

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
        }

        println(tot)
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

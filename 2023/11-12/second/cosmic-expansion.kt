package advent.of.code

import kotlin.math.abs
import kotlin.system.exitProcess
import java.io.File
import java.util.*

fun main() {
    try {
        val input = File("input.txt").readLines()

        val emptyRows = mutableListOf<Long>()
        val emptyCols = mutableListOf<Long>()
        input.forEachIndexed { row, s ->
            if ('#' !in s)
                emptyRows.add(row.toLong())
        }
        (input.indices).map { rowIndex -> input.map { it[rowIndex] } }.forEachIndexed { col, l ->
            if ('#' !in l)
                emptyCols.add(col.toLong())
        }
        emptyRows.add(-1L)
        emptyCols.add(-1L)

        val mul = 1000000L - 1L
        var erCount = 0
        val galaxies = mutableListOf<Pair<Long, Long>>()
        input.forEachIndexed { row, s ->
            var ecCount = 0
            if (row.toLong() == emptyRows[erCount])
                ++erCount
            else {
                s.forEachIndexed { col, c ->
                    if (col.toLong() == emptyCols[ecCount])
                        ++ecCount
                    else if (c == '#')
                        galaxies.add(Pair(row + erCount * mul, col + ecCount * mul))
                }
            }
        }

        var cnt = 0L
        for (i in 0..(galaxies.size - 2)) {
            val (r1, c1) = galaxies[i]
            for (j in (i + 1)..(galaxies.size - 1)) {
                val (r2, c2) = galaxies[j]
                val dist = abs(r2 - r1) + abs(c2 - c1)
                cnt += dist
            }
        }
        println(cnt)
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

package advent.of.code

import kotlin.math.abs
import kotlin.system.exitProcess
import java.io.File
import java.util.*

fun main() {
    try {
        val input = File("input.txt").readLines()

        val emptyRows = mutableListOf<Int>()
        val emptyCols = mutableListOf<Int>()
        input.forEachIndexed { row, s ->
            if ('#' !in s)
                emptyRows.add(row)
        }
        (input.indices).map { rowIndex -> input.map { it[rowIndex] } }.forEachIndexed { col, l ->
            if ('#' !in l)
                emptyCols.add(col)
        }
        emptyRows.add(-1)
        emptyCols.add(-1)

        var erCount = 0
        val galaxies = mutableListOf<Pair<Int, Int>>()
        input.forEachIndexed { row, s ->
            var ecCount = 0
            if (row == emptyRows[erCount])
                ++erCount
            else {
                s.forEachIndexed { col, c ->
                    if (col == emptyCols[ecCount])
                        ++ecCount
                    else if (c == '#')
                        galaxies.add(Pair(row + erCount, col + ecCount))
                }
            }
        }

        var cnt = 0L
        for (i in 0..(galaxies.size - 2)) {
            val (r1, c1) = galaxies[i]
            for (j in (i + 1)..(galaxies.size - 1)) {
                val (r2, c2) = galaxies[j]
                val dist = abs(r2 - r1) + abs(c2 - c1)
                cnt += dist.toLong()
            }
        }
        println(cnt)
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

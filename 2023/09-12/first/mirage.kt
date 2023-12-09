package advent.of.code

import kotlin.system.exitProcess
import java.io.File

fun solve(DP: Array<Array<Long?>>, row: Int, col: Int) {
    if (row >= DP.size || col < 0)
        return

    if (DP[row - 1][col] == null)
        solve(DP, row - 1, col)
    DP[row][col] = (DP[row - 1][col + 1] ?: 0) - (DP[row - 1][col] ?: 0)
    
    // if (col == DP[0].size - row - 1 && DP[row][col] != 0L)
    solve(DP, row + 1, col - 1)
}

fun main() {
    try {
        var cnt = 0L
        File("input.txt").forEachLine { s ->
            val nums = s.split(" ").map { it.toLong() }
            
            val DP = Array(nums.size - 1) { Array<Long?>(nums.size - it) { null } }
            for (i in 0..(nums.size - 1))
                DP[0][i] = nums[i]
            solve(DP, 1, nums.size - 2)
            // DP.forEach { row ->
            //     row.forEach {
            //         print("${it} ")
            //     }
            //     println()
            // }
            // println()

            for (i in 0..(nums.size - 2)) {
                val num = DP[i].last()
                cnt += num ?: 0
            }
        }
        println(cnt)
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

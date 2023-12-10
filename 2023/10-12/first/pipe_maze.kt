package advent.of.code

import kotlin.system.exitProcess
import java.io.File
import java.util.*

fun main() {
    try {
        var start = 0
        val input = File("input.txt").readLines()
        val rows = input.size
        val cols = input[0].length
        val grid = Array(rows * cols) { mutableListOf<Int>() }

        fun getIndex(row: Int, col: Int): Int {
            return row * cols + col
        }

        input.forEachIndexed { row, s ->
            s.forEachIndexed { col, c ->
                val index = getIndex(row, col)
                when(c) {
                    '|' -> {
                        if (row - 1 >= 0 && input[row - 1][col] in "|7FS")
                            grid[index].add(getIndex(row - 1, col))
                        if (row + 1 < rows && input[row + 1][col] in "|LJS")
                            grid[index].add(getIndex(row + 1, col))
                    }
                    '-' -> {
                        if (col - 1 >= 0 && s[col - 1] in "-LFS")
                            grid[index].add(getIndex(row, col - 1))
                        if (col + 1 < cols && s[col + 1] in "-7JS")
                            grid[index].add(getIndex(row, col + 1))
                    }
                    'L' -> {
                        if (col + 1 < cols && s[col + 1] in "-7JS")
                            grid[index].add(getIndex(row, col + 1))
                        if (row - 1 >= 0 && input[row - 1][col] in "|7FS")
                            grid[index].add(getIndex(row - 1, col))
                    }
                    '7' -> {
                        if (col - 1 >= 0 && s[col - 1] in "-LFS")
                            grid[index].add(getIndex(row, col - 1))
                        if (row + 1 < rows && input[row + 1][col] in "|LJS")
                            grid[index].add(getIndex(row + 1, col))
                    }
                    'F' -> {
                        if (col + 1 < cols && s[col + 1] in "-7JS")
                            grid[index].add(getIndex(row, col + 1))
                        if (row + 1 < rows && input[row + 1][col] in "|LJS")
                            grid[index].add(getIndex(row + 1, col))
                    }
                    'J' -> {
                        if (col - 1 >= 0 && s[col - 1] in "-LFS")
                            grid[index].add(getIndex(row, col - 1))
                        if (row - 1 >= 0 && input[row - 1][col] in "|7FS")
                            grid[index].add(getIndex(row - 1, col))
                    }
                    'S' -> {
                        start = index
                        if (col - 1 >= 0 && s[col - 1] in "-LFS")
                            grid[index].add(getIndex(row, col - 1))
                        if (col + 1 < cols && s[col + 1] in "-7JS")
                            grid[index].add(getIndex(row, col + 1))
                        if (row - 1 >= 0 && input[row - 1][col] in "|7FS")
                            grid[index].add(getIndex(row - 1, col))
                        if (row + 1 < rows && input[row + 1][col] in "|LJS")
                            grid[index].add(getIndex(row + 1, col))
                    }
                }
            }
        }

        // BFS
        val visited = BooleanArray(rows * cols) { false }
        val q: Queue<Pair<Int, Int>> = LinkedList<Pair<Int, Int>>()
        q.add(Pair(start, 0))
        var maxDepth = 0
        while(!q.isEmpty()) {
            val (cur, depth) = q.remove()
            if (depth > maxDepth) maxDepth = depth

            if (visited[cur])
                continue
            visited[cur] = true

            for (node in grid[cur]) {
                if (!visited[node])
                    q.add(Pair(node, depth + 1))
            }
        }
        println(maxDepth)
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

package advent.of.code

import kotlin.system.exitProcess
import java.io.File
import java.util.*

fun main() {
    try {
        val input = File("input.txt").readLines()
        val rows = input.size
        val cols = input[0].length
        var start = Pair(0, 0)
        input.forEachIndexed { row, s ->
            val index = s.indexOf('S')
            if (index >= 0) {
                start = Pair(row, index)
            }
        }

        fun getIndex(row: Int, col: Int): Int {
            return row * cols + col
        }
        
        val parsed = Array(rows) { CharArray(cols) { '.' } }
        val visited = Array(rows) { BooleanArray(cols) { false } }
        val q: Queue<Pair<Int, Int>> = LinkedList<Pair<Int, Int>>()
        q.add(start)
        while(!q.isEmpty()) {
            val (r, c) = q.remove()

            if (visited[r][c])
                continue
            visited[r][c] = true
            parsed[r][c] = input[r][c]

            if (input[r][c] in "S|LJ" && r - 1 >= 0 && !visited[r - 1][c] && input[r - 1][c] in "|7F")
                q.add(Pair(r - 1, c))
            if (input[r][c] in "S|F7" && r + 1 < rows && !visited[r + 1][c] && input[r + 1][c] in "|LJ")
                q.add(Pair(r + 1, c))
            if (input[r][c] in "S-J7" && c - 1 >= 0 && !visited[r][c - 1] && input[r][c - 1] in "-LF")
                q.add(Pair(r, c - 1))
            if (input[r][c] in "S-LF" && c + 1 < cols && !visited[r][c + 1] && input[r][c + 1] in "-J7")
                q.add(Pair(r, c + 1))
        }
        val (sr, sc) = start
        val u = parsed[sr - 1][sc]
        val d = parsed[sr + 1][sc]
        val l = parsed[sr][sc - 1]
        val r = parsed[sr][sc + 1]
        if (u in "|7F") {
            if (d in "|LJ") parsed[sr][sc] = '|'
            else if (l in "-LF") parsed[sr][sc] = 'J'
            else if (r in "-J7") parsed[sr][sc] = 'L'
        }
        else if (l in "-LF") {
            if (d in "|LJ") parsed[sr][sc] = '7'
            else if (r in "-J7") parsed[sr][sc] = '-'
        }

        var cnt = 0
        val cCnt = IntArray(cols) { 0 }
        parsed.forEachIndexed { row, s ->
            var rCnt = 0
            var prevC = '.'
            s.forEachIndexed { col, c ->
                if (c == '.') {
                    if (rCnt % 2 == 1) {
                        ++cnt
                        parsed[row][col] = 'I'
                    }
                }
                else if (c in "FL")
                    prevC = c
                else if (c == '|')
                    ++rCnt
                else if (prevC == 'F') {
                    if (c == 'J') {
                        ++rCnt
                        prevC = '.'
                    }
                    else if (c == '7')
                        prevC = '.'
                }
                else if (prevC == 'L') {
                    if (c == '7') {
                        ++rCnt
                        prevC = '.'
                    }
                    else if (c == 'J')
                        prevC = '.'
                }
                // if (c != '|') ++cCnt[col]
                // println("${row}, ${col}: ${c} -> ${rCnt}, ${cCnt[col]}: ${cnt}")
            }
            // println()
        }
        parsed.forEach {
            println(it)
        }
        println(cnt)
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

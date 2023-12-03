package advent.of.code

import java.io.File

fun main() {
    try {
        val text = File("input.txt").readLines()
        val gears = mutableMapOf<Pair<Int, Int>, ArrayList<Int>>()

        text.forEachIndexed { row_i, row ->
            var startIndex = -1
            var endIndex = -1

            val len = row.length

            row.forEachIndexed { col_i, col ->
                // Check start of number
                if (startIndex < 0) {
                    if (col.isDigit())
                        startIndex = col_i
                }
                // Check for end of number
                // Not an else on purpose because startIndex can change inside the first if
                if (startIndex >= 0) {
                    if (col_i + 1 >= len || !row[col_i + 1].isDigit())
                        endIndex = col_i + 1
                }

                // Check for symbols
                if (endIndex >= 0) {
                    val num = row.substring(startIndex, endIndex).toInt()
                    var isPartNumber = false
                    var gear = Pair(0, 0)

                    // Check for columns
                    for (c in (startIndex - 1)..endIndex) {
                        if (c < 0 || c >= len)
                            continue

                        if (row_i - 1 >= 0) { 
                            if (!text[row_i - 1][c].isDigit() && text[row_i - 1][c] == '*') {
                                isPartNumber = true
                                gear = Pair(c, row_i - 1)
                                break
                            }
                        }
                        if (row_i + 1 < text.size) {
                            if (!text[row_i + 1][c].isDigit() && text[row_i + 1][c] == '*') {
                                isPartNumber = true
                                gear = Pair(c, row_i + 1)
                                break
                            }
                        }
                    }
                    // Check for rows 
                    if (!isPartNumber) {
                        if (startIndex > 0 && !row[startIndex - 1].isDigit() && row[startIndex - 1] == '*') {
                            isPartNumber = true
                            gear = Pair(startIndex - 1, row_i)
                        }
                        else if (endIndex < len && !row[endIndex].isDigit() && row[endIndex] == '*') {
                            isPartNumber = true
                            gear = Pair(endIndex, row_i)
                        }
                    }

                    if (isPartNumber) {
                        if (gear !in gears.keys)
                            gears[gear] = ArrayList()
                        gears[gear]?.add(num)
                    }

                    // Reset indices
                    startIndex = -1
                    endIndex = -1
                }
            }
        }

        var cnt = 0
        // Count gears power
        gears.forEach { (_, nums) ->
            if (nums.size == 2) {
                cnt += nums[0] * nums[1]
            }
        }
        println(cnt)
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

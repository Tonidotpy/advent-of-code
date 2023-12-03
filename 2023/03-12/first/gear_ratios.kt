package advent.of.code

import java.io.File

fun main() {
    try {
        val text = File("input.txt").readLines()
        var cnt = 0

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

                    // Check for columns
                    for (c in (startIndex - 1)..endIndex) {
                        if (c < 0 || c >= len)
                            continue

                        if (row_i - 1 >= 0) { 
                            if (!text[row_i - 1][c].isDigit() && text[row_i - 1][c] != '.') {
                                isPartNumber = true
                                break
                            }
                        }
                        if (row_i + 1 < text.size) {
                            if (!text[row_i + 1][c].isDigit() && text[row_i + 1][c] != '.') {
                                isPartNumber = true
                                break
                            }
                        }
                    }
                    // Check for rows 
                    if (!isPartNumber) {
                        if (startIndex > 0 && !row[startIndex - 1].isDigit() && row[startIndex - 1] != '.')
                            isPartNumber = true
                        if (endIndex < len && !row[endIndex].isDigit() && row[endIndex] != '.')
                            isPartNumber = true
                    }

                    if (isPartNumber)
                        cnt += num

                    // Reset indices
                    startIndex = -1
                    endIndex = -1
                }
            }
        }

        println(cnt)
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

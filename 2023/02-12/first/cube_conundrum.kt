package advent.of.code

import java.io.File

enum class Color(val value: String) {
    RED("red"),
    GREEN("green"),
    BLUE("blue");

    companion object {
        val map = Color.values().associateBy { it.value }
    }
}

fun main() {
    var cnt = 0
    try {
        var lineCount = 0
        File("input.txt").forEachLine { line ->
            ++lineCount
            var isImpossible: Boolean = false
            
            // Parse line
            val game: String = line.split(":")[1]
            for (set in game.split(";")) {
                for (cubes in set.split(",")) {
                    // Parse cube info
                    val info = cubes.trim().split(" ")
                    val count = info[0].toInt()
                    val color = Color.map[info[1]]!!

                    // Check number of cubes
                    when(color) {
                        Color.RED -> if (count > 12) isImpossible = true
                        Color.GREEN -> if (count > 13) isImpossible = true
                        Color.BLUE -> if (count > 14) isImpossible = true
                    }

                    // Break if impossible
                    if (isImpossible)
                        break
                }
                if (isImpossible)
                    break
            }

            if (!isImpossible)
                cnt += lineCount
        }

        println(cnt)
    }
    catch(e: Exception) {
        System.err.println("Cant find file input.txt")
    }
}

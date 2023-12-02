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
    var cnt: Int = 0
    try {
        File("input.txt").forEachLine { line ->
            val minCubes = mutableMapOf<Color, Int>(
                Color.RED to 0,
                Color.GREEN to 0,
                Color.BLUE to 0
            )

            // Parse line
            val game: String = line.split(":")[1]
            for (set in game.split(";")) {
                for (cubes in set.split(",")) {
                    // Parse cube info
                    val info = cubes.trim().split(" ")
                    val count: Int = info[0].toInt()
                    val color: Color = Color.map[info[1]]!!

                    if (count > minCubes[color] ?: 0)
                        minCubes[color] = count
                }
            }
            cnt += (minCubes[Color.RED] ?: 0) *
                (minCubes[Color.GREEN] ?: 0) *
                (minCubes[Color.BLUE] ?: 0)
        }

        println(cnt)
    }
    catch(e: Exception) {
        System.err.println("Cant find file input.txt")
    }
}

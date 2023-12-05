package advent.of.code

import java.io.File

fun LongRange.convert(number: Long, target: LongRange): Long {
    if (!this.contains(number))
        return number

    val offset = target.start - start
    return number + offset
}

fun parseMap(input: List<String>, i: Int): Pair<MutableMap<LongRange, LongRange>, Int> {
    // Parse map
    var curLine = i
    val map = mutableMapOf<LongRange, LongRange>()
    while(!input[curLine].isEmpty()) {
        val (dest, src, len) = input[curLine].split(" ").map{ it.toLong() }
        map[src..(src + len - 1)] = (dest)..(dest + len - 1)
        ++curLine
    }
    curLine += 2

    return Pair(map.toSortedMap(compareBy { it.start }), curLine)
}

fun mapTo(map: MutableMap<LongRange, LongRange>, number: Long): Long {
    // Binary search
    val keys = map.keys.toList()
    var start = 0
    var end = keys.size - 1

    while(start <= end) {
        val pivot = (start + (end - start) / 2)
        val range = keys[pivot]

        if (range.contains(number))
            return range.convert(number, map[range] ?: range) 

        if (number < range.start)
            end = pivot - 1
        else
            start = pivot + 1
    }
    return number
}

fun main() {
    var minLocation = Long.MAX_VALUE
    try {
        val input = File("input.txt").readLines()
        var curLine = 0
        
        // Get seeds 
        val list = input[curLine].split(":")[1].trim().split(" ").map { it.toLong() }
        val seeds = mutableListOf<LongRange>()
        for (i in 0..(list.size - 1) step 2)
            seeds.add(list[i]..(list[i] + list[i + 1] - 1))
        curLine += 3

        // Get seed to soil map
        var aux = parseMap(input, curLine)
        val seedToSoil = aux.first
        curLine = aux.second
        
        // Get soil to fertilizer map
        aux = parseMap(input, curLine)
        val soilToFertilizer = aux.first
        curLine = aux.second

        // Get fertilizer to water map
        aux = parseMap(input, curLine)
        val fertilizerToWater = aux.first
        curLine = aux.second

        // Get water to light map
        aux = parseMap(input, curLine)
        val waterToLight = aux.first
        curLine = aux.second
        
        // Get light to temperature map
        aux = parseMap(input, curLine)
        val lightToTemperature = aux.first
        curLine = aux.second
        
        // Get temperature to humidity map
        aux = parseMap(input, curLine)
        val temperatureToHumidity = aux.first
        curLine = aux.second
        
        // Get humidity to location map
        aux = parseMap(input, curLine)
        val humidityToLocation = aux.first
         
        // Map seed to location
        for (seedRange in seeds) {
            for (seed in seedRange) {
                var loc = mapTo(seedToSoil, seed)
                loc = mapTo(soilToFertilizer, loc)
                loc = mapTo(fertilizerToWater, loc)
                loc = mapTo(waterToLight, loc)
                loc = mapTo(lightToTemperature, loc)
                loc = mapTo(temperatureToHumidity, loc)
                loc = mapTo(humidityToLocation, loc)

                if (loc < minLocation)
                    minLocation = loc
            }
        }


        println(minLocation)
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

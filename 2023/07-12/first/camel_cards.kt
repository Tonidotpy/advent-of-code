package advent.of.code

import java.io.File

enum class Card(val value: String) {
    TWO("2"),
    THREE("3"),
    FOUR("4"),
    FIVE("5"),
    SIX("6"),
    SEVEN("7"),
    EIGHT("8"),
    NINE("9"),
    TEN("T"),
    JACK("J"),
    QUEEN("Q"),
    KING("K"),
    ACE("A");

    companion object {
        private val map = Card.values().associateBy { it.value }
        infix fun from(value: String) = map[value]
    }
}
enum class HandType {
    HIGH_CARD,
    ONE_PAIR,
    TWO_PAIRS,
    THREE_OF_A_KIND,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    FIVE_OF_A_KIND;
}

data class Hand(
    val type: HandType,
    val hand: String,
    val bid: Long
) : Comparable<Hand> {
    override fun compareTo(other: Hand): Int {
        if (type != other.type)
            return type.ordinal - other.type.ordinal
        for (i in 0..(hand.length - 1)) {
            val card = hand[i].toString()
            val otherCard = other.hand[i].toString()

            if (card != otherCard)
                return (Card.from(card)?.ordinal ?: 0) -
                    (Card.from(otherCard)?.ordinal ?: 0)
        }
        return 0
    }
}

fun main() {
    try {
        val arr = mutableListOf<Hand>()
        File("input.txt").forEachLine { s ->
            val (hand, bidStr) = s.split(" ")
            val bid = bidStr.toLong()
            val freq = mutableMapOf<Char, Long>()
            
            for (card in hand)
                freq[card] = freq.getOrDefault(card, 0) + 1
            val sorted = freq.toList().sortedByDescending { (_, value) -> value }
            
            var type = when(sorted[0].second) {
                5L -> HandType.FIVE_OF_A_KIND
                4L -> HandType.FOUR_OF_A_KIND
                3L -> when(sorted[1].second) {
                    2L -> HandType.FULL_HOUSE
                    else -> HandType.THREE_OF_A_KIND
                }
                2L -> when(sorted[1].second) {
                    2L -> HandType.TWO_PAIRS
                    else -> HandType.ONE_PAIR
                }
                else -> HandType.HIGH_CARD
            }

            arr.add(Hand(type, hand, bid))
        }
        arr.sort()

        var out = 0L
        arr.forEachIndexed { i, hand ->
            out += hand.bid * (i + 1)
        }
        println(out)
    }
    catch(e: Exception) {
        System.err.println(e.stackTraceToString())
    }
}

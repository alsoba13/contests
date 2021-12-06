fun slv(numbers: List<Int>, windowSize: Int) = numbers.windowed(windowSize+1).count { it.first() < it.last() }

fun main() {
    val numbers = (0 until readLine()!!.toInt()).map { readLine()!!.toInt() }
    println("Problem 1: ${slv(numbers, 1)}")
    println("Problem 2: ${slv(numbers, 3)}")
}
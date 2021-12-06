fun slv(numbers: List<Int>, windowSize: Int) = numbers.windowed(windowSize, 1, transform = Collection<Int>::sum).zipWithNext { a, b -> b - a }.count { it > 0 }

fun main() {
    val numbers = (0 until readLine()!!.toInt()).map { readLine()!!.toInt() }
    println("Problem 1: ${slv(numbers, 1)}")
    println("Problem 2: ${slv(numbers, 3)}")
}
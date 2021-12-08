fun slv(actions: List<Pair<String, Int>>): Int {
    val (horizontalPosition, depth) = actions.partition {
        it.first == "forward"
    }.let {
        (forwards, upDown) -> Pair(
            forwards.map { (_, value) -> value }.sum(),
            upDown.map { (direction, value) -> if (direction == "up") -value else value }.sum()
        )
    }
    return horizontalPosition * depth
}

fun slv2(actions: List<Pair<String, Int>>) : Int {
    var aim = 0;
    val depth = actions.map {
        (direction, value) -> when(direction) {
            "down" -> {aim += value; 0}
            "up" -> {aim -= value; 0}
            else -> aim*value
        }
    }.sum()
    val horizontalPosition = actions.filter { (direction, _) -> direction == "forward" }.map{it.second}.sum()
    return depth * horizontalPosition
}

fun main() {
    val actions = (0 until readLine()!!.toInt()).map { readLine()!!.split(" ").let { (direction, number) -> Pair(direction, number.toInt()) } }
    println("Problem 1: ${slv(actions)}")
    println("Problem 2: ${slv2(actions)}")
}
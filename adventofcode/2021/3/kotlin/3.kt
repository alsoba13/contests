fun commonty(bits: List<Char>, mostCommon : Boolean = true, untie: Char = '0') =
    bits.partition {
        bit -> bit == '0'
    }.let{
        (zeros, ones) -> when(zeros.size.compareTo(ones.size)) {
            1 -> if (mostCommon) '0' else '1'
            -1 -> if (mostCommon) '1' else '0'
            else -> untie
        }
    }

fun slv(binaries: List<String>, m: Int): Int {
    val mostCommon = (0 until m).map { index -> binaries.map { it[index] }.let { commonty(it) } }.joinToString("")
    val leastCommon = mostCommon.map {
        bit -> when(bit) {
            '0' -> '1'
            else -> '0'
        }
    }.joinToString("")
    return Integer.parseInt(mostCommon, 2) * Integer.parseInt(leastCommon, 2)
}

fun slv2(binaries: List<String>, mostCommon: Boolean, untie: Char): Int {
    var binariesAux: List<String> = binaries
    var prefix = ""
    while (binariesAux.size > 1) {
        prefix += commonty(binariesAux.map { it[prefix.length] }, mostCommon, untie)
        binariesAux = binariesAux.filter { binary -> binary.startsWith(prefix) }
    }
    return Integer.parseInt(binariesAux[0], 2)
}

fun main() {
    val (n, m) = readLine()!!.split(" ").map(String::toInt)
    val binaries = (0 until n).map { readLine()!! }
    println("Problem 1: ${slv(binaries, m)}")
    println("Problem 2: ${slv2(binaries, true, '1') * slv2(binaries,false, '0')}")
}
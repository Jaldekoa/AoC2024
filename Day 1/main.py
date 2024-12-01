def read_data(filename):
    with open(filename, "r", encoding="utf-8") as f:
        input_data = [list(map(int, line.split())) for line in f]
    return zip(*input_data)


def part_one(filename):
    left, right = map(sorted, read_data(filename))
    return sum(abs(l - r) for l, r in zip(left, right))


def part_two(filename):
    left, right = map(sorted, read_data(filename))
    return sum(el * right.count(el) for el in left)


if __name__ == "__main__":
    print(f"Part One: {part_one("input.txt")}")
    print(f"Part Two: {part_two("input.txt")}")


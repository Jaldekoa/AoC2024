import re


def read_data(filename):
    with open(filename, "r", encoding="utf-8") as f:
        return f.readlines()


def tokenizer(string):
    return re.findall(r"(do\(\)|don't\(\)|mul\((\d+),(\d+)\))", string)


def part_one(filename):
    input_data = "".join(read_data(filename))
    return sum(int(x) * int(y) for op, x, y in tokenizer(input_data) if "mul" in op)


def part_two(filename):
    input_data = "".join(read_data(filename))

    result, enabled = 0, True
    for op, x, y in tokenizer(input_data):
        enabled = False if op == "don't()" else True if op == "do()" else enabled
        result += int(x) * int(y) if enabled and "mul" in op else 0

    return result


if __name__ == "__main__":
    print(f"Part One: {part_one("input.txt")}")
    print(f"Part Two: {part_two("input.txt")}")

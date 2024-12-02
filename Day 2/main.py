from itertools import combinations


def read_data(filename):
    with open(filename, "r", encoding="utf-8") as f:
        input_data = [list(map(int, line.split())) for line in f]
    return input_data


def is_valid_report(report):
    diffs = [right - left for left, right in zip(report, report[1:])]
    return all(1 <= diff <= 3 for diff in diffs) or all(-3 <= diff <= -1 for diff in diffs)


def part_one(filename):
    input_data = read_data(filename)
    return sum(is_valid_report(report) for report in input_data)


def part_two(filename):
    input_data = read_data(filename)

    return sum(
        any(is_valid_report(sub_report)
            for sub_report in combinations(report, len(report) - 1))
        for report in input_data
    )


if __name__ == "__main__":
    print(f"Part One: {part_one("input.txt")}")
    print(f"Part Two: {part_two("input.txt")}")

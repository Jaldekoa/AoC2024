def read_data(filename) -> tuple[int, int]:
    with open(filename, "r", encoding="utf-8") as f:
        input_data = [list(map(int, line.split())) for line in f]
    return zip(*input_data)


if __name__ == "__main__":
    left, right = map(sorted, read_data("input.txt"))
    print(sum(abs(l - r) for l, r in zip(left, right)))

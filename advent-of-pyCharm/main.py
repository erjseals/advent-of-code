
# Detects the number of incremental increments, element by element
def num_increases(depths):
    if not depths:
        return 0
    else:
        prev_elem = depths[0]
        count = 0
        for elem in depths[1:]:
            if prev_elem < elem:
                count = count + 1
            print("prev_elem: " + str(prev_elem) + " elem: " + str(elem) + " count: " + str(count))
            prev_elem = elem
        return count


def advent_day1():
    depths = []
    with open('res/day1p1.txt', 'r') as file:
        lines = file.readlines()
        for line in lines:
            # Make sure you actually use these as integers!
            depths.append(int(line))
    increases = num_increases(depths)
    print(increases)


if __name__ == '__main__':
    advent_day1()


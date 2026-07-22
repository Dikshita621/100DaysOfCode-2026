def minMeetingRooms(intervals):
    if not intervals:
        return 0

    # Separate and sort start and end times
    starts = sorted([meeting[0] for meeting in intervals])
    ends = sorted([meeting[1] for meeting in intervals])

    rooms = 0
    max_rooms = 0
    s = 0
    e = 0
    n = len(intervals)

    while s < n:
        if starts[s] < ends[e]:
            rooms += 1
            if rooms > max_rooms:
                max_rooms = rooms
            s += 1
        else:
            rooms -= 1
            e += 1

    return max_rooms


# Example
intervals = [[1, 5], [2, 6], [4, 8], [9, 10]]
print(minMeetingRooms(intervals))

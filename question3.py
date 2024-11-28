import heapq

def merge_k_sorted_arrays(k, arrays):
    # Min-heap to store the first element of each array along with the array index and element index
    min_heap = []
    result = []

    # Insert the first element of each array into the heap
    for i in range(k):
        if arrays[i]:
            heapq.heappush(min_heap, (arrays[i][0], i, 0))  # (value, array_index, element_index)

    # Process the heap until it's empty
    while min_heap:
        value, array_index, element_index = heapq.heappop(min_heap)  # Extract the smallest element
        result.append(value)

        # If there's another element in the same array, insert it into the heap
        if element_index + 1 < len(arrays[array_index]):
            next_value = arrays[array_index][element_index + 1]
            heapq.heappush(min_heap, (next_value, array_index, element_index + 1))

    return result

# Input
k = int(input())  # Number of sorted arrays
arrays = [list(map(int, input().split())) for _ in range(k)]  # K sorted arrays

# Merge the arrays and print the result
merged_array = merge_k_sorted_arrays(k, arrays)
print("Merged Array:", merged_array)
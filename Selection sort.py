# Selection Sort using Greedy Approach with User Input

def selection_sort(arr):
    n = len(arr)
    print("\nOriginal Array:", arr)

    for i in range(n - 1):
        min_index = i  

        
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        arr[i], arr[min_index] = arr[min_index], arr[i]

        print(f"After step {i + 1}: {arr}")

    print("\nSorted Array:", arr)


if __name__ == "__main__":
    n = int(input("Enter number of elements: "))
    arr = []
    for i in range(n):
        val = int(input(f"Enter element {i + 1}: "))
        arr.append(val)

    selection_sort(arr)

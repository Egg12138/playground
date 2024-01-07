import random
import sys
from inspect import currentframe
from math import floor, ceil
from typing import List


def is_sorted(arr: List[int]) -> bool:
    return all( x <= y for (x, y) in zip(arr, arr[1:]) )

def gen_arr(n) -> List[int]:
    return [random.randint(0, 100) for _ in range(n)] 

def test_sort(func, arr):
    print(f"\t{func.__name__}:", end = '\t')
    func(arr.copy())



def insertion_sort(arr: List[int]) -> None:
    cmp_counts = 0
    swap_counts = 0
    for (i, key) in enumerate(arr):
        idx_sorted = i - 1
        while idx_sorted >= 0 and key < arr[idx_sorted]:
            arr[idx_sorted + 1] = arr[idx_sorted]
            cmp_counts += 1
            swap_counts += 1
            idx_sorted -= 1
        arr[idx_sorted + 1] = key

    print(f"{cmp_counts=}, {swap_counts=}")
    print(f"{arr=}(not sorted)") if not is_sorted(arr) else print("\tordered")

def biinsertion_sort(arr: List[int]) -> None:
    cmp_counts = 0
    swap_counts = 0
    for (cur, key) in enumerate(arr):
        # l the head index of the sorted sub-arr
        # h the tail index of the sorted sub-arr
        l = 0
        h = cur - 1
        # get the small
        while l <= h:
            m = floor((l + h) / 2)
            if key < arr[m]:  h = m - 1
            else:             l = m + 1
            cmp_counts += 1
        # move all after the ONE at which the key should be  
        for j in range(cur, l, -1):
            arr[j] = arr[j - 1]
            swap_counts += 1
        arr[l] = key

    print(f"{cmp_counts=}, {swap_counts=}")
    print(f"{arr=}(not sorted)") if not is_sorted(arr) else print("\tordered")


def shell_sort(arr: List[int]) -> None:
    gap = len(arr)            
    cmp_counts = 0
    swap_counts = 0
    while gap > 0:
        for i in range(gap, len(arr)):
            first_of_the_sublist = arr[i]
            j = i
            # apply direct insertion to each sub list.
            # j, j - gap, j - 2gap, j - 3gap
            while j >= gap and arr[j - gap] > first_of_the_sublist:
                cmp_counts += 1
                arr[j] = arr[j - gap]
                swap_counts += 1
                j -= gap
            arr[j] = first_of_the_sublist
                
        gap = floor(gap / 2)


    print(f"{cmp_counts=}, {swap_counts=}")
    print(f"{arr=}(not sorted)") if not is_sorted(arr) else print("\tordered")

def bubble(arr: List[int]) -> None:
    n = len(arr)
    cmp_counts = 0
    swap_counts = 0
    is_ordered = False

    for (i, key) in enumerate(arr):
        if is_ordered:
            break
        for k in range(n - i - 1):
            is_ordered = True
            if arr[k] > arr[k + 1]:
                cmp_counts += 1
                arr[k], arr[k + 1] = arr[k + 1], arr[k]
                swap_counts += 1
                is_ordered = False
    print(f"{cmp_counts=}, {swap_counts=}")
    print(f"{arr=}(not sorted)") if not is_sorted(arr) else print("\tordered")

def quick_sort(arr: List[int]) -> None:
    global cmp_counts
    global swap_counts
    cmp_counts = 0
    swap_counts = 0


    """
    此处的i = h + 1表示右侧的指标，它指向一个空位
        ——最新的那个要跟pivot交换的元素移动后留下的空位
    """
    def partition(l, h, cmp_counts, swap_counts):
        pivot = arr[l]
        while l < h and l > 0 and h > 0:
            while (l < h and arr[h] > pivot):
                cmp_counts += 1
                h -= 1
                arr[l] = arr[h]

            while (l < h and arr[l] <= pivot):
                cmp_counts += 1
                l += 1
                arr[h] = arr[l]

        arr[l] = pivot
        swap_counts += 1
        return l
    
    def quicksort_handler(l, h):
        if l < h:
            pivotidx = partition(l, h, cmp_counts, swap_counts)
            quicksort_handler(l, pivotidx - 1)
            quicksort_handler(pivotidx + 1, h)

    quicksort_handler(0, len(arr) - 1)
    print(f"{cmp_counts=}, {swap_counts=}")
    print(f"{arr=}(not sorted)") if not is_sorted(arr) else print("\tordered")

def selection_sort(arr: List[int]) -> None:
    n = len(arr)
    cmp_counts = 0
    swap_counts = 0

    for i in range(n):
        min_idx = i
        for k in range(i + 1, n):
            if arr(min_idx) > arr[k]:
                cmp_counts += 1
                min_idx = k
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
        swap_counts += 1

    
    print(f"{cmp_counts=}, {swap_counts=}")
    print(f"{arr=}(not sorted)") if not is_sorted(arr) else print("\tordered")



def heap_sort(arr: List[int]) -> None:
    n = len(arr)
    
    for i in range(floor(n / 2), -1, -1):
        headpify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i] 
        headpify(arr, i, 0)

    def headpify(arr: List[int], n, i):
        max_idx = i
        l = 2 * i + 1
        r = 2 * i + 2

        if l < n and arr[max_idx] < arr[l]:
            max_idx = l
        
        if r < n and arr[max_idx] < arr[r]:
            arr[i], arr[max_idx] = arr[max_idx], arr[i]
            headpify(arr, n, largest)
        
        
def merge_sort(arr: List[int]) -> None:
    if len(arr) <= 1:
        return arr

    m = floor(len(arr) / 2)
    l = merge_sort(arr[:m])
    r = merge_sort(arr[m:])

    result = merge(l, r)
    print(f"{result=}(not sorted)") if not is_sorted(arr) else print("\tordered")
    
    return result

def merge(llist: List[int], rlist: List[int]):
    result = [] 
    i = k = 0

    while i < len(llist) and k < len(rlist):
        if (llist[i] < rlist[k]):
            result.append(llist[i])
            i += 1
        else:
            result.append(rlist[k])
            k += 1

    result += llist[i:]
    result += rlist[k:]

    
    return result


if __name__ == '__main__':
    n = int(sys.argv[1])    
    a1 = gen_arr(n)
    print(f"{a1=}") if n > 100 else print("collapsed")

    test_sort(insertion_sort, a1)
    test_sort(biinsertion_sort, a1)
    test_sort(shell_sort, a1)
    test_sort(bubble, a1)
    test_sort(quick_sort, a1)
    test_sort(merge_sort, a1)


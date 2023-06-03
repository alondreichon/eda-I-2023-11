import matplotlib.pyplot as plt
import random

times = 0

def insertionSort(n_lista):
    global times
    for index in range(1, len(n_lista)):
        times += 1
        actual = n_lista[index]
        posicion = index
        while posicion > 0 and n_lista[posicion - 1] > actual:
            times += 1
            n_lista[posicion] = n_lista[posicion - 1]
            posicion = posicion - 1
        n_lista[posicion] = actual
    return n_lista

def partir(arr, low, high):
    i = low - 1
    pivot = arr[high]

    for j in range(low, high):
        if arr[j] <= pivot:
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quickSort(arr, low, high):
    if low < high:
        pi = partir(arr, low, high)

        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)

def mergeSort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = arr[:mid]
    right = arr[mid:]

    left = mergeSort(left)
    right = mergeSort(right)

    return merge(left, right)

def merge(left, right):
    merged = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1

    while i < len(left):
        merged.append(left[i])
        i += 1

    while j < len(right):
        merged.append(right[j])
        j += 1

    return merged

TAM = 101
eje_x = list(range(1, TAM, 1))
eje_y_insertion = []
eje_y_quick = []
eje_y_merge = []

for num in eje_x:
    lista_variable = random.sample(range(0, 1000), num)
    times = 0
    insertion_sorted = insertionSort(lista_variable.copy())
    eje_y_insertion.append(times)

    times = 0
    quick_sorted = lista_variable.copy()
    quickSort(quick_sorted, 0, len(quick_sorted) - 1)
    eje_y_quick.append(times)

    times = 0
    merge_sorted = mergeSort(lista_variable.copy())
    eje_y_merge.append(times)

fig, ax = plt.subplots(facecolor='w', edgecolor='k')
ax.plot(eje_x, eje_y_insertion, marker='o', color='purple', linestyle='None')
ax.plot(eje_x, eje_y_quick, marker='o', color='pink', linestyle='None')
ax.plot(eje_x, eje_y_merge, marker='o', color='lightblue', linestyle='None')

ax.set_xlabel("x")
ax.set_ylabel("y")
ax.grid(True)
ax.legend(["Insertion Sort", "QuickSort", "MergeSort"])

plt.title("Comparación de algoritmos de ordenamiento")
plt.show()

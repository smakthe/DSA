def quick_sort(array, low = 0, high = nil)
    return array if array.length < 2
    high ||= array.length - 1
    if low < high
      pivot_index = partition(array, low, high)
      quick_sort(array, low, pivot_index-1)
      quick_sort(array, pivot_index+1, high)
    end
    array
end

def partition(array, low, high)
  pivot = array[high]
  i = low - 1
  for j in low...high
    if array[j] <= pivot
      i += 1
      array[i], array[j] = array[j], array[i]
    end
  end
  array[i+1], array[high] = array[high], array[i+1]
  i+1
end

array = [38, 27, -43, 3, -9, 82, -10, 19]
p "Unsorted array: ", array
sorted_array = quick_sort(array)
p "Sorted array: ", sorted_array

def merge_sort(array)
  return array if array.length < 2
  left_half = array[0...array.length/2]
  right_half = array[array.length/2...array.length]
  sorted_left = merge_sort(left_half)
  sorted_right = merge_sort(right_half)
  merge(sorted_left, sorted_right)
end

def merge(left, right)
  sorted_array = []
  until left.empty? || right.empty?
      sorted_array << (left.first <= right.first ? left.shift : right.shift)
  end
  sorted_array + left + right
end

array = [38, 27, -43, 3, -9, 82, -10, 19]
p "Unsorted array: ", array
sorted_array = merge_sort(array)
p "Sorted array: ", sorted_array
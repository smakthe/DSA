def insertion(a)
  for i in 1...a.length
    key = a[i]
    j = i-1
    while j >= 0 && key < a[j]
      a[j+1] = a[j]
      j -= 1
    end
    p a
    a[j+1] = key
    p a
  end
  a
end

p insertion([2,1,-3,4,17,-5,37,8])
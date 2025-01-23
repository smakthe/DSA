def selection a
    for i in 0...a.length-1
        min = a[i]
        min_index = i
        for j in i+1...a.length
            if a[j] < min
                min = a[j]
                min_index = j
            end
        end
        a[i],a[min_index] = a[min_index],a[i]
    end
    a
end

p selection [2,1,-3,4,17,-5,37,8]
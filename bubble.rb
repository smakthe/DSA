def bubble a
    for i in 0...a.length
        for j in 0...a.length-i-1
            a[j],a[j+1] = a[j+1],a[j] if a[j] > a[j+1]
        end
    end
    a
end

p bubble [2,1,-3,4,17,-5,37,8]

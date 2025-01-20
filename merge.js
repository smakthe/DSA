const mergeSort = (a) => {
    if(a.length < 2) return a
    let left = a.slice(0,a.length/2)
    let right = a.slice(a.length/2, a.length)
    let sortedLeft = mergeSort(left)
    let sortedRight = mergeSort(right)
    return merge(sortedLeft,sortedRight)
}

const merge = (left,right) => {
    let sorted = []
    while(left.length > 0 && right.length > 0){
        left[0] <= right[0] ? sorted.push(left.shift()) : sorted.push(right.shift())
    }
    return sorted.concat(left,right)
}

a = [7,-1,5,-11,60,2,1,8]
console.log("Unsorted Array: ",a);
console.log("Sorted Array: ",mergeSort(a))
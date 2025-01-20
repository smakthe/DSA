const quickSort = (a,low=0,high=null) => {
    if (a.length < 2) return a
    high = high === null ? a.length-1 : high
    if(low < high){
        pivot_index = partition(a,low,high)
        quickSort(a,low,pivot_index-1)
        quickSort(a,pivot_index+1,high)
    }
    return a
}

const partition = (a,low,high) => {
    pivot = a[high]
    i = low -1
    for(j=low;j<high;j++){
        if(a[j] <= pivot){
            i++
            [a[i], a[j]] = [a[j], a[i]]
        }
    }
    [a[i+1], a[high]] = [a[high],a[i+1]]
    return i+1
}

a = [7,1,5,-11,60,8,-1,2]
console.log("Unsorted Array: ",a);
console.log("Sorted Array: ",quickSort(a))
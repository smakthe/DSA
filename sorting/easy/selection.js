a = [7,5,3,1]
console.log(a)

for(i=0;i<a.length-1;i++){
    let min = a[i]
    let min_index = i
    for(j=i+1;j<a.length;j++){
        if(a[j]<a[i]){
            min = a[j]
            min_index = j
        }
    }
    if(a[i]>a[min_index]) [a[i],a[min_index]] = [a[min_index],a[i]]
}

console.log(a)
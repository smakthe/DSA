a = [7,5,3,1]
console.log(a)

for(i = 1;i < a.length;i++){
    key = a[i]
    j = i - 1
    while(j >= 0 && key < a[j]){
        a[j+1] = a[j]
        j--;
    }
    a[j+1] = key
}

console.log(a)
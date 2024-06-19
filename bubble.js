arr = [7,5,3,1]
console.log(arr)

for(i=0;i<arr.length;i++){
    for(j=0;j<(arr.length-i-1);j++){
        if(arr[j]>arr[j+1]){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
        console.log(arr)
    }
}

console.log(arr)
a = [7,5,3,1]
console.log(a)

for(i=0;i<a.length;i++){
    for(j=0;j<(a.length-i-1);j++){
        if(a[j]>a[j+1]){
            temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
    }
}

console.log(a)
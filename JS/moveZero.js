function moveZero(n){ 
let j = 0; 
for (let i = 0; i < n.length ; i++){ 
    if (n[i] != 0){
      [  n[i], n[j]] = [n[j] , n[i]];
      j++; 
    }
}
return n
}
let n = [1, 3, 0, 3]; 
console.log(moveZero(n)) ; 

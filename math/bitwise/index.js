console.log((13).toString(2)) 

function decToBinary(n ){ 
let ans = "" ; 

while ( n > 0 ){ 
ans = (n % 2) + ans; 
n = Math.floor(n / 2) ; 

}
return ans; 


}

console.log(decToBinary(21)); 
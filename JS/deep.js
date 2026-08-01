// function recursiveFlattern(input) {
//   return input.reduce(
//     (acc, val) =>
//       Array.isArray(val) ? acc.concat(recursiveFlattern(val)) : acc.concat(val),
//     [],
//   );
// }

// let arr = [1, 2, 3, [4, 5, 6], [7, 8, [9, 10, [11]], 12], [13,[ 14, [15]]]] ; 
// console.log(recursiveFlattern(arr)) 


function flattenRecursive(arr ,n) {
    let depth = []; 
    for ( let item of arr ){
 if ( Array.isArray(item) &&  n > 0) {
            depth.push(...flattenRecursive (item, n -1))
        } 
        else {
            depth.push(item)
        }
    }
     


    return depth; 
}
let arr = [1, 2, 3, [4, 5, 6], [7, 8, [9, 10, [11]], 12], [13,[ 14, [15]]]] ; 
let n= 1; 
console.log(flattenRecursive(arr , n)) ; 

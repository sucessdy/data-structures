function prefixSum(arr) {
  let n = arr.length;
  if (n == 0) {
    return 0;
  }
  let prefix = new Array(n);

  prefix[0] = arr[0];
  for (let i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + arr[i];
  }

  return prefix;
}

let arr = [4];

// let ans = prefixSum(arr) ;

console.log(prefixSum(arr));

// for (const i of ans){
// console.log(i) ;
// }

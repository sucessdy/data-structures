// // Data Types & Variables 
// // 1️⃣ What will be the output and why?
// let a = 10
// let b = "10" 

// console.log(a + b) // 10 is number convert to the string and (+) with string value.... its string concatenation in js  10 + "10" = "1010" if we want to change the into a number we have to excplitice write Number("10") or so.. 
// console.log(a - b) // 0 in minus its normal one.. no contatenation here.. its minius so.. simpe number minus withnumber.. 0 
// console.log(typeof (a + b)) // string 
// console.log(typeof (a - b)) // number

// // 2️⃣ Predict output

// let x = null
// let y = undefined

// console.log(typeof x) // object is a bug in a js 
// console.log(typeof y) // undefined
// console.log(x == y) // true  "check the value not data type so...true"
// console.log(x === y) // false  "check the data type more stricter than double equal"

// // 3️⃣ What will happen?

// const user = {name: "Ram"}

// user.name = "Shyam"; 
// console.log(user)
// // user.name = "mukta"; 
// user = {name: "Mohan"}
 
// user = {name: "Mohan"}
    // this is const, and we re-declare this object 

// err message
// user = {name: "Mohan"}
// TypeError: Assignment to constant variable.

// const can't be redeclared  and we cant write int hte next line 
// Explain why.

function SearchInsertPosition(nums, target) { 
var st = 0;
var end = nums.length ; 
while (st  < end) { 
   var mid = Math.floor((st + end) / 2)
    if ( nums[mid] === target) {

        return mid ;
        
    }
    else if ( nums[mid] < target) { 
        st = mid + 1 ;
  
    }else { 
end = mid ; 

    }

}
return st ; 


}
let nums = [1,3, 5 ] ;
let target =   7 ; 


console.log(SearchInsertPosition(nums, target)) ; 

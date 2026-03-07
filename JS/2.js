// 🟢 Section 2 — Truthy / Falsy + Logical Operators

// 4️⃣ Predict output

console.log(Boolean("0")) // truty
console.log(Boolean(0)) // falsy
console.log(Boolean([])) // true
console.log(Boolean({})) // true

// 5️⃣ What will be printed?

let a = 0                                   
let b = "Hello"

console.log(a || b) // "Hello" -> or check value from LEFT to right -> and check the truty value ot falsy (0) is faslfy value so.... to the b .which is truthty
console.log(a && b) // 0  -> check the value from left to right and check the falsy value... first one 

// Explain how JS decides this.
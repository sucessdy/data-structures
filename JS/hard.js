// hard test  

// Question 1 — call, apply, bind

// What is the difference between:

// call()
// apply()
// bind()

// And what is the output?

// const user = {
//   name: "Mukta"
// };

// function greet(city, country) {
//   console.log(this.name, city, country);
// }

// greet.call(user, "Delhi", "India");
// greet.apply(user, ["Delhi", "India"]);

// const fn = greet.bind(user, "Delhi");
// fn("India");

// Explain what this becomes in each case.
// Mukta Delhi India
// Mukta Delhi India
// Mukta Delhi India


// call , apply , bind used for  sharing a method..like how we share this with each other... 
// without created  

// let's start from  call -> this call is invoked function immediaelty , this in a context is speteated arugents , and we call the parameters sequencacy this sepreate the common

// apply  is very similare to call  this call is invoked function immediaelty , but the difference here is we only in arguments we pass the single array or single object.

// unlike the other two .  bind is different 
// this is doesnt eun  this call is invoked function immediaelty , 
// this first create a  breand new copy object and stored in a new object.. then we invokked the function and this context permanently locked to the provided object when. u need. u can call tat later.. in the ru times 



// Question 2 — How does new work?

// What happens internally?

function User(name) {
  this.name = name;
}

const user = new User("Mukta");
console.log(user) 
// Without saying "it creates an object."

// Tell me the actual steps JavaScript performs.

// new keywords 

// user - defined  

// let develpoer create a user-defined consstructor object type or of one of the built-in object types that has a constructor function. 
// first we create a blank obejct in js and allocate in memory.  

// the internal set the prototype  of this new construtueor with new 

// Creates a blank object: It generates a brand-new, empty JavaScript object ({}).Links the prototype: It sets the internal [[Prototype]] (__proto__) of this new object to point to the constructor function's prototype object, enabling prototypal inheritance.Binds this: It invokes the constructor function while binding the newly created object to the this context. Any reference to this inside the function now modifies the new object.Returns the object: It automatically returns the new object. If the function explicitly returns a different non-primitive object, that object is returned




// Implement Array.prototype.map

// Suppose map didn't exist.

// Write your own version:

Array.prototype.myMap = function(cb) {
   // ? 'this' refers to the array instance the method was called on

let newArray = [] 
   for(let i = 0; i < this.length ; i++){
      // Check to handle sparse arrays (skip unassigned/empty slots) 
    if (this.hasOwnProperty(i)){ 
     

      //  Callback accepts: currentElement, index, originalArray
      newArray[i] = cb(this[i], i , this);
    }
   }
   return newArray ; 
}
// console.log(myMap.prototype)
// Expected:


const arr = [1, 2, 3];

const result = arr.myMap(x => x * 2);

console.log(result);

// Output:

// [2, 4, 6] 



// Question 4 — Promise.all

// What should happen here?

Promise.all([
  Promise.resolve(1),
  Promise.resolve(2),
  Promise.resolve(3)
]);

// this is this built for running the  asyncrous operation concurrently 



// What does it return?
// sucess : 1, sucess  : 2, sucess :3 
// this all is reolved.. means sucessdfully exuecuted the promoise mltuliple operation with out any reject promise ..  this returrdn us the reolved pormise 
// And:

// Promise.all([
//   Promise.resolve(1),
//   Promise.reject("error"),
//   Promise.resolve(3)
// ]);

// here we reject 
// means all the rejects immediately if any input promise won't even run ....

// error first / / we see 


// What happens?
// now engohg i tired all this   promble i have to write a lot.. 
// Why?
// 

console.log("A");

setTimeout(() => {
  console.log("B");
}, 0);

Promise.resolve().then(() => {
  console.log("C");

  setTimeout(() => {
    console.log("D");
  }, 0);
});

console.log("E");
// output 


// A
// E
// C
// B
// D

// i write simply 
// not too long paragraph Heer  ok 

// A and E are synchronous code which run immedialty excuted line by line.. immmedialty cux js is a single thread 

// C B D  Promise and SetTimeout send to the the webAPI, concpetyually i'm teelling. u... then we placed promise in a microtask queue and first pirortyy order we need to floolwo here c.. then second pripority set
// setTimeout  callbacks are placed in the macrotask queue, first microtassk queue  which is being  processed before macrotasks such as setTimeout callbacks. 
// then  eventlopp one by one pick from microtask and push to the call stack. and excaute the code.. and draind the whole microtask first then moved to the macrotask quuee..
// then even the setITimeout is 0 micro second.. need to fulfil the whole cycle. of eventloop hahahaa

// then eventloop pick form macrotask then TimeRange see and psuhed that in callstacked and excuted the Code and pop out of the stack value print  

// end  here.. i 'm tired 


// Question 6 — Mini Event Emitter
//  a core design pattern in JavaScript used for event-driven, asynchronous communication
// Imagine you're building a tiny version of Node.js events.

// Usage:
const EventEmitter = require('events');
const emitter = new EventEmitter();

emitter.on("login", () => {
  console.log("User logged in");
});

emitter.emit("login");
// .on(): Registers a listener that triggers every time the event fires.\
// .emit(): Triggers the event and passes arguments to the listeners 
// this is don't know in depth  
// Output:

// User logged in

// How would you store events?

// What data structure would you use?

// You don't need full code.

// Just explain the design 
"use strict"
// this kewords is a globle object its works differently in a strict mode and non-strict mode 
// this is a window object... aslo w ecan see this.. broswer console. 
// arrow function don' t have any this binding .. encosling lexical scope... 
// normal function have this binding  


// const user = {
//   name: "Mukta",

//   greet() {
//     console.log(this.name);
//   }
// };

// user.greet();
//  here the answer = Mukta 
// why  greet is a normal function here.. 
// this keyword depend on how we call this fucntion this is called window  
// normal object using method name = mukta
// and greet function know this binding  
// user.greet () remember that name isk                         



// const user = {
//   name: "Mukta",

//   greet() {
//     const inner = () => {
//       console.log(this.name);
//     };

//     inner();
//   }
// };

// user.greet(); 
// this kwywods works differenlty  here also 
// now, here u write a function inside  with a  arrow function 
// still the anwer is same mukta 
// but the excuation is very different this donest  have any binding only global scape ..


// this is not present any window object is not present / only globbal scope is there... 
 
// if we console.log(user)
// we get to see something like name: "mutka" , greet : function 
// so, this is present as a reference Object name.. is present so we get to see that


// Question 2 — Event Loop

// Imagine this code:

console.log("A");

setTimeout(() => {
  console.log("B");
}, 0);

console.log("C");
// ans : 
// A 
// C  
// B  


// What is the output?

// And explain:

// Call Stack
// call stack first we must know  this
// A call stack is a place where our JS code runs .... line by line 
// start initilixation at the top /
// function A call 
// first at the base  
// then second B fuction call move at the top of fucnt a. 
// then after excution the function B and pop out of the stack then fucntio A opop out of the stack..  
// it LIFO. data sturture  
//Last-In, First-Out (LIFO)

// Web APIs
// interact with a browser environment to expose advanced capabilities that are not meant fo JS langaue itself.. 
// I was   shokced that... setITmeout is not a part of JS and promise and APis and DOm 
// some fucntion  or method are are not builit in JS language itself ... so ex liek setTImeout is not invented from JS ..we use settimeout.. for exposing with a broweser not JS stuff 

// Callback Queue / tAsk queue / MacroTask Queue 
// call back queue is a waitng room.. we can think off
// holds callback functions from asynchronous operations until they are ready to be executed




// Event Loop
// continuously checks the call stack and, if empty, moves tasks from the queue to the stack for execution.

// as if you're teaching a beginner.


// Lets start from basic  

// console.log (A) is a synchrouns code which run immedatly 
// then console.log(C)  this is also a synchrous code run immedatly ... line by line.. 

// consol.elog(B) i a a asyncours code... 
// then setTimeout is a asynchrous operation so first callstack send that..to webAPI 
// webAPi see that this task is a async operation .. so...push this too maccrotask queue for a staging area ..for wait until call stack is emoty eventloop checks. if a calll stack is empty thn this pusht the reminig mircotask first... but here we don't have any thne macrotask quue.. loaded  in the call stack..  when the callstack is excaution the code ten pop out the stack 




// Question 3 — Promise Output #1

// Predict the output:

console.log("Start");

Promise.resolve().then(() => {
  console.log("Promise");
});

console.log("End");

// Output?
// first the synchronous code runs immediately   
// start  
// then end  
// now Here is a Promise this behave little different as compare too  setTimeout

// First call stack send the Promise to the webapi to interact with a browser .. events then this send to the high priority queue : microtask queue   this also the wait the promise here..we fully drained the micro task quuee before runing any code from macrotask queue..
// high prioty is promise then event loop checks if a call stack is empty ot Not  
//  call stack empty now event loop push the promise to the call stack then exuation the code thne pop out 
// And explain why. 
// ans  
// start 
// "end" 
// "Promise " A promise represents the eventual result of an asynchronous operation. has three stage -> fulfilled , pending,rejected.
// 

console.log("1"); /// JS is a singles theading lanquage... so synchrous code run immedietly where as asynchrous code is running in a backgroud so its don't block main thread.. where syhcorus code block the main thread .. 

setTimeout(() => {  // same.. cycle but this sendt call stack to.  websapi to macrottask queue.. this is exuted after whole microtask is drained at last.... then our eventloop check the ccalll stack is mepty or not.. then at last this excute the code... and opo out of the srtack 
  console.log("2");
}, 0);

Promise.resolve().then(() => { // call stack push this to the webapis its a async code so we  expose with broweser.. here.. some function is not present in js itself...like dom, event , fetch , settimeout,setImeinteval 
    // here promise.  send to the high prioty queue   whcih is mircotask queue... this drained fully event loop check and if call stck is empty then psuh this... code and callstack happy. excauted the cod.e. then pop out  
  console.log("3");
});

// console.log("4"); then this synchronous  code runs even if 1000 lines is written here... this will excaute line by line... 
// where as asynchrous code   wait until all the code.. is excauted or print after a certain time interval 

// // outut  
// 1 
// 4
// 3
// 2

// Question 5 — Prototype Chain

// What is the output?

const obj = {
  city: "Delhi"
};

const user = Object.create(obj);

console.log(user.city);


// output is Delhi  

// Why does it work even though city isn't inside user?
// In js everything is a object means Array, fucntiom , string is obeject next 
// JavaScript object possesses a hidden, internal link to another object called its prototype. When you try to access a property or method that does not exist directly on an object, JavaScript automatically searches upward through this chain of linked prototypes until it either finds the property or hits the end of the chain, which is null.

// Explain the Prototype Chain in your own words.

// So , we're able to  child - parent -> obejct.proto -> null 
// i do't want to tell mor...  


// Question 6 — Build Debounce

// Write a debounce function.

// Something like:

// const debouncedSearch = debounce(search, 500);

// If a user types:

// h
// he
// hel
// hell
// hello

// very quickly, search() should run only once after 500ms.

// You don't need perfect syntax.

// Just try to write the logic.Question 6 — Build Debounce

// Write a debounce function.

// Something like:

// const debouncedSearch = debounce(search, 500);

// If a user types:

// h
// he
// hel
// hell
// hello

// very quickly, search() should run only once after 500ms.

// You don't need perfect syntax.

// Just try to write the logic.\
const debounce = (func, delay) => {
    let timerId ;
    return function  (...args) { 
        clearTimeout(timerId)
        timerId = setTimeout(()=> { 
func.apply(this, args)
        }, delay)
    }
}

const handleDebounce = debounce(() => {
    console.log("hello world")
}, 500)

document.getElementById("input").addEventListener( 'input',  (e) => { 
    handleDebounce(e.target.value)
})
// handleDebounce()


// THIS IS FUNCTION/ FPR DEBOUNCE U CAN CHECK THIS 
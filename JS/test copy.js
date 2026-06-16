// Question 1 (Simple but common)
// console.log(a);
// var a = 10;
// ans -> undefined  
// var is a function scope...so the variable is present in a 

// global scope  

// i know the memory code and data code 
//   js create  excution context when js code run with memory assign with variable with undefiend .. something like  undefined some value.. can think as empty 
// then at the , after the code exution run we assgin the variable value...  obut here... we don't asssign any vlaue.. we using the value .even before we assign something... we're printed first. and then assignong the value... in case of var... this is undefined.. but  in let and const directlt refercce error we get... 

// Question 2

// What is the difference between:

// var -> is a function scoped variables, we don't prefer to use in a variable to assign.. cuz this cus a major bug.. in a code
//  var a = 80;

// i can assign 
// var a = something 40   
// then a = hold 40 value not .. 80 so.. duplicate... value ..we can asssign which cua a major... bug.. cuz in a code.. base.. we moslty want ungique values... not ressgining.. or redecling .. must not.. do. 

// let
// let is a blocked scope   
// this created in a different scope  than var in a memory 
// let  we can rerassgin 
// let z = 1
// z= 4
// we can do tjat  
// but in scope is blocked   so... outside scope can't access this.. 

// let is more safer than var but still...we prefer const.


// const

// this is   most safertest 
// const is also a blocked scope /

// const cant be redecalred or ressigned we can;t we must tell everyhting in a one line  
// const gives us error...  if we ever try to reassign something 

// const a = 90 
// then we can't do a =44
// this is not allowed so

// Don't give one-line answers. Explain like you're teaching a junior developer.

// Question 3

// What is a closure?

// A closure is combination of function bundloed togetter.. to its lexical envionment bunled together and formermed a closure.. 
function z () { 
      let s= 0
    function a () { 
      
console.log(s)
    }
    a()
    console.log("z")
}

z()
//  this is clousere/... example/// 

// fist call 0  
// econds z  

// Can you give a real-world example where closures are useful?
// So, we use for data privacy  
// for . Closures allow you to shield sensitive information from the rest of your application, p
// Closures are useful in event handlers where the handler needs access to some variables that are out of its initial scope. 
// Question 4

// What is the output?

// for (var i = 0; i < 3; i++) {
//   setTimeout(() => {
//     console.log(i);
//   }, 1000);
// }

// Why?
// so its tpical anwer  ans 3 3 3 three times... 
// cuz its var  variables 
// u know... its   we iterate our loop for the first.. times.... its cratedd at a function scoped...  not in a separated scope 
// so its change the same variables value  
// seconds interation change to 2 then same value change to 3 at the last ..  than 3 prints thrie times... cuz of change memeory is changnig 

// And how would you make it print:
// we can use the let  / to print 1 ,2  3.. its totoally created at a differetn blockked scope... so different value each times... 
// 0
// 1
// 2
// Question 5 (Senior-level thinking)

// Suppose a button is clicked 100 times in 1 second.
// i will use debounce heree
// debounce is a technique  that delay the excution of fucntion for a specfic time has passed 
// measn   button is clicked is mostly prefer...hree 
// use case . Search boxes, auto-saving forms, checking username availability. 


// when the user stop the keystroke the event fire then ..  not for a fixed time interval 
// unlink in throttle   Limits the function to run at a steady, fixed rate (e.g., once every 300ms) regardless of how frequently the event fires.  use case Window resizing, scrolling effects, game controls (shooting). 


// Should you use:

// Debouncing
// Throttling

// Explain the difference and when to use each.


const student =  { 
name : "mukta", 
class : function() { 
console.log(this)
}
}
student.class()
// student.name ()
const student2 ={ 
    name : 20 
}



student.class.call(student2)
// call  apply  
// bind  (shares method) 
const user = {
  name: "Mukta",

  greet() {
    console.log(this.name);
  }
};

user.greet(); 
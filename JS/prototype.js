function a (num) {
    return num * 5
}
a.power= 3; 

console.log(a.power)
console.log(a.prototype)
console.log(a(7))

function createUser (user, score){
    this.user = user, 
    this.score = score
}

createUser.prototype.increment = function() {
    this.score++; 

}

createUser.prototype.print = function () {
    console.log(
        `score is : ${this.score}`
    )
}

const username  = new createUser("mutka", 32)
const username1 = new  createUser("krish", 24)

username.print() 
username1.print()



// here the prototype 

const str = "mutka.  "
const st2 = "mumtqama.     "
console.log(str.trueLength)
console.log(st2) 

const iceCream = ["vanilla", "chocolate" , "straberry"]

 const flavour = {
    vanilla : "ice cube", 
    chocolate : "cone", 
    filling : function () { 
        console.log(` filling :  ${this.chocolate}`) 
    }
 }

Object.prototype.getfn = function() { 
    console.log("this get my ice cream")
} 

iceCream.getfn()
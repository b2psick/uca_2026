// let map1 = new Map([name, "rahul"])
// map1.set("age", 20)

obj1 = {
    "name":"rahul"
}

//object using create
var obj2 = Object.create(obj1)

var sourceObject = {
    "name":"woohoo"
}

var targetObject = {"age":18}

//object using assign
var obj3 = Object.assign(sourceObject, targetObject)

// console.log(obj3)

//object literal

const student1 = {
    name : "rahul",
    age : 30,
    email : "b2psick@gmail.com"
}

const student2 = {
    name : "b2p",
    age : 20,
    email : "b2p@gmail.com"
}

function createStudent(name, age, email, marks) {
    let maxMarks = 100;
    return {
        name : name,
        age : age,
        email : email,
        percentage : (function () {
            return (marks / maxMarks) * 100;
        })()
    }
}

const newStudent = createStudent("rahul", 19, "rahul@gmail.com", 49);

// console.log(newStudent);

function constructStudent(name, age, email, marks) {
    
    this.name = name;
    this.age = age
    this.email = email
    this.mark = marks

}
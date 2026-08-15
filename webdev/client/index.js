const worker = new Worker("./worker.js")

worker.postMessage("yooo")

worker.onmessage = (event) => {

    // if(event.data.error) {
    //     console.log(event.data.message)
    //     return
    // }

    let is = true
    // for(let i = 0; i < event.data.length; i++) {
    //     console.log(`${event.data[i].name}` + " - " + `${is ? "active" : "inactive"}`)
    //     is = !is
    // }

    //2nd ques

    let div = document.getElementById("users")

    if(event.data.error) {
        const p = document.createElement("p")
        p.textContent = "no users"
        div.appendChild(p)
        return
    }
    for(let i = 0; i < event.data.length; i++) {
        const p = document.createElement("p")
        p.textContent = `${event.data[i].name}` + " - " + `${is ? "active" : "inactive"}`
        div.appendChild(p)
        is = !is
    }

}









// const fields = [
//     "First Name",
//     "Last Name",
//     "Email"
// ]

// function generateForm() {
//     return fields.map(item => 
//         `<label>${item}</label>
//         <input type="text"></input>`
//     ).join("")
// }

// console.log(generateForm());

// const users = [
//     {name:"Alice", age:53},
//     {name:"Tim", age:74}
// ]

// function generateForm() {
//     return `<table>
//             ${users.map(item => `
//             <tr>
//                 <td>${item.name}</td>
//                 <td>${item.age}</td>
//             </tr>`).join("")}
//         </table>`
// }

// console.log(generateForm())
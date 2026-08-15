onmessage = async (event) => {
    try {
    const json = await fetch("https://jsonplaceholder.typicode.com/users")
    const data = await json.json()

    if(!data || data.length == 0) {
        postMessage({
            error : true,
            message : "no users"
        })
    } else {
        postMessage(data)
    }
    
    } catch (error) {
        postMessage({
            error : true,
            message : error.message
        })
    }
}
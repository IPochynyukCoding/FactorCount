function getFactorArray(number){
    const factorArray = []
    for(let i =1;i<Math.ceil(Math.sqrt(number));i++){
        if(number %i==0){
            factorArray.push(i)
            factorArray.push(Math.floor(number/i))
        }
    }
    if(Math.floor(Math.sqrt(number))**2 == number){
        factorArray.push(Math.floor(Math.sqrt(number)))
    }
    factorArray.sort((a,b)=> a>b ? 1 : a<b ? -1:0)
    return factorArray
}



let inputNumber = document.getElementById("inputNumber")
let outputArray = document.getElementById("results")
let isPrime = document.getElementById("isPrime")


document.querySelector('button[type="submit"]').addEventListener("click",function(e){
    console.log(inputNumber)
    if (isNaN(Number(inputNumber.value)) || Number(inputNumber.value) <= 0 || Number(inputNumber.value) != Math.floor(Number(inputNumber.value))){
        alert("This number is not an natural number, please try again!")
        e.preventDefault()
    }
    else{
        factorResults = getFactorArray(inputNumber.value)
        outputArray.innerText = `The factors of ${inputNumber.value} are ${factorResults}.`
        isPrime.innerText = `${inputNumber.value} ${factorResults.length == 2 ? "is" : "is not"} prime because it has ${factorResults.length} factors.`
    }
})
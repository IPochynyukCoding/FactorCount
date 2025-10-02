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
    factorArray.sort((a, b) => a - b)
    return factorArray
}



const inputNumber = document.getElementById("inputNumber")
const outputArray = document.getElementById("results")
const isPrime = document.getElementById("isPrime")


document.querySelector('button[type="submit"]').addEventListener("click",function(e){
    const inputValue = inputNumber.value
    if (isNaN(Number(inputValue)) || Number(inputValue) <= 0 || Number(inputValue) != Math.floor(Number(inputValue))){
        alert("This number is not an integer greater than zero, please try again!")
        e.preventDefault()
    }
    else{
        const factorResults = getFactorArray(inputValue)
        const numberOfFactors = factorResults.length
        outputArray.innerText = `The factors of ${inputValue} are ${factorResults}.`
        isPrime.innerText = `${inputValue} is ${numberOfFactors == 2 ? "" : "not"} prime because it has ${numberOfFactors} factor(s).`
    }
})
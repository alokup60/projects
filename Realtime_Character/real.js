const textareaE1 = document.getElementById("textarea")
const totalCounterE1 = document.getElementById("total-counter")
const remainCounterE1 = document.getElementById("remaining-counter")

textareaE1.addEventListener("keyup", () => {
    updateCounter()
})

//remove the data into the textarea

updateCounter()

function updateCounter() {
   totalCounterE1.innerText = textareaE1.value.length;
   remainCounterE1.innerText = textareaE1.getAttribute("maxLength") - textareaE1.value.length;
}
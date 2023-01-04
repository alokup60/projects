const containerE1 = document.querySelector(" .container ");
const carrers = ["Web Developer", "Freelancer", "Instructor", "Tutor"];

let carrerIndex = 0;
let characterIndex = 0;

upadateText();

function upadateText(){
    characterIndex++;
    containerE1.innerHTML = `<h1>I Am a ${carrers[carrerIndex].slice(0,characterIndex)}</h1>`;

    if (characterIndex === carrers[carrerIndex].length) {
        carrerIndex++;
        characterIndex = 0;
    }

    if (carrerIndex === carrers.length) {
        carrerIndex = 0;
    }

    setTimeout(upadateText, 400);
}
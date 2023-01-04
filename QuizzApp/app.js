const questions = [
  {
    que: "Which of the language is a markup language?",
    a: "HTML",
    b: "CSS",
    c: "Jscript",
    d: "PHP",
    correct: "a",
  },
  {
    que: "CSS stands for ?",
    a: "Casecading Stylesheet",
    b: "Cameron style shit",
    c: "cesarioa stylesheet",
    d: "cello smart service",
    correct: "a",
  },
  {
    que: "HTML stanmds for ?",
    a: "CAsecading Stylesheet",
    b: "Hypertext MArkup language",
    c: "cesarioa stylesheet",
    d: "cello smart service",
    correct: "b",
  },
  {
    que: "Capital of India ?",
    a: "Ballia",
    b: "Lucknow",
    c: "New Delhi",
    d: "Agra",
    correct: "c",
  },
  {
    que: "Capital of U.P. ?",
    a: "Ballia",
    b: "Lucknow",
    c: "New Delhi",
    d: "Agra",
    correct: "b",
  },
  {
    que: "Where is Tajmahal Located ?",
    a: "Ballia",
    b: "Lucknow",
    c: "New Delhi",
    d: "Agra",
    correct: "d",
  },
];

let index = 0;
let total = questions.length;
let right = 0,
  wrong = 0;
const quesBox = document.getElementById("quesBox");
const optionInputs = document.querySelectorAll(".options");
const loadQuestion = () => {
  if (index === total) {
    return endQuiz();
  }
  reset();
  const data = questions[index];
  quesBox.innerText = `${index + 1})${data.que}`;
  optionInputs[0].nextElementSibling.innerText =
    data.a; /* nextElementSibling = using radio going to the label which is the next of the radio button*/
  optionInputs[1].nextElementSibling.innerText = data.b;
  optionInputs[2].nextElementSibling.innerText = data.c;
  optionInputs[3].nextElementSibling.innerText = data.d;
};

const submitQuiz = () => {
  const data = questions[index];
  const ans = getAnswer();
  if (ans == data.correct) {
    right++;
  } else {
    wrong++;
  }
  index++;
  loadQuestion();
  return;
};

const getAnswer = () => {
  let answer;
  optionInputs.forEach((input) => {
    if (input.checked) {
      answer = input.value;
    }
  });
  return answer;
};

const reset = () => {
  optionInputs.forEach((input) => {
    input.checked = false;
  });
};

const endQuiz = () => {
  document.getElementById("box").innerHTML = `
  <div style="text-align:center">
  <h3>Thank You ! </h3> <h2> ${right}/${total} are correct </h2>
  </div>`;
};
//initial call
loadQuestion();

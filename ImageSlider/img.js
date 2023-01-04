const nextE1 = document.querySelector(".next");
const imgsEl = document.querySelectorAll("img"); //for length of the selector
const imageConEl = document.querySelector(" .image-container");

const prevEl = document.querySelector(".prev");

let currentImg = 1

let timeout;

nextE1.addEventListener("click", ()=> {
    currentImg++
    clearTimeout(timeout);
    updateImg()
})

prevEl.addEventListener("click", ()=>{
    currentImg--
    clearTimeout(timeout);
    updateImg()
})

updateImg()

function updateImg(){
    if (currentImg > imgsEl.length) {
        currentImg = 1;
    }else if (currentImg < 1) {
        currentImg = imgsEl.length;
    }
    imageConEl.style.transform = `translateX(-${(currentImg - 1) * 600}px)`;

    timeout = setTimeout(()=>{
        currentImg++
        updateImg()
    },3000)
}
let count = 0;
let counter = document.getElementById("counter");

function increment() {
  count++;
  counter.innerText = `The count is: ${count}`;
}

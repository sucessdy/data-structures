let arr = [0, 1, 0, 3, 12];

const container = document.getElementById("array");
function renderArray(i = -1, j = -1) {
  container.innerHTML = "";

  arr.forEach((num, index) => {
    const wrapper = document.createElement("div");
    wrapper.style.display = "flex";
    wrapper.style.flexDirection = "column";
    wrapper.style.alignItems = "center";

    const div = document.createElement("div");
    div.classList.add("box");

    if (num === 0) div.classList.add("zero");
    if (index === i) div.classList.add("pointer-i");
    if (index === j) div.classList.add("pointer-j");

    div.innerText = num;

    const label = document.createElement("div");
    label.classList.add("label");

    if (index === i && index === j) {
      label.innerText = "i, j";
    } else if (index === i) {
      label.innerText = "i";
    } else if (index === j) {
      label.innerText = "j";
    }

    wrapper.appendChild(div);
    wrapper.appendChild(label);
    container.appendChild(wrapper);
  });
}
async function moveZeroes() {
  let j = 0;

  for (let i = 0; i < arr.length; i++) {
    renderArray(i, j);
    await sleep(700);

    if (arr[i] !== 0) {
      [arr[i], arr[j]] = [arr[j], arr[i]];
      renderArray(i, j);
      await sleep(700);

      j++;
    }
  }

  renderArray(); // final clean state
}

function highlight(i, j) {
  const boxes = document.querySelectorAll(".box");

  boxes.forEach(box => box.classList.remove("active"));

  if (boxes[i]) boxes[i].classList.add("active");
  if (boxes[j]) boxes[j].classList.add("active");
}
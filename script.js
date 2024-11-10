const led1Butt = document.getElementById("led-pertama");
const led2Butt = document.getElementById("led-kedua");
const led3Butt = document.getElementById("led-ketiga");
const led4Butt = document.getElementById("led-keempat");

const led1gam = document.getElementById("ledgamsatu");
const led2gam = document.getElementById("ledgamdua");
const led3gam = document.getElementById("ledgamtiga");
const led4gam = document.getElementById("ledgamempat");
const span = document.querySelector("span");
function ledpertama() {
  led1Butt.style.backgroundColor = "red";
  led1gam.src = "./image/led-on.png";
  span.style.color = "red";
}
function ledkedua() {
  led2Butt.style.backgroundColor = "red";
  led2gam.src = "./image/led-on.png";
  span.style.color = "red";
}

function ledketiga() {
  led3Butt.style.backgroundColor = "red";
  led3gam.src = "./image/led-on.png";
  span.style.color = "red";
}

function ledkeempat() {
  led4Butt.style.backgroundColor = "red";
  led4gam.src = "./image/led-on.png";
  span.style.color = "red";
}

const led1Butt = document.getElementById("led-pertama");
const led2Butt = document.getElementById("led-kedua");
const led3Butt = document.getElementById("led-ketiga");
const led4Butt = document.getElementById("led-keempat");

const led1gam = document.getElementById("ledgamsatu");
const led2gam = document.getElementById("ledgamdua");
const led3gam = document.getElementById("ledgamtiga");
const led4gam = document.getElementById("ledgamempat");

const endpoint = "http://192.168.171.94";
const span = document.querySelector("span");

function getlampupertama() {
  fetch(endpoint + "/lampupertama", {
    method: "GET"
  }).then(response => response.text()).then(result => {
    if(result == "ON"){
      led1Butt.style.backgroundColor = "red";
      led1gam.src = "./image/led-on.png";
      span.style.color = "red";
    }
    else{
      led1Butt.style.backgroundColor = "blue";
      led1gam.src = "./image/led-off.png";
      span.style.color = "blue";
    }
  })
}
function setlampupertama() {
  fetch(endpoint + "/lampupertama", {
    method: "POST"
  }).then(response => response.text()).then(() => location.reload())

}


function getlampukedua() {
  fetch(endpoint + "/lampukedua", {
    method: "GET"
  }).then(response => response.text()).then(result => {
    if(result == "ON"){
      led1Butt.style.backgroundColor = "red";
      led1gam.src = "./image/led-on.png";
      span.style.color = "red";
    }
    else{
      led1Butt.style.backgroundColor = "blue";
      led1gam.src = "./image/led-off.png";
      span.style.color = "blue";
    }
  })
}
function setlampukedua() {
  fetch(endpoint + "/lampukedua", {
    method: "POST"
  }).then(response => response.text()).then(() => location.reload())

}


function getlampuketiga() {
  fetch(endpoint + "/lampuketiga", {
    method: "GET"
  }).then(response => response.text()).then(result => {
    if(result == "ON"){
      led1Butt.style.backgroundColor = "red";
      led1gam.src = "./image/led-on.png";
      span.style.color = "red";
    }
    else{
      led1Butt.style.backgroundColor = "blue";
      led1gam.src = "./image/led-off.png";
      span.style.color = "blue";
    }
  })
}
function setlampuketiga() {
  fetch(endpoint + "/lampuketiga", {
    method: "POST"
  }).then(response => response.text()).then(() => location.reload())

}

function getlampukeempat() {
  fetch(endpoint + "/lampukeempat", {
    method: "GET"
  }).then(response => response.text()).then(result => {
    if(result == "ON"){
      led1Butt.style.backgroundColor = "red";
      led1gam.src = "./image/led-on.png";
      span.style.color = "red";
    }
    else{
      led1Butt.style.backgroundColor = "blue";
      led1gam.src = "./image/led-off.png";
      span.style.color = "blue";
    }
  })
}
function setlampukeempat() {
  fetch(endpoint + "/lampukeempat", {
    method: "POST"
  }).then(response => response.text()).then(() => location.reload())

}

getlampupertama()
getlampukedua()
getlampuketiga()
getlampukeempat()
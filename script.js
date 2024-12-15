const led1Butt = document.getElementById("led-pertama");
const led2Butt = document.getElementById("led-kedua");
const led3Butt = document.getElementById("led-ketiga");
const led4Butt = document.getElementById("led4");

const led1gam = document.getElementById("ledgamsatu");
const led2gam = document.getElementById("ledgamdua");
const led3gam = document.getElementById("ledgamtiga");
const led4gam = document.getElementById("ledgam4");

const endpoint = "http://192.168.37.94";
const span = document.querySelector("span");

function getlampupertama() {
  fetch(endpoint + "/lampupertama", {
    // ambil endpoint/lampupertama
    method: "GET",
  })
  // jika hasil ada on of maka..
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        led1Butt.style.backgroundColor = "red";
        led1gam.src = "./image/led-on.png";
        span.style.color = "red";
      } else {
        led1Butt.style.backgroundColor = "blue";
        led1gam.src = "./image/led-off.png";
        span.style.color = "blue";
      }
    });
}
function setlampupertama() {
  fetch(endpoint + "/lampupertama", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => location.reload());
}

function getlampukedua() {
  fetch(endpoint + "/lampukedua", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        led2Butt.style.backgroundColor = "red";
        led2gam.src = "./image/led-on.png";
        span.style.color = "red";
      } else {
        led2Butt.style.backgroundColor = "blue";
        led2gam.src = "./image/led-off.png";
        span.style.color = "blue";
      }
    });
}
function setlampukedua() {
  fetch(endpoint + "/lampukedua", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => location.reload());
}

function getlampuketiga() {
  fetch(endpoint + "/lampuketiga", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        led3Butt.style.backgroundColor = "red";
        led3gam.src = "./image/led-on.png";
        span.style.color = "red";
      } else {
        led3Butt.style.backgroundColor = "blue";
        led3gam.src = "./image/led-off.png";
        span.style.color = "blue";
      }
    });
}
function setlampuketiga() {
  fetch(endpoint + "/lampuketiga", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => location.reload());
}

function getlampukeempat() {
  fetch(endpoint + "/lampukeempat", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        led4Butt.style.backgroundColor = "red";
        led4gam.src = "./image/led-on.png";
        span.style.color = "red";
      } else {
        led4Butt.style.backgroundColor = "blue";
        led4gam.src = "./image/led-off.png";
        span.style.color = "blue";
      }
    });
}
function setlampukeempat() {
  fetch(endpoint + "/lampukeempat", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => location.reload());
}

// DHT
const temperatureSpan = document.getElementById("temperature");
const humiditySpan = document.getElementById("humidity");

// Fungsi untuk membaca data DHT
function getDHTData() {
  fetch(endpoint + "/dht", {
    method: "GET",
  })
    .then((response) => response.json())
    .then((data) => {
      // Perbarui elemen dengan data suhu dan kelembaban
      temperatureSpan.textContent = data.temperature.toFixed(1);
      humiditySpan.textContent = data.humidity.toFixed(1);
    })
    .catch((error) => {
      console.error("Gagal membaca data DHT:", error);
      temperatureSpan.textContent = "--";
      humiditySpan.textContent = "--";
    });
}

// Panggil fungsi getDHTData setiap 0.5 detik
setInterval(getDHTData, 500);

// Panggil fungsi untuk mendapatkan data awal
getDHTData();

getlampupertama();
getlampukedua();
getlampuketiga();
getlampukeempat();

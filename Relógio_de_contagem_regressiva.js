let countdown = 60;

let clock = document.getElementById("clock");

function updateClock() {
  let minutes = Math.floor(countdown / 60);
  let seconds = countdown % 60;

  clock.innerHTML = `${minutes}:${seconds < 10 ? "0" : ""}${seconds}`;

  countdown--;

  if (countdown < 0) {
    clearInterval(intervalId);
    clock.innerHTML = "Tempo esgotado!";
  }
}

let intervalId = setIntervl(updateClock, 1000);

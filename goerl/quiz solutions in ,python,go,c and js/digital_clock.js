function myDigitalClock() {
  var d1 = new Date();
  var hours = d1.getHours();    // 0 - 23
  var minutes = d1.getMinutes();  // 0 - 59
  var seconds = d1.getSeconds();  // 0 - 59
  var zone = "AM";

  // Convert hours to 12-hour format and determine the AM/PM zone
  if (hours >= 12) {
    zone = "PM";
    hours = hours === 12 ? 12 : hours - 12;
  } else {
    zone = "AM";
    hours = hours === 0 ? 12 : hours;
  }

  // Add leading zeros for minutes and seconds if they are less than 10
  minutes = minutes < 10 ? "0" + minutes : minutes;
  seconds = seconds < 10 ? "0" + seconds : seconds;

  // Create a string representation of the digital clock
  var timeString = hours + ":" + minutes + ":" + seconds + " " + zone;

  // Display the digital clock on the webpage or console (for testing)
  console.log(timeString);
}

// Call the function to update the clock every second
setInterval(myDigitalClock, 1000);

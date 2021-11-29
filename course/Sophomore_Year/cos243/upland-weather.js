const moment = require('moment');
const request = require('request');

function accurateTime() {
    return moment().format("LT");
}

function timeStamp(message) {
    return `${message} ${accurateTime()}`;
}

request.get("https://api.openweathermap.org/data/2.5/weather?appid=32843bad9e96bb36c7935458544b1628&id=4927510&units=imperial",
    (error, degrees) => {
        if (error) {
            throw new Error("Request failed")
        }
        let x = JSON.parse(degrees.body); //turns text into object
        console.log(x);
        let y = x.main.temp; //iterates through the object to grab what I want. In this case it's the temperature.
        console.log(`${timeStamp('At')}, it's ${y} degrees.`); //Outputs what I need to output

    });
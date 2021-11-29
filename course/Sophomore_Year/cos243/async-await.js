//Loading node packages
const moment = require('moment');
const request = require('request');

// Report the weather; `result` is the JSON object returned from OWM.
function reportWeather(result) {
    console.log(`On ${moment()}, it's ${result.main.temp} degrees.`);
}

// Report an error.
function reportError(error) {
    console.log(`Something went haywire: '${error}'`);
}

function requestPromisified(uri, qs) {
    return new Promise((resolve, reject) => {
        request.get({uri:uri, qs:qs},
            (error, degrees) => {
                if (error) {
                    reject(error);
                }
                let x = JSON.parse(degrees.body); //turns text into object
                resolve(x);

            });
    });
}

// Get the time and temp using the promise directly.
function getTimeAndTempPromise(uri, qs) {
    requestPromisified(uri, qs)
        .then(data => reportWeather(data))
        .catch(err => reportError(err));
}

// Get the time and temp using async-await.
async function getTimeAndTempAsync(uri, qs) {
    try {
        let data = await requestPromisified(uri, qs);
        reportWeather(data);
    }
    catch (err){
        reportError(err);
    }
}

// Credentials to access Open Weather Map
const uri = "https://api.openweathermap.org/data/2.5/weather";
const qs = {
    id: "4927510",
    appid: "32843bad9e96bb36c7935458544b1628",
    units: "imperial"
};
// Invoke both versions of time-and-temp.
getTimeAndTempPromise(uri, qs);
getTimeAndTempAsync(uri, qs);

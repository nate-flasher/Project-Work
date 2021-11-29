const https = require('https');
const request = require('request');
const debug = true;

//questions: what is response.on exactly? how is this all working together? how is the syntax of requestOptions, response => working etc?
function prettyPrintJson(jsonObject) {
    return JSON.stringify(jsonObject, null, 2);
}

const randomOrgRequestOptions = {
    hostname: 'api.random.org',
    method: 'POST',
    path: '/json-rpc/2/invoke',
    headers: {'Content-Type': 'application/json'}  //tells random.org that we want a json response
};

const generateIntegersPostData = { //supplies payload to be sent to http post request
    "jsonrpc": "2.0",
    "method": "generateIntegers",
    "params": {
        "apiKey": "ccba1f8a-21ab-48c6-b62d-e8d34bb19c36",
        "n": 5,
        "min": 1,
        "max": 100
    },
    "id": 1
};

function randomOrgApiPromise(requestOptions, postData) {
    return new Promise((resolve, reject) => {
        const request = https.request(requestOptions, response => { //callback function gets called when request is complete.
            //Start of callback code, invoked when HTTPS request completes. Creates response object.

            const chunks = []; //Hold intermediate pieces of overall response.

            if (debug) {
                console.log(`STATUS: ${response.statusCode}`);
                console.log(`HEADERS: ${prettyPrintJson(response.headers)}`);
            }
            response.setEncoding('utf8');

            response.on('data', chunk => { //want access to an event called data. when data arrives call this anon function. we are signing up for this event
                //Got some data - hold on to it until we're all done.
                if (debug) {
                    console.log(`CHUNK: ${prettyPrintJson(JSON.parse(chunk))}`);
                    //console.log(`CHUNK: ${chunk}`);
                }
                chunks.push(chunk);
            });

            response.on('end', () => { //nothing to recieve because its the end of info
                //That's it for new data; here, just print out all the chunks.
                const content = chunks.join(''); //what is this doing? hooking chunks together!
                //console.log(`CONTENT (Callback):\n${prettyPrintJson(JSON.parse(content))}`);
                resolve(content);
            });

            //End of callback code. As in the end of using response.
        });


//Back to main thread of control. F
    request.on('error', err => {
        console.error(`Request error: ${err}`);
        reject(err); //we listened for an error and if it happeneds reject will catch it and tell the .catch function.
    }); //ending this request.on of error

//Send the request data.
    request.write(JSON.stringify(postData));
//Can also SEND multiple chunks, but we're done for now.
    request.end();
    });
}

randomOrgApiPromise(randomOrgRequestOptions, generateIntegersPostData)
    .then(content => console.log(`CONTENT (Promise):\n${prettyPrintJson(JSON.parse(content))}`))
    .catch(error => console.log(`BUMMER: ${error}`));
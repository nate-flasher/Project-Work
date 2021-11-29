const knex = require('knex')({
    client: 'pg',
    connection: {
        host: 'faraday.cse.taylor.edu',
        user: 'readonly',
        password: 'nerds4christ',
        database: 'dvdrental'
    }
});

function TEMP(newDriver) {
    return new Promise((resolve, reject) => {
        knex('Driver')
            .insert(newDriver)
    });
}

function NAME(){
    return new Promise((resolve, reject) => {
        knex
    });
}

function NAME(){
    return new Promise((resolve, reject) => {
        knex
    });
}

function NAME(){
    return new Promise((resolve, reject) => {
        knex
    });
}


const Hapi = require('@hapi/hapi');

const init = async () => {
    // Create a new Hapi server
    const server = Hapi.server({
        host: 'localhost',
        port: 3000
    });

    // Output endpoints at startup.
    await server.register({plugin: require('blipp'),
        options: {showAuth: true}});

    // Log stuff.
    await server.register({
        plugin: require('hapi-pino'),
        options: {
            prettyPrint: true
        }
    });

    server.route([
        {
            method: 'POST',
            path: '/driver/',
            handler: (request, h) => {
            }
        },
    ]);

    server.route([
        {
            method: 'GET',
            path: '/films/{film_id}',
            handler: (request, h) => {
            }
        },
    ]);

    server.route([
        {
            method: 'GET',
            path: '/films',
            handler: (request, h) => {
            }
        },
    ]);

    // Start the server.
    await server.start();
}

// Catch promises lacking a .catch.
process.on('unhandledRejection', err => {
    console.error(err);
    process.exit(1);
});

// Go!
init();

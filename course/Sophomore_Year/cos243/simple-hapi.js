const knex = require('knex')({
     client: 'pg',
     connection: {
     host: 'faraday.cse.taylor.edu',
         user: 'readonly',
         password: 'nerds4christ',
         database: 'dvdrental'
     }
 });

    function country() {
        return new Promise((resolve, reject) => {
        knex
            .select('country_id', 'country')
            .from('country')
            .then(result => resolve(result))
            .then(() => knex.destroy());
    });
}

function getOneFilm(id){
    return new Promise((resolve, reject) => {
        knex
            .select('film_id', 'title', 'rental_rate')
            .from('film')
            .where('film_id', id)
            .then(result => resolve(result))
            .then(() => knex.destroy());
    });
}

function getMatchingFilms(matchingLetters){
    return new Promise((resolve, reject) => {
        knex
            .select('film_id', 'title', 'rental_rate')
            .from('film')
            .where('title', 'like', matchingLetters)
            .then(result => resolve(result))
            .then(() => knex.destroy());
    });
}

function getAllFilms(){
    return new Promise((resolve, reject) => {
        knex
            .select('film_id', 'title', 'rental_rate')
            .from('film')
            .then(result => resolve(result))
            .then(() => knex.destroy());
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
             method: 'GET',
             path: '/',
             handler: (request, h) => {
                  return 'Hello, Hapi';
                  }
              },
           ]);

     server.route([
         {
             method: 'GET',
             path: '/countries/',
             handler: (request, h) => {
                 return country();
             }
         },
     ]);

     server.route([
         {
             method: 'GET',
             path: '/films/{film_id}',
             handler: (request, h) => {
                 const film_id = request.params.film_id;
                 request.logger.info(`Request for details of film ${film_id}`);
                 return getOneFilm(film_id);
             }
         },
     ]);

     server.route([
         {
             method: 'GET',
             path: '/films',
             handler: (request, h) => {
                 const searchKey = request.query.title;
                 if(searchKey){
                     return getMatchingFilms(searchKey);
                 }
                 else{
                    return getAllFilms();
                 }
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




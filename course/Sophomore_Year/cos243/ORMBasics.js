
const knex = require('knex')({
    client: 'pg',
    connection: {
        host: 'faraday.cse.taylor.edu',
        user: 'readonly',
        password: 'nerds4christ',
        database: 'dvdrental'
    }
});

objection = require('objection');
const Model = objection.Model;
Model.knex(knex);



class Actor extends Model {
    static get tableName() {
        return 'actor';
    }
}
function message(){
    console.log();
}
function actors_starting_with(prefix) {
    Actor.query()
        .then(actors => {
            actors.forEach(actor => {
                if (actor.first_name.startsWith(prefix) || actor.last_name.startsWith(prefix)) {
                    console.log(`Actor ID: ${actor.actor_id}    Actor Firstname: ${actor.first_name}    Actor Lastname: ${actor.last_name}`);
                }
            });
            knex.destroy();
        })
        .catch(err => console.log(err.message));
}

actors_starting_with('F');






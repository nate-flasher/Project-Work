
const knex = require('knex')({
    client: 'pg',
    connection: {
        host: 'faraday.cse.taylor.edu',
        user: 'nate_flasher',
        password: 'sayuvezi',
        database: 'nate_flasher'
    }
});

objection = require('objection');
const Model = objection.Model;
Model.knex(knex);



class Authorization extends Model {   //DONE
    static get tableName() {
        return 'Authorization';
    }
    static get relationMappings() {
      return {
          driver: {
              relation: Model.BelongsToOneRelation,
              modelClass: Driver,
              join: {
                  from: 'Authorization.driverId',
                  to: 'Driver.id'  }

      },

      vehicle: {
          relation: Model.BelongsToOneRelation,
          modelClass: Vehicle,
          join: {
            from: 'Authorization.vehicleId',
            to: 'Vehicle.id'  }
          }

      }

    }
}
class Driver extends Model {  //DONE
    static get tableName() {
        return 'Driver';
    }
    static get relationMappings(){
      return {
        authorization: {
          relation: Model.HasManyRelation,
          modelClass: Authorization,
          join: {
            from: 'Driver.id',
            to: 'Authorization.driverId' }
        },

      drivers: {
        relation: Model.HasManyRelation,
        modelClass: Drivers,
        join: {
          from: 'Driver.id',
          to: 'Drivers.driverId'}
         }
      }

      }

    }

class Drivers extends Model { //DONE
    static get tableName() {
        return 'Drivers';
    }
    static get relationMappings() {
        return {
            driver: {
                relation: Model.BelongsToOneRelation,
                modelClass: Driver,
                join: {
                    from: 'Drivers.driverId',
                    to: 'Driver.id'  }

            },

            ride: {
                relation: Model.BelongsToOneRelation,
                modelClass: Ride,
                join: {
                    from: 'Drivers.rideId',
                    to: 'Ride.id'  }
            }

        }

    }
}
class Location extends Model { //DONE
    static get tableName() {
        return 'Location';
    }
    static get relationMapping(){
      return {
        state: {
          relation: Model.BelongsToOneRelation,
          modelClass: State,
          join: {
            from: 'Location.state',
            to: 'State.abbreviation'}
        },

        toRide: {
          relation: Model.HasManyRelation,
          modelClass: Ride,
          join: {
            from: 'Location.id',
            to: 'Ride.toLocationId'}
        },

        fromRide: {
          relation: Model.HasManyRelation,
          modelClass: Ride,
          join: {
            from: 'Location.id',
            to: 'Ride.fromLocationId'}
        },

      }
    }
}
class Passenger extends Model { //DONE
    static get tableName() {
        return 'Passenger';
    }
    static get relationMappings() {
        return {
            passengers: {
                relation: Model.HasManyRelation,
                modelClass: Passengers,
                join: {
                    from: 'Passenger.id',
                    to: 'Passengers.passengerId'  }
            }

        }

    }
}
class Passengers extends Model { //DONE
    static get tableName() {
        return 'Passengers';
    }
    static get relationMappings() {
        return {
            passenger: {
                relation: Model.BelongsToOneRelation,
                modelClass: Passenger,
                join: {
                    from: 'Passengers.passengerId',
                    to: 'Passenger.id'  }

            },

            ride: {
                relation: Model.BelongsToOneRelation,
                modelClass: Ride,
                join: {
                    from: 'Passengers.rideId',
                    to: 'Ride.id'  }
            }

        }

    }
}
class Ride extends Model { //DONE
    static get tableName() {
        return 'Ride';
    }

    static get relationMappings() {
        return {
            drivers: {
                relation: Model.HasManyRelation,
                modelClass: Drivers,
                join: {
                    from: 'Ride.id',
                    to: 'Drivers.rideId'
                }
            },
            passengers: {
                relation: Model.HasManyRelation,
                modelClass: Passengers,
                join: {
                    from: 'Ride.id',
                    to: 'Passengers.rideId'
                }
            },

            vehicle: {
                relation: Model.BelongsToOneRelation,
                modelClass: Vehicle,
                join: {
                    from: 'Ride.vehicleId',
                    to: 'Vehicle.id'
                }
            },

            fromLocation: {
                relation: Model.BelongsToOneRelation,
                modelClass: Location,
                join: {
                    from: 'Ride.fromLocationId',
                    to: 'Location.id'
                }
            },

            toLocation: {
                relation: Model.BelongsToOneRelation,
                modelClass: Location,
                join: {
                    from: 'Ride.toLocationId',
                    to: 'Location.id'
                }
            }
        }
    }
}
class State extends Model { //DONE
    static get tableName() {
        return 'State';
    }
    static get relationMappings() {
        return {
            location: {
                relation: Model.HasManyRelation,
                modelClass: Location,
                join: {
                    from: 'State.abbreviation',
                    to: 'Location.state'
                }
            }

        }


    }
}
class Vehicle extends Model {
    static get tableName() {
        return 'Vehicle';
    }
    static get relationMappings() {
        return {
            authorization: {
                relation: Model.HasManyRelation,
                modelClass: Authorization,
                join: {
                    from: 'Vehicle.id',
                    to: 'Authorization.vehicleId'
                }
            },
            ride: {
                relation: Model.HasManyRelation,
                modelClass: Ride,
                join: {
                    from: 'Vehicle.id',
                    to: 'Ride.vehicleId'}
            },

            vehicle_type: {
                relation: Model.BelongsToOneRelation,
                modelClass: Vehicle_Type,
                join: {
                    from: 'Vehicle.vehicleTypeId',
                    to: ' Vehicle Type.id'}
            },
        }
    }
}
class Vehicle_Type extends Model { //DONE
    static get tableName() {
        return 'Vehicle Type';
    }
    static get relationMappings() {
        return {
            vehicle: {
                relation: Model.HasManyRelation,
                modelClass: Vehicle,
                join: {
                    from: 'Vehicle Type.id',
                    to: 'Vehicle.vehicleTypeId'
                }
            }

        }


    }
}




async function query() {
    const test = await Driver.query();
    console.log(test);
}

query();








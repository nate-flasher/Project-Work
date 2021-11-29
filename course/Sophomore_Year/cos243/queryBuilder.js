const knex = require('knex')({
     client: 'pg',
     connection: {
     host: 'faraday.cse.taylor.edu',
         user: 'readonly',
         password: 'nerds4christ',
         database: 'dvdrental'
     }
 });

 knex //problem 1
     .select('category_id', 'name')
     .from('category')
     .then(result => console.log(result))
     .then(() => knex.destroy());

 //output from problem 1
 /*
 [
  { category_id: 1, name: 'Action' },
  { category_id: 2, name: 'Animation' },
  { category_id: 3, name: 'Children' },
  { category_id: 4, name: 'Classics' },
  { category_id: 5, name: 'Comedy' },
  { category_id: 6, name: 'Documentary' },
  { category_id: 7, name: 'Drama' },
  { category_id: 8, name: 'Family' },
  { category_id: 9, name: 'Foreign' },
  { category_id: 10, name: 'Games' },
  { category_id: 11, name: 'Horror' },
  { category_id: 12, name: 'Music' },
  { category_id: 13, name: 'New' },
  { category_id: 14, name: 'Sci-Fi' },
  { category_id: 15, name: 'Sports' },
  { category_id: 16, name: 'Travel' }
]


  */

 knex //problem 2
     .select('title', 'rental_duration')
     .from('film')
     .where('title', 'like', 'S%')
     .andWhere('rental_duration', '>', '3')
     .andWhere('rental_duration', '<', '7')
     .orderBy('rental_duration', 'desc')
     .orderBy('title', 'desc')
     .then(result => console.log(result))
     .then(() => knex.destroy());

 //output from problem 2

/*
[
  { title: 'Sweden Shining', rental_duration: 6 },
  { title: 'Sunset Racer', rental_duration: 6 },
  { title: 'Storm Happiness', rental_duration: 6 },
  { title: 'Steers Armageddon', rental_duration: 6 },
  { title: 'Spy Mile', rental_duration: 6 },
  { title: 'Speakeasy Date', rental_duration: 6 },
  { title: 'Soup Wisdom', rental_duration: 6 },
  { title: 'Sorority Queen', rental_duration: 6 },
  { title: 'Snatch Slipper', rental_duration: 6 },
  { title: 'Shrunk Divine', rental_duration: 6 },
  { title: 'Shootist Superfly', rental_duration: 6 },
  { title: 'Shawshank Bubble', rental_duration: 6 },
  { title: 'Shakespeare Saddle', rental_duration: 6 },
  { title: 'Secret Groundhog', rental_duration: 6 },
  { title: 'Seabiscuit Punk', rental_duration: 6 },
  { title: 'Scalawag Duck', rental_duration: 6 },
  { title: 'Sassy Packer', rental_duration: 6 },
  { title: 'Super Wyoming', rental_duration: 5 },
  { title: 'Superfly Trip', rental_duration: 5 },
  { title: 'Sundance Invasion', rental_duration: 5 },
  { title: 'Sun Confessions', rental_duration: 5 },
  { title: 'Summer Scarface', rental_duration: 5 },
  { title: 'Submarine Bed', rental_duration: 5 },
  { title: 'Streetcar Intentions', rental_duration: 5 },
  { title: 'Star Operation', rental_duration: 5 },
  { title: 'Stampede Disturbing', rental_duration: 5 },
  { title: 'Stallion Sundance', rental_duration: 5 },
  { title: 'Stagecoach Armageddon', rental_duration: 5 },
  { title: 'Splendor Patton', rental_duration: 5 },
  { title: 'Splash Gump', rental_duration: 5 },
  { title: 'Spirited Casualties', rental_duration: 5 },
  { title: 'Spice Sorority', rental_duration: 5 },
  { title: 'Slums Duck', rental_duration: 5 },
  { title: 'Slipper Fidelity', rental_duration: 5 },
  { title: 'Sling Luke', rental_duration: 5 },
  { title: 'Sleepless Monsoon', rental_duration: 5 },
  { title: 'Sister Freddy', rental_duration: 5 },
  { title: 'Side Ark', rental_duration: 5 },
  { title: 'Ship Wonderland', rental_duration: 5 },
  { title: 'Shane Darkness', rental_duration: 5 },
  { title: 'Secretary Rouge', rental_duration: 5 },
  { title: 'Scissorhands Slums', rental_duration: 5 },
  { title: 'School Jacket', rental_duration: 5 },
  { title: 'Savannah Town', rental_duration: 5 },
  { title: 'Samurai Lion', rental_duration: 5 },
  { title: 'Saints Bride', rental_duration: 5 },
  { title: 'Sabrina Midnight', rental_duration: 5 },
  { title: 'Swarm Gold', rental_duration: 4 },
  { title: 'Suspects Quills', rental_duration: 4 },
  { title: 'Suicides Silence', rental_duration: 4 },
  { title: 'Strangers Graffiti', rental_duration: 4 },
  { title: 'Strangelove Desire', rental_duration: 4 },
  { title: 'Steel Santa', rental_duration: 4 },
  { title: 'State Wasteland', rental_duration: 4 },
  { title: 'Stage World', rental_duration: 4 },
  { title: 'Spoilers Hellfighters', rental_duration: 4 },
  { title: 'Spartacus Cheaper', rental_duration: 4 },
  { title: 'South Wait', rental_duration: 4 },
  { title: 'Something Duck', rental_duration: 4 },
  { title: 'Snatchers Montezuma', rental_duration: 4 },
  { title: 'Smile Earring', rental_duration: 4 },
  { title: 'Sleuth Orient', rental_duration: 4 },
  { title: 'Sleepy Japanese', rental_duration: 4 },
  { title: 'Silverado Goldfinger', rental_duration: 4 },
  { title: 'Shining Roses', rental_duration: 4 },
  { title: 'Seven Swarm', rental_duration: 4 },
  { title: 'Sense Greek', rental_duration: 4 },
  { title: 'Sea Virgin', rental_duration: 4 },
  { title: 'Seattle Expecations', rental_duration: 4 },
  { title: 'Salute Apollo', rental_duration: 4 },
  { title: 'Sagebrush Clueless', rental_duration: 4 }
]

 */

knex //problem 3
    .select('country')
    .count('city_id AS city_count')
    .from('city')
    .innerJoin('country', 'city.country_id', 'country.country_id')
    .groupBy('country')
    .orderBy('city_count', 'desc')
    .then(result => console.log(result))
    .then(() => knex.destroy());

//output from problem 3

/*
[
  { country: 'India', city_count: '60' },
  { country: 'China', city_count: '53' },
  { country: 'United States', city_count: '35' },
  { country: 'Japan', city_count: '31' },
  { country: 'Mexico', city_count: '30' },
  { country: 'Russian Federation', city_count: '28' },
  { country: 'Brazil', city_count: '28' },
  { country: 'Philippines', city_count: '20' },
  { country: 'Turkey', city_count: '15' },
  { country: 'Indonesia', city_count: '14' },
  { country: 'Nigeria', city_count: '13' },
  { country: 'Argentina', city_count: '13' },
  { country: 'South Africa', city_count: '11' },
  { country: 'Taiwan', city_count: '10' },
  { country: 'Poland', city_count: '8' },
  { country: 'Iran', city_count: '8' },
  { country: 'United Kingdom', city_count: '8' },
  { country: 'Canada', city_count: '7' },
  { country: 'Germany', city_count: '7' },
  { country: 'Italy', city_count: '7' },
  { country: 'Venezuela', city_count: '7' },
  { country: 'Vietnam', city_count: '6' },
  { country: 'Ukraine', city_count: '6' },
  { country: 'Colombia', city_count: '6' },
  { country: 'Egypt', city_count: '6' },
  { country: 'Spain', city_count: '5' },
  { country: 'South Korea', city_count: '5' },
  { country: 'Saudi Arabia', city_count: '5' },
  { country: 'Netherlands', city_count: '5' },
  { country: 'Pakistan', city_count: '5' },
  { country: 'France', city_count: '4' },
  { country: 'Yemen', city_count: '4' },
  { country: 'Peru', city_count: '4' },
  { country: 'Israel', city_count: '4' },
  { country: 'Austria', city_count: '3' },
  { country: 'Dominican Republic', city_count: '3' },
  { country: 'Bangladesh', city_count: '3' },
  { country: 'Malaysia', city_count: '3' },
  { country: 'Tanzania', city_count: '3' },
  { country: 'Algeria', city_count: '3' },
  { country: 'Chile', city_count: '3' },
  { country: 'Ecuador', city_count: '3' },
  { country: 'United Arab Emirates', city_count: '3' },
  { country: 'Switzerland', city_count: '3' },
  { country: 'Paraguay', city_count: '3' },
  { country: 'Thailand', city_count: '3' },
  { country: 'Morocco', city_count: '3' },
  { country: 'Mozambique', city_count: '3' },
  { country: 'Sudan', city_count: '2' },
  { country: 'Oman', city_count: '2' },
  { country: 'Cameroon', city_count: '2' },
  { country: 'Congo, The Democratic Republic of the', city_count: '2' },
  { country: 'Cambodia', city_count: '2' },
  { country: 'Latvia', city_count: '2' },
  { country: 'Azerbaijan', city_count: '2' },
  { country: 'Greece', city_count: '2' },
  { country: 'Puerto Rico', city_count: '2' },
  { country: 'French Polynesia', city_count: '2' },
  { country: 'Kenya', city_count: '2' },
  { country: 'Kazakstan', city_count: '2' },
  { country: 'Yugoslavia', city_count: '2' },
  { country: 'Belarus', city_count: '2' },
  { country: 'Romania', city_count: '2' },
  { country: 'Bolivia', city_count: '2' },
  { country: 'Angola', city_count: '2' },
  { country: 'Bulgaria', city_count: '2' },
  { country: 'Myanmar', city_count: '2' },
  { country: 'Senegal', city_count: '1' },
  { country: 'Nauru', city_count: '1' },
  { country: 'Slovakia', city_count: '1' },
  { country: 'Estonia', city_count: '1' },
  { country: 'Gambia', city_count: '1' },
  { country: 'New Zealand', city_count: '1' },
  { country: 'Hungary', city_count: '1' },
  { country: 'Chad', city_count: '1' },
  { country: 'Armenia', city_count: '1' },
  { country: 'Nepal', city_count: '1' },
  { country: 'Afghanistan', city_count: '1' },
  { country: 'Holy See (Vatican City State)', city_count: '1' },
  { country: 'North Korea', city_count: '1' },
  { country: 'Czech Republic', city_count: '1' },
  { country: 'Liechtenstein', city_count: '1' },
  { country: 'Runion', city_count: '1' },
  { country: 'Saint Vincent and the Grenadines', city_count: '1' },
  { country: 'Australia', city_count: '1' },
  { country: 'Faroe Islands', city_count: '1' },
  { country: 'Ethiopia', city_count: '1' },
  { country: 'Virgin Islands, U.S.', city_count: '1' },
  { country: 'Bahrain', city_count: '1' },
  { country: 'Finland', city_count: '1' },
  { country: 'Lithuania', city_count: '1' },
  { country: 'Greenland', city_count: '1' },
  { country: 'Anguilla', city_count: '1' },
  { country: 'Turkmenistan', city_count: '1' },
  { country: 'Tunisia', city_count: '1' },
  { country: 'Brunei', city_count: '1' },
  { country: 'Sri Lanka', city_count: '1' },
  { country: 'Malawi', city_count: '1' },
  { country: 'American Samoa', city_count: '1' },
  { country: 'Moldova', city_count: '1' },
  ... 9 more items
]
 */






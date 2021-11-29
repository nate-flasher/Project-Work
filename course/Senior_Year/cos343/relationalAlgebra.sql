-- Query 1
select name
from category;
-- Relational Algebra expression -  Π name(category)

-- Query 2
select title, release_year
from film
inner join language l
    on film.language_id = l.language_id
where name = 'English' and rating = 'PG-13' or rating = 'PG';
-- Relational Algebra expression -  Π title, release_year(σ film.language_id = l.language_id(σ name = 'English' and rating = 'PG-13'(film * language)))
-- ∪ Π title, release_year(σ film.language_id = l.language_id(σ name = 'English' and rating = 'PG'(film * language)))

-- Query 3
select first_name, last_name
from actor
inner join film_actor fa
    on actor.actor_id = fa.actor_id
inner join film f
    on fa.film_id = f.film_id
where length > 60
-- Relational Algebra expression - Π first_name, last_name(σ fa.film_id = f.film_id(σ actor.actor_id = fa.actor_id(actor * film_actor) * film)))



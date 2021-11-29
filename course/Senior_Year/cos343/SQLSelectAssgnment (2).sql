--Nate Flasher

--Problem 1
SELECT category_id, name
FROM category
offset 3
limit 5;

--Problem 2
select country, count(city) AS city_count
from country
    inner join city
        on country.country_id = city.country_id
group by country
order by city_count desc;

--Problem 3
select first_name, last_name, count(title) AS count
from actor
    inner join film_actor fa
        on actor.actor_id = fa.actor_id
    inner join film f
        on fa.film_id = f.film_id
group by last_name, first_name
order by last_name, first_name;

--Problem 4
select title, count(i.inventory_id) as count
from film
inner join inventory i
    on film.film_id = i.film_id
inner join rental r
    on i.inventory_id = r.inventory_id
group by title
order by count desc, title;

--Problem 5
select first_name, last_name, name, count(name) as count
from actor
inner join film_actor fa
    on actor.actor_id = fa.actor_id
inner join film f
    on fa.film_id = f.film_id
inner join film_category fc
    on f.film_id = fc.film_id
inner join category c
    on fc.category_id = c.category_id
where last_name like 'S%'
group by first_name, last_name, name
having count(name) >= 3
order by last_name, first_name, count desc;
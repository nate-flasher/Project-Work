--Query 1
select title, name
from film
inner join film_category fc on film.film_id = fc.film_id
inner join category c on c.category_id = fc.category_id
where name like 'C%' and name in(
select name
from category);

--Query 2
select distinct customer_id, email
from customer
where exists(select payment_id
from payment
inner join public.customer c on c.customer_id = payment.customer_id
where amount > 2.5 * (select AVG(amount) from payment) and payment.customer_id = customer.customer_id)
order by email;

--Query 3
select first_name, last_name, count(title) as number_of_films_appeared_in
from film
inner join film_actor fa on film.film_id = fa.film_id
inner join actor a on a.actor_id = fa.actor_id
group by last_name, first_name
having count(title) > (select count(title) as Kirsten_Paltrow_number_of_films
from film
inner join film_actor fa on film.film_id = fa.film_id
inner join actor a on a.actor_id = fa.actor_id
where first_name = 'Kirsten' and last_name = 'Paltrow')
order by count(title) desc, last_name, first_name;

select count(project_id) into item_counter, count(duration) into duration_counter
from Item
inner join Work w
on Item.id = w.id
--function that determines if next movie rental is free for a specific customer
create function is_next_movie_free(customerID integer)
returns bool as $$
    declare counter integer;
BEGIN

select count(r.rental_id) into counter
from payment
inner join customer c on c.customer_id = payment.customer_id
inner join rental r on c.customer_id = r.customer_id
where payment.customer_id = c.customer_id and c.customer_id = r.customer_id
and c.customer_id = customerID;

    if (counter + 1) % 10 = 0 then
        return true;
        else
        return false;
    end if;

end;
$$ LANGUAGE plpgsql;


--tester function
select count(r.rental_id) as counter
from payment
inner join customer c on c.customer_id = payment.customer_id
inner join rental r on c.customer_id = r.customer_id
where payment.customer_id = c.customer_id and c.customer_id = r.customer_id
and c.customer_id = 96;

--returns true
select * from is_next_movie_free(96);

--returns false
select * from is_next_movie_free(400);



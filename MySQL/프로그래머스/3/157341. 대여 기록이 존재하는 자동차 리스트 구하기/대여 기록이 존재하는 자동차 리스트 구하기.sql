select c.CAR_ID
from CAR_RENTAL_COMPANY_CAR as c left join CAR_RENTAL_COMPANY_RENTAL_HISTORY as h on c.CAR_ID = h.CAR_ID
where CAR_TYPE = "세단" and c.CAR_ID in (
    select CAR_ID
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where month(START_DATE) = 10
)
group by c.CAR_ID
order by c.CAR_ID desc
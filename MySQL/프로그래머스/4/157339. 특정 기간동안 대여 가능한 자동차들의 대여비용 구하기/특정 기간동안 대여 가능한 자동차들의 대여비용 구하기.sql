select 
    CAR_ID, c.CAR_TYPE, 
    round(daily_fee * (1 - ifnull(DISCOUNT_RATE, 0) / 100) * 30) as FEE
from 
    CAR_RENTAL_COMPANY_CAR as c 
    left join CAR_RENTAL_COMPANY_DISCOUNT_PLAN as d 
        on c.CAR_TYPE = d.CAR_TYPE and DURATION_TYPE = "30일 이상"
where 
    c.CAR_TYPE regexp "SUV|세단" and
    CAR_ID not in (
        select CAR_ID
        from CAR_RENTAL_COMPANY_RENTAL_HISTORY
        where END_DATE >= "2022-11-01" or START_DATE >= "2022-11-01"
    )
having FEE >= 500000 and FEE < 2000000
order by FEE desc, c.CAR_TYPE, c.CAR_ID desc

with n as (
    select count(distinct USER_ID) as c
    from USER_INFO 
    where year(JOINED) = 2021
)

select 
    year(s.SALES_DATE) as YEAR, 
    month(s.SALES_DATE) as MONTH, 
    count(distinct s.USER_ID) as PUCHASED_USERS,
    round(count(distinct s.USER_ID) / n.c, 1) as PUCHASED_RATIO
from 
    USER_INFO as u 
    join ONLINE_SALE as s
        on u.USER_ID = s.USER_ID,
    n
where year(u.JOINED) = 2021
group by YEAR, MONTH
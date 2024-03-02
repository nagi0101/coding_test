select year(SALES_DATE), month(SALES_DATE), GENDER, count(distinct s.USER_ID) as USERS
from 
    ONLINE_SALE as s 
    join USER_INFO as u 
        on s.USER_ID = u.USER_ID and GENDER is not null
group by year(SALES_DATE), month(SALES_DATE), GENDER
order by year(SALES_DATE), month(SALES_DATE), GENDER, s.USER_ID

#select floor((PRICE / 10000)) * 10000 as PRICE_GROUP, count(*)
select truncate(PRICE, -4) as PRICE_GROUP, count(*)
from PRODUCT
group by PRICE_GROUP
order by PRICE_GROUP
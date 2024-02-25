select FLAVOR
from (
    select * from FIRST_HALF as f
    union
    select * from JULY as j
) as t
group by FLAVOR
order by sum(TOTAL_ORDER) desc
limit 3
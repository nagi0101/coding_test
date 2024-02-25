select 
    o.ANIMAL_ID,
    o.NAME
from ANIMAL_OUTS o
join ANIMAL_INS i
     on o.ANIMAL_ID = i.ANIMAL_ID
order by timestampdiff(day, i.DATETIME, o.DATETIME) desc
limit 2
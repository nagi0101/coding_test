with c as (
    select CATEGORY, sum(CODE) as s
    from SKILLCODES
    group by CATEGORY
)
    
select ID, EMAIL, FIRST_NAME, LAST_NAME
from DEVELOPERS
where SKILL_CODE & (select s from c where CATEGORY = "Front End") != 0
order by ID
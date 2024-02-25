with recursive t as (
    select -1 as HOUR, 0 as COUNT
    union all
    select HOUR + 1, ifnull((
        select count(*)
        from ANIMAL_OUTS
        where hour(DATETIME) - 1 = HOUR
        group by hour(DATETIME)
    ), 0)
    from t
    where HOUR < 23
)

select * from (
    select * from t
    order by HOUR desc
    limit 24
) t
order by HOUR
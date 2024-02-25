select 
    u.USER_ID,
    u.NICKNAME,
    sum(b.PRICE) as TOTAL_SALES
from USED_GOODS_BOARD as b left join USED_GOODS_USER as u on b.WRITER_ID = u.USER_ID
where b.STATUS = "DONE"
group by USER_ID
having TOTAL_SALES >= 700000
order by TOTAL_SALES
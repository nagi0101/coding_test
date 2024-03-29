select o.PRODUCT_ID, PRODUCT_NAME, sum(PRICE * AMOUNT) as TOTAL_SALES
from FOOD_ORDER as o join FOOD_PRODUCT as p on o.PRODUCT_ID = p.PRODUCT_ID
where year(PRODUCE_DATE) = 2022 and month(PRODUCE_DATE) = 5
group by o.PRODUCT_ID
order by TOTAL_SALES desc, o.PRODUCT_ID
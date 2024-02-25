select b.AUTHOR_ID, AUTHOR_NAME, CATEGORY, sum(PRICE * SALES) as TOTAL_SALES
from BOOK_SALES as s join BOOK as b on s.BOOK_ID = b.BOOK_ID join AUTHOR as a on b.AUTHOR_ID = a.AUTHOR_ID
where year(SALES_DATE) = 2022 and month(SALES_DATE) = 1
group by b.AUTHOR_ID, CATEGORY
order by b.AUTHOR_ID, CATEGORY desc
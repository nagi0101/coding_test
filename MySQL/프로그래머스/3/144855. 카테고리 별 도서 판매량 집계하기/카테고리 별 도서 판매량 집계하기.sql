select
    CATEGORY,
    sum(SALES) as TOTAL_SALES
from BOOK_SALES
join BOOK
on BOOK.BOOK_ID = BOOK_SALES.BOOK_ID
where date_format(SALES_DATE, "%Y-%m") = "2022-01"
group by CATEGORY
order by CATEGORY
select 
    MEMBER_NAME,
    REVIEW_TEXT,
    date_format(REVIEW_DATE, "%Y-%m-%d") as REVIEW_DATE
from REST_REVIEW as r left join MEMBER_PROFILE as m on r.MEMBER_ID = m.MEMBER_ID
where r.MEMBER_ID = (
    select r.MEMBER_ID
    from REST_REVIEW as r left join MEMBER_PROFILE as m on r.MEMBER_ID = m.MEMBER_ID
    group by r.MEMBER_ID
    order by count(r.MEMBER_ID) desc
    limit 1
)
order by REVIEW_DATE, REVIEW_TEXT
select 
    PT_NAME, 
    PT_NO, 
    GEND_CD, 
    AGE, 
    if(TLNO, TLNO, 'NONE') as TNLO
from PATIENT
where GEND_CD = 'W' AND AGE <= 12 
order by AGE desc, PT_NAME
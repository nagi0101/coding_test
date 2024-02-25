select HISTORY_ID, truncate(DAILY_FEE * (100 - ifnull(DISCOUNT_RATE, 0)) * 0.01 * (timestampdiff(day, START_DATE, END_DATE) + 1), 0) as FEE
from CAR_RENTAL_COMPANY_RENTAL_HISTORY as h 
    left join CAR_RENTAL_COMPANY_CAR as c on h.CAR_ID = c.CAR_ID 
    left join CAR_RENTAL_COMPANY_DISCOUNT_PLAN as p 
        on 
            p.CAR_TYPE = c.CAR_TYPE and DURATION_TYPE = 
            case
                when timestampdiff(day, START_DATE, END_DATE) + 1 >= 90 then "90일 이상"
                when timestampdiff(day, START_DATE, END_DATE) + 1 >= 30 then "30일 이상"
                when timestampdiff(day, START_DATE, END_DATE) + 1 >= 7 then "7일 이상"
            end
where c.CAR_TYPE = "트럭"
order by FEE desc, HISTORY_ID desc
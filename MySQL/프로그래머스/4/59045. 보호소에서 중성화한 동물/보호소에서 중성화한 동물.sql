select i.ANIMAL_ID, i.ANIMAL_TYPE, i.NAME
from ANIMAL_INS as i join ANIMAL_OUTS as o on i.ANIMAL_ID = o.ANIMAL_ID
where 
    i.SEX_UPON_INTAKE regexp "^Intact" 
    and o.SEX_UPON_OUTCOME regexp "^[Neutered|Spayed]"
order by i.ANIMAL_ID
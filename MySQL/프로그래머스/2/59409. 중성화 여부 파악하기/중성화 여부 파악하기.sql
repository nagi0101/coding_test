select 
    ANIMAL_ID, 
    NAME,
    if(SEX_UPON_INTAKE regexp "Neutered|Spayed", "O", "X") as 중성화
from ANIMAL_INS
order by ANIMAL_ID
select ANIMAL_ID, NAME
from ANIMAL_INS
where NAME regexp "[E|e][L|l]" and ANIMAL_TYPE = "Dog"
order by NAME
update Salary 
set Salary.sex = case 
    when Salary.sex = 'f' then 'm'
    else 'f' end;

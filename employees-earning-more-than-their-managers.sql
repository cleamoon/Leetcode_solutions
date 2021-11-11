# Write your MySQL query statement below
Select A.name as Employee
From Employee A, Employee B
Where A.managerId = B.id and A.salary > B.salary;

# Write your MySQL query statement below
Select C.name as Customers
From Customers C
Where C.id not in (select customerId from Orders);

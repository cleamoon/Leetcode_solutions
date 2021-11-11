# Write your MySQL query statement below
Select distinct P1.email
From Person P1, Person P2
Where P1.id < P2.id and P1.email = P2.email;

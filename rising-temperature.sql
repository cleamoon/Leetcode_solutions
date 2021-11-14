# Write your MySQL query statement below
select A.id
from Weather A, Weather B
where A.temperature > B.temperature and DATE(DATE_ADD(B.recordDate, INTERVAL 1 DAY)) = DATE(A.recordDate);

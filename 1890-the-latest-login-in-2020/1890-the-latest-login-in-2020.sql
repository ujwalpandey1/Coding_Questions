# Write your MySQL query statement below
SELECT user_id, MAX(time_stamp) as last_stamp 
from Logins
WHERE time_stamp LIKE '2020%'
group by user_id;
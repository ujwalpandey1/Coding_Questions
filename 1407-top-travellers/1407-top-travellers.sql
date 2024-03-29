# Write your MySQL query statement below
SELECT  u.name,IFNULL(sum(r.distance),0) AS travelled_distance
FROM Users u LEFT JOIN Rides r ON u.id=r.user_id 
GROUP BY (u.id)
ORDER BY SUM(r.distance) DESC , u.name;
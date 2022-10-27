# Write your MySQL query statement below
SELECT email as Email From Person 
Group by email
having COUNT(email)>1;
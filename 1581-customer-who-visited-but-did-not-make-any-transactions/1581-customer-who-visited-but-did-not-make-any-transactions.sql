# Write your MySQL query statement below
SELECT customer_id,COUNT(customer_id) as count_no_trans
FROM Visits WHERE visit_id NOT IN(
SELECT t.visit_id FROM Transactions t INNER JOIN Visits v ON t.visit_id=v.visit_id 
)
GROUP BY customer_id;
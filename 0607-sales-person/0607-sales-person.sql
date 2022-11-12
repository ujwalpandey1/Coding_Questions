# Write your MySQL query statement below
SELECT s.name FROM SalesPerson s WHERE s.name NOT IN(
SELECT s.name
From Orders o left join company c on o.com_id=c.com_id left join SalesPerson s on s.sales_id=o.sales_id
WHERE c.name="RED");
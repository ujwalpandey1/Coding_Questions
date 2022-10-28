# Write your MySQL query statement below
SELECT MAX(salary) as SecondHighestSalary From Employee 
where salary not in (SELECT MAX(SALARY) FROM Employee);


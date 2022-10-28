CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
     SET N=N-1;
  RETURN (
      SELECT DISTINCT salary from employee order by salary DESC limit 1 offset N
      
  );
END
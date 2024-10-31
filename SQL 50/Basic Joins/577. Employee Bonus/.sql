# Write your MySQL query statement below
SELECT e.name, B.bonus
FROM Employee E
LEFT JOIN Bonus B
ON E.empId = B.empId
WHERE B.bonus < 1000 OR 
B.empId IS NULL;

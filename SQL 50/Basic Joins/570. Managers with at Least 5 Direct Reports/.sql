SELECT A.name
FROM Employee A
JOIN Employee B
ON A.id = B.managerId
GROUP BY A.id
HAVING COUNT(A.id) >= 5;

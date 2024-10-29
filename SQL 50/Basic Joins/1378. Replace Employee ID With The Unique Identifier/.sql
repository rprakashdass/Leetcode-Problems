SELECT U.unique_id, E.name
FROM EmployeeUNI AS U
RIGHT JOIN Employees AS E
ON U.id = E.id;

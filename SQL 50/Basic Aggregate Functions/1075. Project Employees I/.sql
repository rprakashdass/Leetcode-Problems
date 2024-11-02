SELECT P.project_id, ROUND(
    SUM(E.experience_years) / COUNT(*), 
    2
) average_years
FROM Project P
LEFT JOIN Employee E
ON P.employee_id = E.employee_id
GROUP BY P.project_id;

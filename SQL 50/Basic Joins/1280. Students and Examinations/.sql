SELECT A.student_id, A.student_name, B.subject_name,
COUNT(E.student_id) AS attended_exams
FROM Students A
CROSS JOIN Subjects B
LEFT JOIN Examinations E
ON E.student_id = A.student_id
AND E.subject_name = B.subject_name
GROUP BY A.student_id, A.student_name, B.subject_name
ORDER BY A.student_id, B.subject_name;

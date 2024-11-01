SELECT M.machine_id, ROUND(
    AVG(P.timestamp - M.timestamp),
    3) processing_time
FROM Activity M
JOIN Activity P
ON M.machine_id = P.machine_id
AND M.process_id = P.process_id
AND M.timestamp < P.timestamp
GROUP BY M.machine_id;

SELECT A.id FROM Weather A
JOIN Weather B
ON A.recordDate - INTERVAL 1 DAY = B.recordDate
WHERE A.temperature > B.temperature;

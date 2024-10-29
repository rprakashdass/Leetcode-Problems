SELECT A.id FROM Weather A
JOIN Weather B
ON A.recordDate-1 = B.recordDate
WHERE A.temperature > B.temperature;

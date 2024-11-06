SELECT DISTINCT A.num AS ConsecutiveNums
FROM logs A
JOIN Logs B ON A.id - 1 = B.id
JOIN Logs C ON A.id + 1 = C.id
WHERE A.num = B.num AND B.num = C.num;

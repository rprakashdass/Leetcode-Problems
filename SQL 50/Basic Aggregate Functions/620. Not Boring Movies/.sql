-- Method 1
SELECT *
FROM Cinema
WHERE id%2 != 0 AND description <> "boring"
ORDER BY Rating DESC;

-- Method 2
SELECT *
FROM Cinema
WHERE id % 2 != 0 AND LOWER(description) NOT LIKE "%boring%"
ORDER BY Rating DESC;

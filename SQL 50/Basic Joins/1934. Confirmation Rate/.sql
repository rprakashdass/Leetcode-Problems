SELECT S.user_id, ROUND(
    SUM(
        IF( C.action = 'confirmed', 1, 0 )
    ) / COUNT(*),
    2
) AS confirmation_rate
FROM Signups S
LEFT JOIN Confirmations C
ON S.user_id = C.user_id
GROUP BY S.user_id;

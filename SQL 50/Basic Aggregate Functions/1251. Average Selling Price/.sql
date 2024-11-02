SELECT P.product_id, IFNULL(
    ROUND(
    SUM( P.price * U.units ) / SUM(U.units)
    ,2
    ), 0
) AS average_price
FROM Prices P
LEFT JOIN UnitsSold U
ON P.product_id = U.product_id
AND P.start_date <= U.purchase_date
AND P.end_date >= U.purchase_date
GROUP BY P.product_id;

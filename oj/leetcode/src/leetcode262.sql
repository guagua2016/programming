SELECT      request_at AS "Day", 
            ROUND(((SUM(CASE WHEN LOWER(Status) LIKE "cancelled%" THEN 1.000 ELSE 0 END)) / COUNT(id)), 2) AS "Cancellation Rate" 
FROM        trips
WHERE       client_id NOT IN (SELECT users_id FROM users WHERE banned = 'Yes')
AND         request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY    request_at;
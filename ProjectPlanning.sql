SELECT Start_Date, MIN(End_Date)
FROM
  (SELECT Start_Date
   FROM PROJECTS
   WHERE Start_Date NOT IN
       (SELECT End_Date
        FROM PROJECTS)) A,
  (SELECT End_Date
   FROM PROJECTS
   WHERE End_Date NOT IN
       (SELECT Start_Date
        FROM PROJECTS)) B
WHERE Start_Date < End_Date
GROUP BY Start_Date
ORDER BY (MIN(End_Date) - Start_Date), Start_Date;
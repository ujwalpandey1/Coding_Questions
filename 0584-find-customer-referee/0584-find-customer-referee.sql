# Write your MySQL query statement below
SELECT name FROM Customer WHERE referee_id NOT IN(SELECT referee_id FROM Customer WHERE referee_id=2) OR referee_id IS Null;
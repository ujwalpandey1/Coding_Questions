# Write your MySQL query statement below
SELECT stock_name ,sum(
case when operation='Buy' then -price else price
    end) as capital_gain_loss From Stocks group by stock_name;
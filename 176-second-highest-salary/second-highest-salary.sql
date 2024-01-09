# Write your MySQL query statement below
Select max(salary) As SecondHighestSalary
from Employee
where salary<(Select max(salary)
from Employee
where salary)
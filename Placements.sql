select S1.Name
from Students s1 
inner join Packages p1 on s1.Id = p1.Id
inner join Friends f on s1.id = f.Id
inner join Students s2 on f.Friend_Id = s2.Id
inner join Packages p2 on s2.id = p2.Id
where p1.Salary < p2.Salary
order by p2.Salary;
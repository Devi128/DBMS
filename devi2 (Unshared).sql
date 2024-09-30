create table students16(
    sid integer,
    sname varchar(20),
    perc integer,
    gender varchar(20),
    branch varchar(20));
insert into students16 values(101,'devi',96,'f','cse');
insert into students16 values(102,'varsha',99,'f','cse');
insert into students16 values(103,'renu',95,'f','ece');
insert into students16 values(104,'sai',98,'m','civil');
insert into students16 values(105,'vikas',97,'m','ece');
select * from students16;
select sysdate from students16;
select months_between(sysdate,'20-08-2024') from students16;
select next_day(sysdate,'monday') from students16;
select last_day(sysdate) from students16;
select add_months(sysdate,-1) from students16;
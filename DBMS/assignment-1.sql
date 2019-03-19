select empno,ename,sal from emp where sal between 1000 and 2000
select deptno, dname from dept order by dname
select job from emp group by job
select * from emp where deptno in (10,20) order by ename
select ename,job from emp where job='clerk'and deptno=20
select ename from emp where ename  like '%th%' or ename like '%ll%'
select * from emp where mgr is not null
select ename, sal + isnull(comm,0) from emp 
select ename, sal*12 salary,isnull(comm,0)*12 commission from emp where sal> isnull(comm,0) and deptno in(select deptno from dept where dname ='SALES')order by sal desc,ename
select concat(concat(ename,' is a '),job)"employee name and job", cast(sal*(1.15) as int) "salary increased to 15%" from emp 
select ename, REPLACE(job,'SALESMAN', 'SALESPERSON') from emp where job='SALESMAN'
select job,min(sal) "minimum salary",max(sal) "maximum salary" from emp group by job
select count(job)"No of managers" from emp where job='MANAGER'
select job, avg(sal) "average salary", sum(sal+isnull(comm,0)) "total remuneration" from emp group by job
select max(sal)-min(sal) "difference between max & min sal" from emp
select deptno from emp group by deptno having count(empno) >3
select CASE when count(empno) = count(*) then 'true' else 'false' end  from emp
select ename,mgr,sal from emp where sal in( select min(sal) from emp  group by mgr having min(sal)>1000) order by sal desc
select ename ,dname from emp e, dept d where e.deptno = d.deptno order by dname
select ename, e.deptno,d.dname from emp e, dept d where e.deptno=d.deptno
select ename, e.deptno,loc,sal from emp e, dept d where e.deptno=d.deptno and sal>1500
select ename from emp , salgrade  where sal between losal and hisal and grade =3 
select ename from emp e, dept d where e.deptno=d.deptno and loc='DALLAS'
select ename,job, sal, grade, dname from emp e, salgrade, dept d where job<>'CLERK' and e.deptno=d.deptno and grade in(select grade from salgrade where e.sal between losal and hisal) order by sal desc
select * from emp where sal*12 = 36000 or job='CLERK'
select deptno, dname from dept where deptno not in ( select deptno from emp group by deptno)
select ename,job,sal from emp  where sal in ( select max(sal) from emp group by job) order by sal desc
select ename, hiredate from emp where hiredate in ( select max(hiredate) from emp group by deptno) order by hiredate
select deptno,count(empno)'count', sum(sal)'total', avg(sal)'average' from emp group by deptno

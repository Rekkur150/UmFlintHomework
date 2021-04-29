CREATE TABLE studentInfo (
	studentNum INT,
	marks INT
);

DROP TABLE USERS; --Removes the table called USERS

SET TIMING ON; --Allow us to see the timing of commands.

SELECT COUNT(*) FROM studentInfo s1, studentInfo s2 
WHERE s1.studentNum=s2.studentNum;

SELECT COUNT(*) FROM studentInfo s1 
WHERE s1.studentNum IN (SELECT studentNum FROM studentInfo);

UPDATE studentinfo SET marks = marks - 1
WHERE studentNum IN (SELECT studentNum FROM studentInfo);
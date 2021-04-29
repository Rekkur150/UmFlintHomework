

--PROBLEM 1

DROP TABLE PC;
DROP TABLE Product;

CREATE TABLE Product (maker VARCHAR(20),model VARCHAR(20) PRIMARY KEY,type VARCHAR(20));

CREATE TABLE PC (model VARCHAR(20) PRIMARY KEY REFERENCES Product ON DELETE CASCADE, speed INT, ram INT, hd INT, price FLOAT);

--PROBLEM 2

DROP TABLE Accounts;
DROP TABLE Customers;

CREATE TABLE Customers(ssNo VARCHAR(20) PRIMARY KEY,name VARCHAR(20),phone VARCHAR(20),address VARCHAR(20));

CREATE TABLE Accounts(accNum INT PRIMARY KEY ,balance FLOAT,type VARCHAR(20),owner VARCHAR(20) REFERENCES Customers);

--PROBLEM 3

DROP TABLE Player;
DROP TABLE Team;
DROP TABLE League;

CREATE TABLE League(lName VARCHAR(20) PRIMARY KEY, yearEstablished INT);

CREATE TABLE Team(tName VARCHAR(20), tManager VARCHAR(20), league VARCHAR(20) REFERENCES League, PRIMARY KEY (tName, league));

CREATE TABLE Player(playerNum INT, playerName VARCHAR(20), team VARCHAR(20), league VARCHAR(20), FOREIGN KEY (team,league) REFERENCES Team(tName,league), PRIMARY KEY (playerNum, team, league));

--PROBLEM 4

DROP TABLE Technical;
DROP TABLE Marketing;
DROP TABLE Business;
DROP TABLE Employee;

CREATE TABLE Employee(Enumber INT PRIMARY KEY, name VARCHAR(20), yearHired INT);

CREATE TABLE Technical(Tnumber INT PRIMARY KEY REFERENCES Employee, Tdegree VARCHAR(20));

CREATE TABLE Marketing(Mnumber INT PRIMARY KEY REFERENCES Employee, revenue INT);

CREATE TABLE Business(Bnumber INT PRIMARY KEY REFERENCES Employee, experience INT);

--PROBLEM 5

DROP TABLE ProductAtStore;
DROP TABLE ProductPartOfSale;
DROP TABLE Product;
DROP TABLE Sale;
DROP TABLE Customer;
DROP TABLE Employee;
DROP TABLE CStore;

CREATE TABLE CStore(city VARCHAR(20) PRIMARY KEY, address VARCHAR(20));

CREATE TABLE Employee(Eid INT PRIMARY KEY, address VARCHAR(20), joinYear INT, salary INT, Erank VARCHAR(20), works VARCHAR(20) REFERENCES CStore);

CREATE TABLE Customer(Cnumber INT PRIMARY KEY, address VARCHAR(20));

CREATE TABLE Sale(Sid INT PRIMARY KEY, Sdate DATE, Sstore VARCHAR(20) REFERENCES CStore, customer INT REFERENCES Customer);

CREATE TABLE Product(Pname VARCHAR(20) PRIMARY KEY, Pcategory VARCHAR(20));

CREATE TABLE ProductPartOfSale(product VARCHAR(20) REFERENCES Product, sale INT REFERENCES Sale, quantity INT);

CREATE TABLE ProductAtStore(product VARCHAR(20) REFERENCES Product, Pstore VARCHAR(20) REFERENCES CStore, quantity INT);


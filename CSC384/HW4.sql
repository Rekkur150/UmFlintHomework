
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

DROP TABLE League;
DROP TABLE Team;
DROP TABLE Player;

CREATE TABLE League(lName VARCHAR(20) PRIMARY KEY, yearEstablished INT);

CREATE TABLE Team(tName VARCHAR(20), tManager VARCHAR(20), league VARCHAR(20) REFERENCES League, PRIMARY KEY (tName, league));

CREATE TABLE Player(playerNum INT, name VARCHAR(20), team VARCHAR(20) REFERENCES Team, league VARCHAR(20) REFERENCES League, PRIMARY KEY (playerNum, team, league));

--PROBLEM 4

DROP TABLE Employee;
DROP TABLE Technical;
DROP TABLE Marketing;
DROP TABLE Business;

CREATE TABLE Employee(number INT, name VARCHAR(20), yearHired INT);

CREATE TABLE Technical(number INT PRIMARY KEY REFERENCES Employee, degree VARCHAR(20));

CREATE TABLE Marketing(number INT PRIMARY KEY REFERENCES Employee, revenue INT);

CREATE TABLE Business(number INT PRIMARY KEY REFERENCES Employee, experience INT);

--PROBLEM 5

DROP TABLE Store;
DROP TABLE Employee;
DROP TABLE Customer;
DROP TABLE Sale;
DROP TABLE Product;
DROP TABLE ProductPartOfSale;
DROP TABLE ProductAtStore;

CREATE TABLE Store(city VARCHAR(20) PRIMARY KEY, address VARCHAR(20));

CREATE TABLE Employee(id INT PRIMARY KEY, address VARCHAR(20), joinYear INT, salary INT, rank VARCHAR(20), works VARCHAR(20) REFERENCES Store);

CREATE TABLE Customer(number INT, address VARCHAR(20));

CREATE TABLE Sale(id INT PRIMARY KEY, date DATE, store VARCHAR(20) REFERENCES Store, customer INT REFERENCES Customer);

CREATE TABLE Product(name VARCHAR(20) PRIMARY KEY, category VARCHAR(20));

CREATE TABLE ProductPartOfSale(product VARCHAR(20) REFERENCES Product, sale INT REFERENCES Sale, quantity INT);

CREATE TABLE ProductAtStore(product VARCHAR(20) REFERENCES Product, store VARCHAR(20) REFERENCES Store, quantity INT);



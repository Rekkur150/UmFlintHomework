--Constraint Changing

CREATE TABLE Sells (
    barName VARCHAR(20),
    beerNAME VARCHAR(20),
    price NUMBER(*,2),
    CONSTRAINT pkSells PRIMARY KEY (barName, beerName),
    FOREIGN KEY (beerName) REFERENCES BEER(beername)
)

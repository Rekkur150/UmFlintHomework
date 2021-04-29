

-- Constraints
CREATE TABLE Beer (
    beerName VARCHAR(20),
    manF VARCHAR(20),
    PRIMARY KEY (beerName)
);

CREATE TABLE Bar (
    barName VARCHAR(20),
    city VARCHAR(20),
    PRIMARY KEY (barName)
);


CREATE TABLE Sell (
    barName VARCHAR(20),
    beerName VARCHAR(20),
    beerPrice REAL,
    PRIMARY KEY(barName, beerName),
    FOREIGN KEY (barName) REFERENCES Bars(barName),
    FOREIGN KEY (beerName) REFERENCES Beers(beerName)
);

--Inserting Values

INSERT INTO beer VALUES('Wine', 'Winnings');
INSERT INTO beer VALUES('Linux','Better');
INSERT INTO beer VALUES('Vim','The better editors');
INSERT INTO beer VALUES('nano', 'Back to basics');
INSERT INTO beer VALUES('Wine', 'For Actual Drinkers');

INSERT INTO beerPricesAtBars VALUES ('JIM', 'DRINK',5);
INSERT INTO beerPricesAtBars VALUES ('JIM', 'DRUNK',5);
INSERT INTO beerPricesAtBars VALUES ('JUM', 'DRINK',5);


/*
Project Option: Coyote Inland Empire Art Museum
Description: This script inserts data into each of the tables so that we may
	test the database for functionality.
Author: Hamza Khan 005125350
*/

INSERT INTO Artwork (Artwork_ID, Artwork_Dimensions, Artwork_Medium, Artwork_Name, Artwork_Weight, Artwork_Year) VALUES ('217469', '12X11X3','Oil','Legend of Clyopatra','15','401');
INSERT INTO Artwork (Artwork_ID, Artwork_Dimensions, Artwork_Medium, Artwork_Name, Artwork_Weight, Artwork_Year) VALUES ('217470','11X5X11','Sculpture','Bust of Hercules','30','102');
INSERT INTO Artwork (Artwork_ID, Artwork_Dimensions, Artwork_Medium, Artwork_Name, Artwork_Weight, Artwork_Year) VALUES ('217471', '5X10X5', 'Painting', 'Hera', '15', '102');
INSERT INTO Artwork (Artwork_ID, Artwork_Dimensions, Artwork_Medium, Artwork_Name, Artwork_Weight, Artwork_Year) VALUES ('217472', '10X15X5', 'Sketching', 'Davinci Plane', '1', '1401');
INSERT INTO Artwork (Artwork_ID, Artwork_Dimensions, Artwork_Medium, Artwork_Name, Artwork_Weight, Artwork_Year) VALUES ('217473','15X12X15','Portrait','Mona Lisa','20','1501');

INSERT INTO Collection VALUES ('5368747415','217469');
INSERT INTO COllection VALUES ('5368747416','217470');
INSERT INTO Collection VALUES ('5368747417','217471');
INSERT INTO Collection VALUES ('5368747418','217472');
INSERT INTO Collection VALUES ('5368747419','217473');

INSERT INTO Slides VALUES ('2142354','217469');
INSERT INTO Slides VALUES ('2142355','217469');
INSERT INTO Slides VALUES ('2142356','217469');
INSERT INTO Slides VALUES ('2142380','217470');
INSERT INTO Slides VALUES ('2142385','217471');
INSERT INTO Slides VALUES ('2142369','217473');
INSERT INTO Slides VALUES ('2151323','217473');
INSERT INTO Slides VALUES ('2142352','217473');

INSERT INTO Location VALUES ('507','217469','Egypt');
INSERT INTO Location VALUES ('608','217470','Greek');
INSERT INTO Location VALUES ('501','217471','Greek');
INSERT INTO Location VALUES ('451','217472','Italy');
INSERT INTO Location VALUES ('692','217473','Italy');

INSERT INTO Maintenance VALUES ('217469','Cleaning, Repair');
INSERT INTO Maintenance VALUES ('217473','Cleaning');

UPDATE Artwork SET Artwork_Collection_ID = '5368747415', Artwork_Location_ID = '507' WHERE Artwork_ID = '217469';
UPDATE Artwork SET Artwork_Collection_ID = '5368747416', Artwork_Location_ID = '608' WHERE Artwork_ID = '217470';
UPDATE Artwork SET Artwork_Collection_ID = '5368747417', Artwork_Location_ID = '501' WHERE Artwork_ID = '217471';
UPDATE Artwork SET Artwork_Collection_ID = '5368747418', Artwork_Location_ID = '451' WHERE Artwork_ID = '217472';
UPDATE Artwork SET Artwork_Collection_ID = '5368747419', Artwork_Location_ID = '692' WHERE Artwork_ID = '217473'; 

INSERT INTO Loan VALUES ('217469','5350','813','19-JUN-12','21-AUG-12');
INSERT INTO Loan VALUES ('217473','5350','815','30-SEP-12','25-DEC-12');

INSERT INTO Musuem VALUES ('5350','Smithsonian','600 Marland Ave SW, Washington, DC 20002');
INSERT INTO Musuem VALUES ('5135','Liberty','1251 California St, Riverside, CA 91351');

INSERT INTO Member VALUES ('58135','Tim Smith','2152 East Westside St, Houston, TX 50171', 'Platinum');
INSERT INTO Member VALUES ('25235','Dwayne Johnson','13521 Malibu Dr, Malibu, CA 92134','Double Platinum');

INSERT INTO NonMember VALUES ('10322', 'Shaan Wes', '5013 Liberty Ave, Los Angeles, CA 91031');
INSERT INTO NonMember VALUES ('13512', 'Bill Gates', '13252 Washington Dr, Seattle, WA 12321');

INSERT INTO Acquisition VALUES ('54215','217470','Donated','1','58135','','','15-May-11', '15,419.21'); 
INSERT INTO Acquisition VALUES ('59082','217471','Bought','2','','5350','','03-Jan-10','20,535.31');
INSERT INTO Acquisition VALUES ('65265','217472','Donated','3','','','10322','10-Jun-11','53,142.10');

INSERT INTO Unscheduled VALUES ('217469','Y','Clean','Repair, Mend');
INSERT INTO Unscheduled VALUES ('217473','N','','Clean');

SET PAUSE OFF;
SELECT * FROM Collection;
SELECT * FROM Slides;
SELECT * FROM Location;
SELECT * FROM Unscheduled;
SELECT * FROM Maintenance;
SELECT * FROM Artwork;
SELECT * FROM Loan;
SELECT * FROM Acquisition;
SELECT * FROM Musuem;

START commentTables.sql;

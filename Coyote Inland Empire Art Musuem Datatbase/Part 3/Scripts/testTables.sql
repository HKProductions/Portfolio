/*
Project Option: Coyote Inland Empire Art Museum
Description: This script is used to create views for the database and test 
	the functionality of the database itself to see if every component 
	works.
Author: Hamza Khan 005125350
*/

-- Show loan and musuem information
SELECT L.Artwork_ID, L.Loan_Museum_ID, M.Name, L.Loan_Start_Date, L.Loan_End_Date 
FROM Loan L, Musuem M
WHERE  M.Musuem_ID = L.Loan_Museum_ID;

-- Create the view for the loan and musuem informatio
DROP VIEW loanInfo;
CREATE VIEW loanInfo AS
	SELECT L.Artwork_ID, L.Loan_Museum_ID, M.Name, L.Loan_Start_Date, L.Loan_End_Date
	FROM Loan L, Musuem M
	WHERE M.Musuem_ID = L.Loan_Museum_ID;

-- Show the loanInfo view and test it
DESC loanInfo
SELECT * FROM loanInfo;
SELECT Artwork_ID, Name, Loan_Start_Date, Loan_End_Date
FROM loanInfo;

-- Show artwork name and locations
SELECT A.Artwork_Name, A.Artwork_Medium, L.Location_ID, L.Location_Address
FROM Artwork A, Location L
WHERE L.Location_ID = A.Artwork_Location_ID;

-- Create a view for an artwork location
DROP VIEW artworkLocation;
CREATE VIEW artworkLocation AS
	SELECT A.Artwork_Name, A.Artwork_Medium, L.Location_ID, L.Location_Address
	FROM Artwork A, Location L
	WHERE L.Location_ID = A.Artwork_Location_ID;

-- Show the artworkLocation view and test it
DESC artworkLocation
SELECT * FROM artworkLocation;
SELECT Artwork_Name, Location_Address 
FROM artworkLocation;

-- Show the artwork name and it's slides ID
SELECT A.Artwork_Name, S.Slides_ID
FROM Artwork A, Slides S
WHERE S.Artwork_ID = A.Artwork_ID;

-- Create view for artwork and slides info
DROP VIEW artworkSlides;
CREATE VIEW artworkSlides AS
	SELECT A.Artwork_ID, A.Artwork_Name, S.Slides_ID
	FROM Artwork A, Slides S
	WHERE S.Artwork_ID = A.Artwork_ID;

-- Show the artworkSlides view and test it
DESC artworkSlides
SELECT * FROM artworkSlides;
SELECT Artwork_Name, Slides_ID AS "Slide Number"
FROM artworkSlides;

-- Show the maintentance info 
SELECT M.Artwork_ID, A.Artwork_Name, A.Artwork_Medium, A.Artwork_Dimensions, A.Artwork_Weight, L.Location_Address, M.Maintenance_Scheduled
FROM Maintenance M, Artwork A, artworkLocation L
WHERE A.Artwork_ID = M.Artwork_ID
AND L.Location_ID = A.Artwork_Location_ID;

-- Create View for maintentance info
DROP VIEW artworkMaintenance;
CREATE VIEW artworkMaintenance AS
	SELECT M.Artwork_ID, A.Artwork_Name, A.Artwork_Medium, A.Artwork_Dimensions, A.Artwork_Weight, L.Location_Address, M.Maintenance_Scheduled
	FROM Maintenance M, Artwork A, artworkLocation L
	WHERE A.Artwork_ID = M.Artwork_ID
	AND L.Location_ID = A.Artwork_Location_ID;

-- Show the artworkMaintenance view and test it
DESC artworkMaintenance
SELECT * FROM artworkMaintenance;
SELECT Artwork_Name, Artwork_Medium, Artwork_Dimensions, Artwork_Weight, Location_Address, Maintenance_Scheduled
FROM artworkMaintenance;

-- Show the total number of artwork in the museum
SELECT COUNT(Artwork_ID) "Total Artworks"
FROM Artwork;

-- Create a view to display the toal number of artworks
DROP VIEW totalArtwork;
CREATE VIEW totalArtwork AS
	SELECT COUNT(Artwork_ID) "Total Artworks"
	FROM Artwork;

-- Show totalArtwork view and test it
DESC totalArtwork
SELECT * FROM totalArtwork;

-- Create a way to get artwork information about it's acquisition
DROP VIEW artworkAcquisition;
CREATE VIEW artworkAcquisition AS 
	SELECT Acq.Acquisition_ID, A.Artwork_Name, Acq.Acquisition_Date, Acq.Acquisition_Value, M.Name AS "Name", M.Address AS "Address"
	FROM Acquisition Acq, Artwork A, Member M
	WHERE Acq.Acquisition_From = 1 AND M.Member_ID = Acq.Acquisition_Member_ID AND A.Artwork_ID = Acq.Artwork_ID
	UNION
	SELECT Acq.Acquisition_ID, A.Artwork_Name, Acq.Acquisition_Date, Acq.Acquisition_Value, M.Name AS "Name", M.Address AS "Address"
	FROM Acquisition Acq, Artwork A, Musuem M
	WHERE Acq.Acquisition_From = 2 AND M.Musuem_ID = Acq.Acquisition_Musuem_ID AND A.Artwork_ID = Acq.Artwork_ID
	UNION
	SELECT ACq.Acquisition_ID, A.Artwork_Name, Acq.Acquisition_Date, Acq.Acquisition_Value, N.Name AS "Name", N.Address AS "Address"
	FROM Acquisition Acq, Artwork A, NonMember N
	WHERE Acq.Acquisition_From = 3 AND N.NonMember_ID = Acq.Acquisition_NonMember_ID AND A.Artwork_ID = Acq.Artwork_ID;

-- Show artworkAcquisition view and test it
DESC artworkAcquisition
SELECT * FROM artworkAcquisition;

-- Show unscheduled artwork maintenance info
SELECT U.Artwork_ID, A.Artwork_Name, L.Loan_Start_Date, A.Artwork_Dimensions, A.Artwork_Medium, A.Artwork_Weight, U.Unscheduled_Repairs,
CASE U.Unscheduled_Request
	WHEN 'Y' THEN U.Unscheduled_Repairs_Request
	ELSE 'None Needed'
END Unscheduled_Repairs_Requested
FROM Artwork A, Unscheduled U, Loan L
WHERE A.Artwork_ID = U.Artwork_ID AND L.Artwork_ID = U.Artwork_ID;

-- Create view for unscheduled artwork maintenance
DROP VIEW unscheduledArtwork;
CREATE VIEW unscheduledArtwork AS
	SELECT U.Artwork_ID, A.Artwork_Name, L.Loan_Start_Date, A.Artwork_Dimensions, A.Artwork_Medium, A.Artwork_Weight, U.Unscheduled_Repairs,
	CASE U.Unscheduled_Request
		WHEN 'Y' THEN U.Unscheduled_Repairs_Request
		ELSE 'None Needed'
	END Unscheduled_Repairs_Requested
	FROM Artwork A, Unscheduled U, Loan L
	WHERE A.Artwork_ID = U.Artwork_ID AND L.Artwork_ID = U.Artwork_ID;

-- Show the unscheduledArtwork view and test it
DESC unscheduledArtwork
SELECT * FROM unscheduledArtwork;
SELECT Artwork_Name, Artwork_Medium, Loan_Start_Date, Unscheduled_Repairs_Requested, Unscheduled_Repairs
FROM unscheduledArtwork
WHERE Artwork_ID = '217473';

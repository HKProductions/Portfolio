/*
Project Option: Coyote Inland Empire Art Museum
Description: This script creates comments for all the tables and each element inside of the table
Author: Hamza Khan 005125350
*/

COMMENT ON TABLE Collection IS 'Gives artwork collection ID';
COMMENT ON TABLE Slides IS 'Slide information on artwork';
COMMENT ON TABLE Location IS 'Gives information about an artworks location';
COMMENT ON TABLE Maintenance IS 'Describes scheduled maintenance needed to be done on artwork';
COMMENT ON TABLE Musuem IS 'Gives musuem information to museum';
COMMENT ON TABLE Member IS 'Gives member information to museum';
COMMENT ON TABLE NonMember IS 'Gives nonmember information to museum';
COMMENT ON TABLE Acquisition IS 'Gives museum information about how an artwork was obtained';
COMMENT ON TABLE Loan IS 'Gives loan information about which museum an artwork was loaned from';
COMMENT ON TABLE Unscheduled IS 'Describes unscheduled maintenance needed on an artwork';
COMMENT ON TABLE Artwork IS 'Gives artwork information';

COMMENT ON COLUMN Collection.Collection_ID IS 'An artworks collection number an artwork belongs in';
COMMENT ON COLUMN COllection.Artwork_ID IS 'An artworks ID to associate it to the collection it belongs to';

COMMENT ON COLUMN Slides.Slides_ID IS 'An artworks slide id if it has one';
COMMENT ON COLUMN Slides.Artwork_ID IS 'An artworks ID to associate the slide to the artwork';

COMMENT ON COLUMN Location.Location_ID IS 'An artworks location ID set for an artwork';
COMMENT ON COLUMN Location.Artwork_ID IS 'An artworks ID used to find its location';
COMMENT ON COLUMN Location.Location_Address IS 'The actual location of an artwork';

COMMENT ON COLUMN Maintenance.Artwork_ID IS 'An artworks ID used tro get information for a scheduled maintenance';
COMMENT ON COLUMN Maintenance.Maintenance_Scheduled IS 'The maintenance the artwork needs that day';

COMMENT ON COLUMN Musuem.Musuem_ID IS 'Used to identify what musuem the artwork is from';
COMMENT ON COLUMN Musuem.Name IS 'The name of the musuem the artwork is from';
COMMENT ON COLUMN Musuem.Address IS 'The address of the musuem the artwork is from';

COMMENT ON COLUMN Member.Member_ID IS 'Used to identify a member of the musuem';
COMMENT ON COLUMN Member.Name IS 'The name of a member';
COMMENT ON COLUMN Member.Address IS 'The address of a member';
COMMENT ON COLUMN Member.Member_Membership_Type IS 'The type of membership the member is part of';

COMMENT ON COLUMN NonMember.NonMember_ID IS 'Used to identify a non member of the museum';
COMMENT ON COLUMN NonMember.Name IS 'The name of the civilian';
COMMENT ON COLUMN Nonmember.Address IS 'The address of the civilian';

COMMENT ON COLUMN Acquisition.Acquisition_ID IS 'Used to find the artrwork that was acquired by the musuem';
COMMENT ON COLUMN Acquisition.Artwork_ID IS 'Used to get the artwork that is acquired by the museum';
COMMENT ON COLUMN Acquisition.Acquisition_Type IS 'Used to describe how the musuem got the artwork';
COMMENT ON COLUMN Acquisition.Acquisition_FROM IS 'Used to describe who the acquisiton came from';
COMMENT ON COLUMN Acquisition.Acquisition_Member_ID IS 'Used to get the member information if the artwork was acquired from a member';
COMMENT ON COLUMN Acquisition.Acquisition_Musuem_ID IS 'Used to get the museum information if the artwork was acquired froma museum';
COMMENT ON COLUMN Acquisition.Acquisition_NonMember_ID IS 'Used to get the Non Member information if the artwork is acquired from a civilian';
COMMENT ON COLUMN Acquisition.Acquisition_Date IS 'The date the artwork was acquired';
COMMENT ON COLUMN Acquisition.Acquisition_Value IS 'The value of the artwork that was aquired';

COMMENT ON COLUMN Loan.Artwork_ID IS 'Used to find if an artwork is on loan';
COMMENT ON COLUMN Loan.Loan_Museum_ID IS 'Used to find the musuem the artwork is on loan from';
COMMENT ON COLUMN Loan.Loan_Number IS 'Used to find other artworks that are on loan';
COMMENT ON COLUMN Loan.Loan_Start_Date IS 'The date the arwork started its time in the loaned musuem';
COMMENT ON COLUMN Loan.Loan_End_Date IS 'The date the artwork has to be returned';

COMMENT ON COLUMN Unscheduled.Artwork_ID IS 'Used to get artwork information form loan table';
COMMENT ON COLUMN Unscheduled.Unscheduled_Request IS 'Used to see if the artwork needs to be repaired on for an emergency';
COMMENT ON COLUMN Unscheduled.Unscheduled_Repairs_Request IS 'Used to tell maintenance if the artwork needs maintenance before shipping before the usual';
COMMENT ON COLUMN Unscheduled.Unscheduled_Repairs IS 'Used to do any emergancy maintenance an artwork needs';

COMMENT ON COLUMN Artwork.Artwork_ID IS 'Used to find information about an artwork';
COMMENT ON COLUMN Artwork.Artwork_Collection_ID IS 'Used to find if the artwork is part of a collection in the museum';
COMMENT ON COLUMN Artwork.Artwork_Location_ID IS 'Used to find the location the artwork is located in the museeum';
COMMENT ON COLUMN Artwork.Artwork_Dimensions IS 'The dimensions of the artwork in inches';
COMMENT ON COLUMN Artwork.Artwork_Medium IS 'The medium the artwork is part of';
COMMENT ON COLUMN Artwork.Artwork_Name IS 'The name of the artwork';
COMMENT ON COLUMN Artwork.Artwork_Weight IS 'The weight of the artwork';
COMMENT ON COLUMN Artwork.Artwork_Year IS 'The year the artwork is from'; 

SET PAUSE OFF
START testTables.sql

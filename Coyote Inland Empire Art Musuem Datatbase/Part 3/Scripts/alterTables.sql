/*
Project Option: Coyote Inland Empire Art Museum
Description: The purpose of this table is to alter the tables so they can share
	and communcte between each other.
Author: Hamza Khan 005125350
*/

ALTER TABLE Collection
	ADD CONSTRAINTS Collection_Artwork_ID_FK FOREIGN KEY (Artwork_ID) REFERENCES Artwork(Artwork_ID);

ALTER TABLE Slides
	ADD CONSTRAINTS Slides_Artwork_ID_FK FOREIGN KEY (Artwork_ID) REFERENCES Artwork(Artwork_ID);

ALTER TABLE Location
	ADD CONSTRAINTS Location_Artwork_ID_FK FOREIGN KEY (Artwork_ID) REFERENCES Artwork(Artwork_ID);

ALTER TABLE Maintenance 
	ADD CONSTRAINTS Maintenance_Artwork_ID_FK FOREIGN KEY (Artwork_ID) REFERENCES Artwork(Artwork_ID);

ALTER TABLE Acquisition
	ADD CONSTRAINTS Acquisition_Artwork_ID_FK FOREIGN KEY (Artwork_ID) REFERENCES Artwork(Artwork_ID);

ALTER TABLE Acquisition
	ADD CONSTRAINTS Acquisition_Member_ID_FK FOREIGN KEY (Acquisition_Member_ID) REFERENCES  Member(Member_ID);

ALTER TABLE Acquisition
	ADD CONSTRAINTS Acquisition_Musuem_ID_FK FOREIGN KEY (Acquisition_Musuem_ID) REFERENCES Musuem(Musuem_ID);

ALTER TABLE Acquisition
	ADD CONSTRAINTS Acquisition_NonMember_ID_FK FOREIGN KEY (Acquisition_NonMember_ID) REFERENCES NonMember(NonMember_ID);

ALTER TABLE Loan
	ADD CONSTRAINTS Loan_Artwork_ID_FK FOREIGN KEY (Artwork_ID) REFERENCES Artwork(Artwork_ID);

ALTER TABLE Unscheduled
	ADD CONSTRAINTS Unscheduled_Artwork_ID_FK FOREIGN KEY (Artwork_ID) REFERENCES Loan(Artwork_ID);

ALTER TABLE Artwork
	ADD CONSTRAINTS Artwork_Collection_ID_FK FOREIGN KEY (Artwork_Collection_ID) REFERENCES Collection(Collection_ID);

ALTER TABLE Artwork
	ADD CONSTRAINTS Artwork_Location_ID_FK FOREIGN KEY (Artwork_Location_ID) REFERENCES Location(Location_ID); 


SET PAUSE OFF;
START insertTables.sql;

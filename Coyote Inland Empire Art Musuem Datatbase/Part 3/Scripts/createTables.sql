/* 
Project Option: Coyote Inland Empire Art Musuem
Purpose: The purpose of this script is to create the appropriate tables for 
	the database.
Author: Hamza Khan 005125350
*/

DROP TABLE Collection CASCADE CONSTRAINTS;
CREATE TABLE Collection (
	Collection_ID CHAR(10),
	Artwork_ID CHAR(10) UNIQUE NOT NULL,
	CONSTRAINTS Collection_PK PRIMARY KEY (Collection_ID)
);

DROP TABLE Slides CASCADE CONSTRAINTS;
CREATE TABLE Slides (
	Slides_ID CHAR(10),
	Artwork_ID CHAR(10),
	CONSTRAINTS Slides_PK PRIMARY KEY (Slides_ID)
);

DROP TABLE Location CASCADE CONSTRAINTS;
CREATE TABLE Location (
	Location_ID CHAR(10),
	Artwork_ID CHAR (10) UNIQUE NOT NULL,
	Location_Address VARCHAR2(30) NOT NULL,
	CONSTRAINTS Location_PK PRIMARY KEY (Location_ID)
);

DROP TABLE Maintenance CASCADE CONSTRAINTS;
CREATE TABLE Maintenance (
	Artwork_ID CHAR(10),
	Maintenance_Scheduled VARCHAR2(30),
	CONSTRAINTS Maintenance_PK PRIMARY KEY (Artwork_ID)
);

DROP TABLE Musuem CASCADE CONSTRAINTS;
CREATE TABLE Musuem (
	Musuem_ID CHAR(10),
	Name VARCHAR2(30) NOT NULL,
	Address VARCHAR2(50) NOT NULL,
	CONSTRAINTS Musuem_PK PRIMARY KEY (Musuem_ID)
);

DROP TABLE Member CASCADE CONSTRAINTS;
CREATE TABLE Member (
	Member_ID CHAR(10),
	Name VARCHAR2(30) NOT NULL,
	Address VARCHAR2(50) NOT NULL,
	Member_Membership_Type VARCHAR2(30) NOT NULL,
	CONSTRAINTS Member_PK PRIMARY KEY (Member_ID)
);

DROP TABLE NonMember CASCADE CONSTRAINTS;
CREATE TABLE NonMember (
	NonMember_ID CHAR(10),
	Name VARCHAR2(30) NOT NULL,
	Address VARCHAR2(50) NOT NULL,
	CONSTRAINTS NonMember_PK PRIMARY KEY (NonMember_ID)
);

DROP TABLE Acquisition CASCADE CONSTRAINTS;
CREATE TABLE Acquisition (
	Acquisition_ID CHAR(10),
	Artwork_ID CHAR(10),
	Acquisition_Type VARCHAR(20) NOT NULL,
	Acquisition_From CHAR(1) NOT NULL,
	Acquisition_Member_ID CHAR(10),
	Acquisition_Musuem_ID CHAR(10),
	Acquisition_NonMember_ID CHAR(10),
	Acquisition_Date DATE NOT NULL,
	Acquisition_Value VARCHAR(12) NOT NULL,
	CONSTRAINTS Acquisition_PK PRIMARY KEY (Acquisition_ID),
	CONSTRAINTS Acquisition_From_CK CHECK (Acquisition_From IN ('1','2','3'))
);

DROP TABLE Loan CASCADE CONSTRAINTS;
CREATE TABLE Loan (
	Artwork_ID CHAR(10),
	Loan_Museum_ID CHAR(10) NOT NULL,
	Loan_Number CHAR(10) NOT NULL,
	Loan_Start_Date DATE NOT NULL,
	Loan_End_Date DATE NOT NULL,
	CONSTRAINTS Loan_PK PRIMARY KEY (Artwork_ID)
);

DROP TABLE Unscheduled CASCADE CONSTRAINTS;
CREATE TABLE Unscheduled (
	Artwork_ID CHAR(10),
	Unscheduled_Request CHAR(1),
	Unscheduled_Repairs_Request VARCHAR2(30),
	Unscheduled_Repairs VARCHAR2(30),
	CONSTRAINTS Unscheduled_PK PRIMARY KEY (Artwork_ID),
	CONSTRAINTS Unscheduled_Request_CK CHECK (Unscheduled_Request IN ('Y','N'))
);

DROP TABLE Artwork CASCADE CONSTRAINTS;
CREATE TABLE Artwork (
	Artwork_ID CHAR(10),
	Artwork_Collection_ID CHAR(10),
	Artwork_Location_ID CHAR(10),
	Artwork_Dimensions CHAR(11),
	Artwork_Medium VARCHAR2(10),
	Artwork_Name VARCHAR2(30),
	Artwork_Weight CHAR(5),
	Artwork_Year CHAR(4),
	CONSTRAINTS Artwork_PK PRIMARY KEY (Artwork_ID)
);


SET PAUSE OFF;
START alterTables.sql;

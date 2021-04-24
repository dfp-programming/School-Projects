<?php


/*
This class is called upon by fileUploadProc.php to insert a couple of strings into a database.
To connect to the database, this class calls unpon Db_conn.php.

*/

require_once "Db_conn.php";

class DBInputOutput
{
	private $db;
	private $conn;

	/* CREATES A CONNECTION TO THE DATABASE */
	private function db_connection()
	{
		$this->db = new DatabaseConn();
		$this->conn = $this->db->dbOpen();
	}

	public function insertData($data = '', $column = '', $DBNAME = '')
	{

		$sqlQuery = "INSERT INTO $DBNAME ($column) VALUES (?);";
		try {

			if ($data == '' || $column == '' || $DBNAME == '')
				throw ("insertData() - BAD FUNCTION CALL");

			//opening the database
			$this->db_connection();

			//creating PDO statement from the database object
			$PDOstmt = $this->conn->prepare($sqlQuery);

			//mySQL injection protection.  I found out in the internet that if you use question mark place holders,
			//the you must use an integer representing the questionmark count up to it. I had tried it using just '?'
			//and it seemed to work, but then if you have more question marks, it would not be so good. 

			$PDOstmt->bindValue(1, $data, PDO::PARAM_STR); //bind file data

			//Making PDO useful and finally insert into the DB.  Yes super secure, but takes too long.  
			//There should be a method that takes care of all of this at once. Pass an array and forget :) 
			$PDOstmt->execute();

			//closing the database to avoid multiple connections and crashes
			$this->conn = NULL;

			return "NO ERROR";
		} catch (PDOException $e) {
			return $e->getMessage();
		}
	}

	public function getData($DBNAME = '')
	{
		$sqlQuery = "SELECT name FROM $DBNAME;";
		try {

			//opening the database
			$this->db_connection();

			//prepare statement
			$PDOstmt = $this->conn->query($sqlQuery);

			//extracting all of columns into an array.
			$dataArray = $PDOstmt->fetchAll();

			//closing the database to avoid multiple connections and crashes
			$this->conn = NULL;

			return $dataArray;
		} catch (PDOException $e) {
			return $e->getMessage();
		}

		// $sqlQuery = "SELECT name FROM $DBNAME;";
		// try {

		// 	//opening the database
		// 	$this->db_connection();

		// 	$PDOstmt = $this->conn->query($sqlQuery);

		// 	//$PDOstmt->bindValue(1, $DBNAME, PDO::PARAM_STR);
			
		// 	//extracting all of columns into an array.
		// 	$dataArray = $PDOstmt->fetchAll();

		// 	//closing the database to avoid multiple connections and crashes
		// 	$this->conn = NULL;

		// 	return $dataArray;
		// } catch (PDOException $e) {
		// 	return $e->getMessage();
		// }
	}

	public function clearDatabase($DBNAME = '')
	{

		$sqlQuery = "TRUNCATE TABLE $DBNAME;";
		try {

			//opening the database
			$this->db_connection();

			//preparying the query
			$PDOstmt = $this->conn->prepare($sqlQuery);

			//running the query
			$PDOstmt->execute();

			//closing the database to avoid multiple connections and crashes
			$this->conn = NULL;
		
		} catch (PDOException $e) {
			return $e->getMessage();
		}
	}


}

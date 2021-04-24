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

	//this function take an associative array, where the keys match the table columns
	public function insertData($data = '', $table = '')
	{

		$questionMarks = "?";
		$count = 1;

		$sqlQuery = "INSERT INTO $table (1) VALUES (2);";
		$dataKeys="";

		try {

			if(!is_array($data) || count($data) == 0 || $table =='')
				throw("BAD FUNCTION CALL: insertData() - Bad Argument");

			$dataKeys = array_keys($data);

			 //making a question mark string based on the array size
			for($i = 0; $i< count($data)-1;$i++)
				$questionMarks.=", ?";

			//replace the question mark string into sqlquery
			$sqlQuery = str_replace("1", $questionMarks, $sqlQuery);
			$sqlQuery = str_replace("2", $questionMarks, $sqlQuery);

			//changing the first set of ? with the input array keys. 
			foreach($dataKeys as $value)
				$sqlQuery = preg_replace('/\?/', $value, $sqlQuery, 1);

			//opening the database
			$this->db_connection();

			//creating PDO statement from the database object
			$PDOstmt = $this->conn->prepare($sqlQuery);

			//binding dynamically the second set of ? - I tried doing both lef and right sets first, but it 
			//didnt quite work for me.  Maybe there is a way! 
			
			foreach($data as $value){
				$PDOstmt->bindValue($count, $value, PDO::PARAM_STR);
				$count++;
			}
			
			//inserting into database - Finally!
			$PDOstmt->execute();

			//closing the database to avoid multiple connections and crashes
			$this->conn = NULL;

			return "NO ERROR";
		} catch (PDOException $e) {
			return $e->getMessage();
		}
	}

	public function getData($table = '')
	{
		$sqlQuery = "SELECT * FROM $table;";
		try {

			if($table == '')
				throw("BAD FUNCTION CALL: getData() - Bad Argument");

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
	}

	public function clearDatabase($table = '')
	{

		$sqlQuery = "TRUNCATE TABLE $table;";
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

<?php

/*
To connect to the database, this class calls unpon Db_conn.php,
which is meant to be on the server, and it has the necessary credentials
to access the database


There are five methods to this class.

	db_connection() => uses the DatabaseConn() class to opens the database.  Returns true or false.

	insertData($data = '', $table = '') => The first argument is an associative array, 
		where the keys name must match the table column names and point to the data for each column.
		The second argument is simply the name of the table.  returns "NO ERROR" or a string with a message. 

	getData($table = '') => pass on the table name, and it this will return an array with
		the data for all of the columns. returns an array or a string with a message. 

	deleteRow($table = '', $column = '', $value) => will evaluate where a colum equals a value
		then delete that row . returns "NO ERROR" or a string with a message. 

	clearTable($table = '') => deletes a table, just pass the name. returns "NO ERROR" or a string with a message. 

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

		if (is_string($this->conn))
			return "DBInputOutput::db_connection() - failure opening the database: $this->conn";
		else
			return "NO ERROR";
	}

	//this function take an associative array, where the keys match the table columns, and the values are the data
	public function insertData($table = '', $data = array())
	{
		$questionMarks = "?";
		$count = 1;

		$sqlQuery = "INSERT INTO $table (1) VALUES (2);";
		$dataKeys = "";

		$check = false;

		try {

			if (!is_array($data) || count($data) == 0 || !is_string($table))
				throw new PDOException("DBInputOutput::insertData() Bad Argument");

			//opening the database
			$check = $this->db_connection();

			if (!$check == "NO ERROR")
				throw new PDOException("DBInputOutput::insertData() - $check");

			$dataKeys = array_keys($data);

			//making a question mark string based on the array size
			for ($i = 0; $i < count($data) - 1; $i++)
				$questionMarks .= ", ?";

			//replace the question mark string into sqlquery
			$sqlQuery = str_replace("1", $questionMarks, $sqlQuery);
			$sqlQuery = str_replace("2", $questionMarks, $sqlQuery);

			//changing the first set of ? with the input array keys. 
			foreach ($dataKeys as $value)
				$sqlQuery = preg_replace('/\?/', $value, $sqlQuery, 1);

			//creating PDO statement from the database object
			$PDOstmt = $this->conn->prepare($sqlQuery);

			//binding dynamically the second set of ? - I tried doing both lef and right sets first, but it 
			//didnt quite work for me.  Maybe there is a way! 

			foreach ($data as $value) {
				$PDOstmt->bindValue($count, $value, PDO::PARAM_STR);
				$count++;
			}

			//inserting into database - Finally!
			$check = $PDOstmt->execute();

			if ($check == false)
				throw new PDOException("DBInputOutput::inserData() - excecute statement failed");

			//closing the database to avoid multiple connections and crashes
			$this->conn = NULL;

			return "NO ERROR";
		} catch (PDOException $e) {
			$this->conn = NULL;
			return $e->getMessage();
		}
	}

	//This function returns an array with all of the table data
	public function getData($table = '')
	{
		$sqlQuery = "SELECT * FROM $table;";
		$check = false;
		try {

			if (!is_string($table))
				throw new PDOException("DBInputOutput::getData() - Bad Argument");

			//opening the database
			$check = $this->db_connection();

			if (!$check == "NO ERROR")
				throw new PDOException("DBInputOutput::getData() - $check");

			//prepare statement
			$PDOstmt = $this->conn->query($sqlQuery);

			//extracting all of columns into an array.
			$dataArray = $PDOstmt->fetchAll();

			//closing the database to avoid multiple connections and crashes
			$this->conn = NULL;

			if (is_array($dataArray))
				return $dataArray;
			else
				throw new PDOException("DBInputOutput::getData() - fetchall failure");
		} catch (PDOException $e) {
			$this->conn = NULL;
			return $e->getMessage();
		}
	}

	public function deleteRow($table = '', $column = '', $value)
	{
		$sqlQuery = "DELETE FROM $table where $column=:$value;";

		$check = false;

		try {
	
			if (!is_string($table) || !is_string($column) || !is_string($value))
				throw new PDOException("DBInputOutput::deleteRow() - Bad Argument");

			//opening the database
			$check = $this->db_connection();

			if (!$check == "NO ERROR")
				throw new PDOException("DBInputOutput::deleteRow() - $check");

			$PDOstmt = $this->conn->prepare($sqlQuery);

			$check = $PDOstmt->execute([":$value" => "$value"]);

			if ($check == false)
				throw new PDOException("DBInputOutput::deleteRow() - execute statement failed");

			//closing connection
			$this->conn = NULL;

			return "NO ERROR";

		} catch (PDOException $e) {
			
			$this->conn = NULL;
			return $e->getMessage();
		}
	}

	//Clear yout entire table
	public function clearTable($table = '')
	{
		$sqlQuery = "TRUNCATE TABLE $table;";
		$check = false;

		try {

			if (!is_string($table))
				throw new PDOException("DBInputOutput::clearTable() - Bad Argument");

			//opening the database
			$check = $this->db_connection();

			if ($check == false)
				throw new PDOException("DBInputOutput::clearTable() - Failure to open database");

			//preparying the query
			$PDOstmt = $this->conn->prepare($sqlQuery);

			//running the query
			$check = $PDOstmt->execute();

			if ($check == false)
				throw new PDOException("DBInputOutput::clearTable() - excecute statement failed");

			//closing the database to avoid multiple connections and crashes
			$this->conn = NULL;

			return "NO ERROR";
		} catch (PDOException $e) {
			$this->conn = NULL;
			return $e->getMessage();
		}
	}
}

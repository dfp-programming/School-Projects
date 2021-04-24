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

    public function insertName($name)
    {

        $sqlQuery = "INSERT INTO file_name_list (filename,filepath) VALUES (?,?);";
        try {

            //opening the database
            $this->db_connection();

            //creating PDO statement from the database object
            $PDOstmt = $this->conn->prepare($sqlQuery);

            //mySQL injection protection.  I found out in the internet that if you use question mark place holders,
            //the you must use an integer representing the questionmark count up to it. I had tried it using just '?'
            //and it seemed to work, but then if you have more question marks, it would not be so good. 

            $PDOstmt->bindValue(1,$name,PDO::PARAM_STR);//bind file name
            $PDOstmt->bindValue(2,"files_directory/".$name,PDO::PARAM_STR); //bind file path

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

    public function retrieveNames(){

        $sqlQuery = "SELECT filename, filepath FROM file_name_list;";
        try {

            //opening the database
            $this->db_connection();

            //creating PDO statement from the database object
            //It is ok to use the query function because I dont have any values to bind. 
            //If the search was more complex, then I could simply use the bindValue() function for
            //protection agaist sql injection attacks. 
            $PDOstmt = $this->conn->query($sqlQuery);
                                  
            //extracting all of the file names and paths into an array.
            $fileNameArray = $PDOstmt->fetchAll();

            //closing the database to avoid multiple connections and crashes
            $this->conn = NULL;

            return $fileNameArray;
        } catch (PDOException $e) {
            return $e->getMessage();
        }

    }
}

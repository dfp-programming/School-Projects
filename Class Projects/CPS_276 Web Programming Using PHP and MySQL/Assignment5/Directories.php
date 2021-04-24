<?php

class Directories
{

    private const LOCAL_ROOT = "directories/";
    private const FILE_TO_CREATE = "/readme.txt";
    private $fileContents = "";
    private $dirName = "";


    public function getData()
    { //Iitialize variables or throw exception if bad data is found

        if ($_POST["button"] == "submitButtonPressed") {

            if ($_POST["folderNameField"] == "" || $_POST["folderNameField"][0] == '/')
                throw new Exception("Bad directory name.");

            else {
                $this->dirName = self::LOCAL_ROOT . $_POST["folderNameField"];
                $this->fileContents = $_POST["fileContentsBox"];
            }
        }
    }

    private function checkDir()
    { //returns an error if the directory already exist

        if (file_exists("$this->dirName") || is_dir("$this->dirName"))
            throw new Exception("Directory already exists.");
    }

    private function createDir()
    { //Will check if the directory is viable, and proceed to create it if no exceptions are thrown
        $this->checkDir("$this->dirName");
        mkdir($this->dirName, 0777, true);
    }

    private function createFile()
    { //returns the path to the file created

        $readMeFile = fopen($this->dirName . self::FILE_TO_CREATE, "w+");
        fwrite($readMeFile, $this->fileContents);
        fclose($readMeFile);

        return $this->dirName . self::FILE_TO_CREATE;
    }

    public function dataStorage()
    {

        //run these functions, and if one throws an exception, then return it as a string.
        try {
            $this->getData();
            $this->createDir();
            $filePath = $this->createFile();
        } catch (Exception $e) {
            return $e->getMessage() . "<br><br>";
        }

        //reset the variables
        $this->fileContents = "";
        $this->dirName = "";

        return "<p>File and directory were created</p>" . "<a href=\"$filePath\">$filePath</a>" . "<br><br>";
    }
}

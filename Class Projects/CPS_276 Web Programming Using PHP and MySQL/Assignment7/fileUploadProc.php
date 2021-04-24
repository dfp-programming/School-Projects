<?php

/*

This class is called by index.php and checks varios conditions that would invalidate the file
upload process.  If all goes well, it calls upon DBInputOutput to insert the name and path
into the database.  It also moves the file uploaded into the apropiate folder inside the server. 

*/

require_once 'DBInputOutput.php';

class fileHandler
{
    private $DBIO;
    private const LOCAL_ROOT = "files_directory/";
    private $extension;
    private $maxFileSize;
    private $allowedFileTypes;// = array("pdf");//initially I had made this an array so it could take many file formats.
    private $fileUploadError = array(
        "UPLOAD_ERR_OK",
        "UPLOAD_ERR_INI_SIZE",
        "UPLOAD_ERR_FORM_SIZE",
        "UPLOAD_ERR_NO_FILE",
        "UPLOAD_ERR_NO_TMP_DIR",
        "UPLOAD_ERR_CANT_WRITE",
        "UPLOAD_ERR_EXTENSION"
    );

    //pass an array with the file extensions you want to allow into the server
    public function __construct($fileTypeArray,$size=10240) {
        
            $this->extension = "";
            $this->DBIO = new DBInputOutput();
            $this->allowedFileTypes = $fileTypeArray;
            $this->maxFileSize = $size;
    }

    private function correctFileType()
    {
        $inboundFileExtension = $_FILES["incomingFile"]["type"];
        $inboundFileExtension = strtolower($inboundFileExtension); //ensure there are no upper case characters
        $inboundFileExtension = explode('/', $inboundFileExtension);//explode into an array

        //this method took some trial and error.  The file type is not located
        //in the same part of the array everytime.  For example, a text file is text/plain
        //while a jpeg is image/jpeg.  So I got creative with a foreach loop and the in_array() function;

        foreach($this->allowedFileTypes as $type){//check if any of allowed file types are present in the file extension array
            if(in_array($type,$inboundFileExtension)){
                $this->extension = $type;
                return true;
            }
        }

        return false;
    }

    private function fileTooBig()
    {
        if ($_FILES["incomingFile"]["size"] > $this->maxFileSize)
            return true;
        else
            return false;
    }

    private function uploadFile()
    {
        $temp = $_FILES["incomingFile"]["tmp_name"];
        $fileName = $_POST["fileNameField"];
        
        if($filename='' || $fileName == NULL)
            throw("NO FILE NAME WAS ENTERED"); 
        else{
            move_uploaded_file($temp, self::LOCAL_ROOT . $fileName . '.' . $this->extension);
            $status = $this->DBIO->insertName($fileName . '.' . $this->extension);
        }

        if($status =="NO ERROR")
            return;
        else
            throw("THERE WAS AN ERROR UPLOADING TO THE DATABASE = $status");
    }

    public function checkAndUpload()
    {
        try {

            if ($_POST["button"] == "uploadFileRequest") {

                $this->file = $_FILES;

                if (!$this->correctFileType()) //check file type
                    throw new Exception("FILE EXTENSION NOT ALLOWED OR NO FILE SELECTED");

                else if ($this->fileTooBig()) //check file size
                    throw new Exception("FILE SIZE OVER ALLOWED LIMIT");

                else if ($_FILES["incomingFile"]["error"] != 0) //see if anything besides error_ok happened
                    throw new Exception($this->fileUploadError[$_FILES["incomingFile"]["error"]]);

                else if ($_POST["fileNameField"] == "" || $_POST["fileNameField"][0] == '/') //check for correct file name
                    throw new Exception("NO FILE NAME ENTERED");

                else
                    $this->uploadFile();

                return "FILE UPLOADED CORRECTLY";
            }
        } catch (Exception $e) {
            return $e->getMessage() . "<br><br>";
        }
    }
}

<?php

/* 

WORKFLOW: Index provides means to inser a file name and upload a file.  To do so, it calls
upon the fileHandler class, which takes care of all the checks that could invalidate the action.
If all of the checks pass, fileHandler calls upon DBinputOutput, so it can insert data into the database
and will save the file int he server will the appropiate name.

Index.php displays a hyperlink to listFilesProc.php which pulls all of the file paths and displays 
them in a unordered list. It does so by calling upon the DBInputOutput.php class. 

I hope you like my program!

Diego F. Perez
CPS276 - 09Nov2020

*/


$message = "";

if ($_POST) {
    require_once "fileUploadProc.php";
    //pass an array with the file types you want to allow, and int maxSize. 
    $uploadMyFile = new fileHandler(array('pdf'), 102400); 
    $message =  $uploadMyFile->checkAndUpload($_POST);
}
 
?>

<!doctype html>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css" integrity="sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2" crossorigin="anonymous">

    <title>Assignment 7</title>
</head>

<body>
    <div class="container">
        <h1>File Upload</h1>
        <form method="post" action="index.php" enctype="multipart/form-data">
            <div class="form-group">
                <a href="listFilesProc.php">Show File List</a><br>
                <label for="fileNameField">File Name</label>
                <input type="text" class="form-control" name="fileNameField" id="fileNameField" placeholder="File name goes here">
                <input type="file" name="incomingFile" id="fileSelectField">
            </div>
            <button type="submit" name="button" class="btn btn-primary" value="uploadFileRequest">Upload File</button>
            <p><?php echo $message; ?></p>
        </form>
        <!-- Option 1: jQuery and Bootstrap Bundle (includes Popper) -->
        <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ho+j7jyWK8fNQe+A12Hb8AhRq26LrZ/JpcUGGOn+Y7RsweNrtN/tE3MoK7ZeZDyx" crossorigin="anonymous"></script>
    </div>
</body>

</html>
<?php

/*
This class will use DBInputOutput.php to retrieve the path of all files present in the database.
It will all be displayed as an unordered list.  then a link to return back to the main page. 
*/

include_once "DBInputOutput.php";
$DB = new DBInputOutput(); //Custom class I made for inserting file names into a mysql table
$fileNameArray = $DB->retrieveNames(); //This variable will either contain an array of names, or a exception string

?>

<!doctype html>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css"
     integrity="sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2" crossorigin="anonymous">

    <title>File List</title>
</head>

<body>
    <div class="container">
        <h1>List Files</h1>
        <div>
            <ul>
                <?php
                if (is_array($fileNameArray))
                    foreach ($fileNameArray as $file)
                        echo "<li><a target='_blank' href=\"$file[1]\"> $file[1]</a></li>";
                else
                    echo $fileNameArray; //we go down this path if this variable was to contain an exception or something.
                ?>
            </ul>
        </div>

        <p> <a href="index.php"> Go back to add more files</a> </p>
        <!-- Option 2: jQuery, Popper.js, and Bootstrap JS
    <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.1/dist/umd/popper.min.js" integrity="sha384-9/reFTGAW83EW2RDu2S0VKaIzap3H66lZH81PoYlFhbGU+6BZp6G7niu735Sk7lN" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/js/bootstrap.min.js" integrity="sha384-w1Q4orYjBQndcko6MimVbzY0tgp4pWB4lZ7lr30WKz0vr/aWKhXdBNmNb5D92v7s" crossorigin="anonymous"></script>
    -->
    </div>
</body>

</html>
<?php

$output=NULL;

if (isset($_POST["button"])) {

    require_once 'Directories.php';
    $fileCreation = new Directories();
    $output = $fileCreation->dataStorage($_POST);
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

    <title>Assignment 5</title>
</head>

<body>
    <div class="container">
        <h1>File and Directory Assignment</h1>
        <p>Enter a folder name and the contents of a file. Folder names should contain alpha numeric characters only.</P>
        <?php echo $output; ?>
        <form method="post" action="index.php">
            <div class="form-group">
                <label for="folderNameField">Folder Name</label>
                <input type="text" class="form-control" name="folderNameField" id="folderNameField" placeholder="mydirectory/subdirectory">
            </div>
            <div class="form-group">
                <label for="fileContentsBox">File Contents</label>
                <textarea style="height: 500px;" type="password" class="form-control" id="fileContentsBox" name="fileContentsBox">
                </textarea>
            </div>
            <button type="submit" name="button" class="btn btn-primary" value="submitButtonPressed">Submit</button>
        </form>
        <!-- Option 1: jQuery and Bootstrap Bundle (includes Popper) -->
        <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ho+j7jyWK8fNQe+A12Hb8AhRq26LrZ/JpcUGGOn+Y7RsweNrtN/tE3MoK7ZeZDyx" crossorigin="anonymous"></script>

    </div>
</body>

</html>
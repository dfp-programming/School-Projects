<?php

$output = "";

if (count($_POST) > 0) {
    require_once 'addNameProc.php';
    $addName = new addNameProc();
    $output = $addName->addClearNames($_POST);
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

    <title>Assignment 4</title>
</head>

<body>
    <div class="container">
        <h1>Add Names</h1>
        <form method="post" action="index.php">
            <button type="submit" name="button" class="btn btn-primary" value="addNameButton">Add Name</button>
            <button type="submit" name="button" class="btn btn-primary" value="clearNameButton">Clear Names</button>
            <div class="form-group">
                <label for="inputName">Enter Name</label>
                <input type="text" class="form-control" name="inputNameField" id="inputName" placeholder="John Doe">
            </div>
            <div class="form-group">
                <label for="nameListField">List of Names</label>
                <textarea style="height: 500px;" type="password" class="form-control" id="nameListField" name="nameListField">
                <?php echo $output; ?> 
                </textarea>
            </div>
        </form>
        <!-- Option 1: jQuery and Bootstrap Bundle (includes Popper) -->
        <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ho+j7jyWK8fNQe+A12Hb8AhRq26LrZ/JpcUGGOn+Y7RsweNrtN/tE3MoK7ZeZDyx" crossorigin="anonymous"></script>

    </div>
</body>

</html>
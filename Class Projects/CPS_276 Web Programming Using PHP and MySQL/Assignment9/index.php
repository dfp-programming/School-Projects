<?php

$dt = null;
$msg = null;
if (isset($_POST["button"])) {
    require_once 'notesIO.php';
    $dt = new notesIO();
    $msg = $dt->addNote($_POST);
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

    <title>Assignment 9</title>
</head>

<body>
    <div class="container">
        <h1>Add Note Assignment</h1>
        <a href="getNotes.php">Display Notes<a>
                <form method="post" action="index.php">
                    <div>
                        <?php echo $msg ?>
                    </div>
                    <div class="form-group">
                        <label for="noteDate">Date and Time</label>
                        <input type="datetime-local" class="form-control" id="noteDate" name="noteDate">
                    </div>
                    <div class="form-group">
                        <label for="noteField">Note Contents</label>
                        <textarea style="height: 500px;" type="text" class="form-control" id="noteField" name="noteField">
                        </textarea>
                    </div>
                    <button type="submit" name="button" class="btn btn-primary" value="addNoteButton">Add Note</button>
                </form>
                <!-- Option 1: jQuery and Bootstrap Bundle (includes Popper) -->
                <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous">
                </script>
                <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ho+j7jyWK8fNQe+A12Hb8AhRq26LrZ/JpcUGGOn+Y7RsweNrtN/tE3MoK7ZeZDyx" crossorigin="anonymous">
                </script>

    </div>
</body>

</html>
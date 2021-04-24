<?php

//I tried a relative path here but it wasnt working... not sure why. 
require_once "/var/www/html/classes/Pdo_methods.php";

try {

    $DBIO = new DBInputOutput();
    $namesArray = $DBIO->clearDatabase('names');

    $response = (object)[
        'masterstatus'=>'success',
        'msg'=> "<p><strong>The names database has been cleared...</strong></p>"
        ];
    
    echo json_encode($response);
  

} catch (PDOException $e) {
    
    $thisIsWhatHappened = $e->getMessage();

    $response = (object)[
        'masterstatus'=>'error',
        'msg'=> "something went wrong: $thisIsWhatHappened"
        ];
        
        echo json_encode($response, JSON_FORCE_OBJECT);
  
}

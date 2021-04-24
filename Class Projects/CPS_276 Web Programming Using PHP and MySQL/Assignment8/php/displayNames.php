<?php

//I tried a relative path here but it wasnt working... not sure why. 
require_once "/var/www/html/classes/Pdo_methods.php";

try {

    $DBIO = new DBInputOutput();
    $namesArray = $DBIO->getData('names');
    $namesString = "<p><strong>LAST NAME, FIRST NAME</strong></p>";

    sort($namesArray);

    //$namesString .= "<ul>";
    foreach ($namesArray as &$row) {
        $row = preg_replace("/\r|\n|\t/", '', $row);
        $namesString .= "<p>$row[0]</p>";
        //$namesString .= "<li>$row[0]</li>";
    }
    //$namesString .= "</ul>";

    //if the string didnt change, then we must say the database is empty
    
    //if ($namesString == "<p><strong>LAST NAME, FIRST NAME</strong></p><ul></ul>")
    if ($namesString == "<p><strong>LAST NAME, FIRST NAME</strong></p>")
        $namesString = "<p><strong>The names database is empty...</strong></p>";

    $response = (object)[
        'masterstatus' => 'success',
        'names' => $namesString
    ];


    echo json_encode($response);
} catch (PDOException $e) {

    $thisIsWhatHappened = $e->getMessage();

    $response = (object)[
        'masterstatus' => 'error',
        'msg' => "something went wrong: $thisIsWhatHappened"
    ];

    echo json_encode($response, JSON_FORCE_OBJECT);
} catch (Exception $e) {

    $thisIsWhatHappened = $e->getMessage();

    $response = (object)[
        'masterstatus' => 'error',
        'msg' => "something went wrong: $thisIsWhatHappened"
    ];

    echo json_encode($response, JSON_FORCE_OBJECT);
}

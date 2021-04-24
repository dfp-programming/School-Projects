<?php
   
//I tried a relative path here but it wasnt working... not sure why.   
require_once "/var/www/html/classes/Pdo_methods.php";

try{

$DBIO = new DBInputOutput();

$nameObject = json_decode($_POST['data']);
$fullname = $nameObject->name;
$fullname = explode(' ',$fullname);


//If $fullname became an array, reverse the order and add a comma. 
if(is_array($fullname)){
    $fullname = array_reverse($fullname, true);
    $fullname = implode(", ",$fullname);
}

$DBIO->insertData($fullname,'name','names');

$response = (object) [
    'masterstatus' => 'success',
    'msg' => '<p><strong>Name added to the names database!</strong></p>'
];
  
echo json_encode($response);

} catch (PDOException $e) {
    
    $thisIsWhatHappened = $e->getMessage();

    $response = (object)[
        'masterstatus'=>'error',
        'msg'=> "something went wrong: $thisIsWhatHappened"
        ];
        
        echo json_encode($response, JSON_FORCE_OBJECT);
  
}catch (Exception $e) {
    
    $thisIsWhatHappened = $e->getMessage();
    
    $response = (object)[
        'masterstatus'=>'error',
        'msg'=> "something went wrong: $thisIsWhatHappened"
        ];
        
        echo json_encode($response, JSON_FORCE_OBJECT);
  
}




?>
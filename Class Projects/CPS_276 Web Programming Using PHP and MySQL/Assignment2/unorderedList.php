<?php
function listFunction($mainItems=0,$nestedItems=0){
 
    //creating the unordered list by mean of two for loops
    echo "<div>";
        for ($i=0; $i < $mainItems; $i++) { 
        
            echo "<ul><li>".($i+1)."</li>";
            for ($j=0; $j < $nestedItems; $j++){
                echo "<ul><li>".($j+1)."</ul></li>";
            }
            echo "</ul>";
        }
    echo "</div>";

}



?>

<!DOCTYPE hmtl>
<hmtl>
    <title>List</title>
    <h3>Unordered List</h3>
    <body>
        <?php listFunction(4,5);?>
        <br>
    </body>
</hmtl>
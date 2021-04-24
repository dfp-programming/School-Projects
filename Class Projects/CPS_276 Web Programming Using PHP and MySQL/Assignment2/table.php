<?php

function createTable($rows =1, $cells =2, $border =1){

    echo "<div>";
        echo "<table border=\"$border\">";
        for ($i=0; $i <$rows ; $i++) { 
           
            echo "<tr>";
            for ($j=0; $j <$cells ; $j++) { 
                echo "<td>Row ".($i+1)." Cell ".($j+1)."</td>";
            }
            echo "</tr>";
        }
        echo "</table>";
        echo "</div>";
}

?>

<!DOCTYPE html>
<hmtl>
    <title>Nested List</title>
    <h3>Table Function</h3>
    <body>
        <?php echo createTable(15,5,1) ?>
    </body>
</hmtl>
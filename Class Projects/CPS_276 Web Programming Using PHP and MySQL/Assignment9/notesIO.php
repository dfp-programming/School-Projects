<?php

require_once "Pdo_methods.php";

class notesIO
{

    private $note = "";
    private $date;

    public function prepDate(&$rawDate)
    {
        $rawDate = str_replace('T', ' ', $rawDate);
    }

    public function addNote()
    {
        $toDB = new DBInputOutput();

        //taking the data from the form
        $note = $_POST["noteField"];
        $date = $_POST["noteDate"];

        //The string has a format which inclides a T.  the sql datatype DATETIME does not support this
        //I made a small function just so I could remove the T. 
        $this->prepDate($this->date);

        //creating an associative array to insert into the database
        $data = array("note_field" => $note, "user_date" => "$date");

        $msg = $toDB->insertData($data, "notes");

        if ($msg == "NO ERROR")
            return "<p><strong>NOTE HAS BEEN ADDED</strong></p>";
        else;
            return "<p><strong>$msg</strong></p>";
    }


    public function getNotes()
    {

        $output = "";
        $rawData = "";
        $fromDB = new DBInputOutput();
        $beginDate = $_POST["beginDate"];
        $endDate = $_POST["endDate"];
        $rawData = $fromDB->getData("notes");
        $tempArray = array();

        $tableHeader = <<<HTML
        </br><table class="table table-striped">
        <thead>
            <tr>
            <th scope="col" width="30%">Date and Time</th>
            <th scope="col">Note</th>
            </tr>
          </thead>
         <tbody>
        HTML;

        //If rawData is anything but an array, we assume it is an exception.  Terminate function. 
        if (!is_array($rawData))
            return $rawData;

        else {

            //only add selected dates
            foreach ($rawData as $row)
                if ($row["user_date"] >= $beginDate && $row["user_date"] <= $endDate) {

                    $newDate = strtotime($row["user_date"]);
                    $newDate = date("\T\h\\e jS \o\\f F, Y, \a\\t g:i A", $newDate );
                    $tempArray[] = "<tr><td>" . $newDate . "</td><td>" . $row["note_field"] . "</td></tr>";
                }

            //sort array, and turn into string
            rsort($tempArray, SORT_STRING | SORT_FLAG_CASE);
            $tempArray = implode(' ', $tempArray);

            $output = "$tableHeader" . "$tempArray" . "</tbody></table>";
        }

        return $output;
    }
}

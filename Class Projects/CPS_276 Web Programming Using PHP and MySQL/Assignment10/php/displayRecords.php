<?php

// WRITE YOUR CODE HERE

require_once "classes/Pdo_methods.php";

class records
{
    /*         In this table header, I wanted a hidden id column in the table.
    It will come in handy when is time to delete a record.  */

    private $tableHeader = <<<HTML
        <thead>
            <tr>
                <th scope="col" style='display:none'>id</th>
                <th scope="col">Name</th>
                <th scope="col">Address</th>
                <th scope="col">City</th>
                <th scope="col">State</th>
                <th scope="col">Phone</th>
                <th scope="col">Email</th>
                <th scope="col">DOB</th>
                <th scope="col">Contact</th>
                <th scope="col">Age</th>
                <th scope="col">Delete</th>
            </tr>
          </thead>
        HTML;

    private function prepDate(&$array)
    {
        //get rid of the - in the date, and reverse it so year is at the end. 
        $temp = $array["dob"];
        $temp = explode('-', $temp);
        $temp = array_reverse($temp);
        $array["dob"] = implode("/", $temp);
    }

    private function buildTableBody($dataArray)
    {

        $body = array('<tbody>');

        //sort array by name
        usort($dataArray, function ($row1, $row2) {
            return (strtolower($row1['name']) <=> strtolower($row2['name']));
        });


        //creating the table's body
        foreach ($dataArray as &$row) {

            //Adding a checkbox to each array row so it matches the header
            $this->prepDate($row);
            $row += ['delete' => "<input type='checkbox' value='{$row["id"]}' name='checked_row[]'>"];

            /*         creating the table contents for each row on the array
            Each loop appends one element to the tableContents[] array */
            $body[] = <<<HTML
                <tr>
                <td style='display:none'>{$row["id"]}</td>
                <td>{$row["name"]}</td>
                <td>{$row["address"]}</td>
                <td>{$row["city"]}</td>
                <td>{$row["state"]}</td>
                <td>{$row["phone"]}</td>
                <td>{$row["email"]}</td>
                <td>{$row["dob"]}</td>
                <td>{$row["contact"]}</td>
                <td>{$row["age_range"]}</td>
                <td align='center'>{$row["delete"]}</td>
                </tr>
                HTML;
        }

        //turning array into string and closing the table's body
        $body = implode(' ', $body);
        $body .= '<tbody>';

        return $body;
    }

    private function buildTable()
    {

        $completeTable = "";
        $fromDB = new DBInputOutput();
        $rawDataArray = $fromDB->getData('final');
        $deleteButton = "<button type='submit' name='delete_button' value='pressed' class='btn btn-danger'>Delete</button>";
        $tableContents = "";
        $message = "";

        if (is_string($rawDataArray))    //if it is a string, it means something went wrong when fetching the data
            $message = "<p><strong>Something went wrong: $rawDataArray</strong></p>";

        else if (empty($rawDataArray))  //If rawDataArray is empty, terminate the function. 
            $message = "<p><strong>This contact list is empty </strong></p>
                             <img src='no-data-for-you.jpg' alt='funny meme was supposed to show up here'>";

        else
            $tableContents = $this->buildTableBody($rawDataArray);

        $completeTable = <<<HTML
                <form method='POST' action='index.php?page=display'>
                <div>
                    $deleteButton
                </div>
                <br>
                <div>
                    <table class="table table-striped table-bordered">
                        $this->tableHeader
                        $tableContents 
                    </table>
                        $message
                </div>
            </form>
            HTML;

        return $completeTable;
    }

    public function updateRecords()
    { //check deletes records checked.
        $toDB = new DBInputOutput();
        $count = 0;
        $check = null;
        $table = null;

        if (!empty($_POST)) {

            if (isset($_POST['checked_row'])) { //Wrap the for each function to ensure at least one row was checked

                foreach ($_POST['checked_row'] as $row) {

                    $check = $toDB->deleteRow('final', 'id', "$row");

                    if ($check == "NO ERROR")
                        $count++;
                    else {
                        $table = $this->buildTable();
                        return array("Something went wrong: $check", $table);
                    }
                }
            }
        }

        $table = $this->buildTable();
        return array("<h5><strong>$count contact(s) were deleted </strong></h5>", $table);
    }

    public function getRecords()
    {
        $table = $this->buildTable();
        return array("<h5><strong>Contacts List</strong></h5>", $table);
    }




    // public function getRecords()
    // {
    //     $output = "";
    //     $fromDB = new DBInputOutput();
    //     $rawDataArray = $fromDB->getData('final');
    //     $deleteButton = "<button type='submit' name='delete' class='btn btn-danger'>Delete</button>";
    //     $tableContents = array('<tbody>');

    //     /*         In this table header, I wanted a hidden id column in the table.
    //     It will come in handy when is time to delete a record.  */
    //     $tableHeader = <<<HTML
    //     <thead>
    //         <tr>
    //             <th scope="col" style='display:none'>id</th>
    //             <th scope="col">Name</th>
    //             <th scope="col">Address</th>
    //             <th scope="col">City</th>
    //             <th scope="col">State</th>
    //             <th scope="col">Phone</th>
    //             <th scope="col">Email</th>
    //             <th scope="col">DOB</th>
    //             <th scope="col">Contact</th>
    //             <th scope="col">Age</th>
    //             <th scope="col">Delete</th>
    //         </tr>
    //       </thead>
    //     HTML;

    //     //If rawDataArray is empty, terminate the function. 
    //     if (empty($rawDataArray))
    //         return array("<p><strong>No records to display</strong></p>", implode($rawDataArray));

    //     else {

    //         //sort array by name
    //         usort($rawDataArray, function ($row1, $row2) {
    //             return (strtolower($row1['name']) <=> strtolower($row2['name']));
    //         });


    //         //creating the table's body
    //         foreach ($rawDataArray as &$row) {

    //             //Adding a checkbox to each array row so it matches the header
    //             $this->prepDate($row);
    //             $row += ['delete' => "<input type='checkbox' value='{$row["id"]}' name='{$row["id"]}'>"];

    //             /*         creating the table contents for each row on the array
    //             Each loop appends one element to the tableContents[] array */
    //             $tableContents[] = <<<HTML
    //                 <tr>
    //                 <td style='display:none'>{$row["id"]}</td>
    //                 <td>{$row["name"]}</td>
    //                 <td>{$row["address"]}</td>
    //                 <td>{$row["city"]}</td>
    //                 <td>{$row["state"]}</td>
    //                 <td>{$row["phone"]}</td>
    //                 <td>{$row["email"]}</td>
    //                 <td>{$row["dob"]}</td>
    //                 <td>{$row["contact"]}</td>
    //                 <td>{$row["age_range"]}</td>
    //                 <td align='center'>{$row["delete"]}</td>
    //                 </tr>
    //                 HTML;
    //         }


    //         //turning array into string and closing the table's body
    //         $tableContents = implode(' ', $tableContents);
    //         $tableContents .= '<tbody>';

    //         $output = <<<HTML
    //             <form method='POST' action='index.php?page=display'>
    //             <div>
    //                 $deleteButton
    //             </div>
    //             <div>
    //                 <table class="table table-striped table-bordered">
    //                     $tableHeader
    //                     $tableContents 
    //                 </table>
    //             </div>
    //         </form>
    //         HTML;
    //     }

    //     return array("<p><strong>Contacts</strong></p>", $output);
    // }
}

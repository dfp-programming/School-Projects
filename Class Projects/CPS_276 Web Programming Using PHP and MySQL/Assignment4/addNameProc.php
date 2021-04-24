<?php

class addNameProc
{

    private $nameList;

    private function sortNames()
    {
        $tempArray = explode("\n", $this->nameList);
        sort($tempArray, SORT_STRING | SORT_FLAG_CASE);

        //this for each loop removes un wanted newline characters that mess with the final string. 
        //I found a way to pass by value in order to iterate on each element
        //nice way to avoid for loops
        foreach ($tempArray as &$value) {
            $value = preg_replace("/\r|\n|\t/", '', $value);
        }

        //It is necessary to use the \n argument to so the function adds it in between each element
        if(is_array($tempArray))
            $this->nameList = implode("\n", $tempArray);
    }

    public function addClearNames()
    {
        //Grabbing the existing names from the text field, if any.
        $this->nameList = $_POST["nameListField"];

        //See which button was pressed 
        if ($_POST["button"] == "addNameButton") {

            $rawName = $_POST["inputNameField"];

            //remove unwanted characters just in case they got passed on. 
            $rawName = preg_replace("/\r|\n|\t/", '', $rawName);

            //Check if the input has spaces or not, the add the new name to the old list
            if (strpos($rawName, " ") > 0) {
                $rawName = explode(" ", $rawName);
                $this->nameList = $this->nameList . $rawName[1] . ", " . $rawName[0];
            } 
            
            else {
                $this->nameList = $this->nameList . $rawName;
            }
        } 
        
        else if ($_POST["button"] == "clearNameButton") {
            $this->nameList = null;
        }


        $this->sortNames();
        return $this->nameList;
    }
}

<?php

class Calculator{

    public function calc($operator=NULL,$a=NULL,$b=NULL){

        $myTag = "<br>";

        if ( !(is_string($operator)) || !(is_int($a)) || !(is_int($b))){ 
            
            return "You must enter a string and two numbers".$myTag;
        }
        else{
            switch ($operator){

                case "+" : return "$a + $b = ".($a+$b).$myTag;
                case "-" : return "$a - $b = ".($a-$b).$myTag;
                case "*" : return "$a * $b = ".($a*$b).$myTag;
                case "/" :
                    if($b==0)
                        return "Cannot divide by zero".$myTag;
                    else
                        return "$a / $b = ".($a/$b).$myTag;
                default :
                    return "Invalid operator"; break;
            }

        }
    }
}

?>
<?php
//YOU MUST WRITE THE CODE FOR THE OTHER REGULAR EXPRESSIONS TO BE USED

class Validation
{
	/* USED AS A FLAG CHANGES TO TRUE IF ONE OR MORE ERRORS IS FOUND */
	private $error = false;

	/* CHECK FORMAT IS BASCALLY A SWITCH STATEMENT THAT TAKES A VALUE AND THE NAME OF THE FUNCTION
	 THAT NEEDS TO BE CALLED FOR THE REGULAR EXPRESSION */
	public function checkFormat($value, $regex)
	{
		switch ($regex) {
			case "name":
				return $this->name($value);
				break;
			case "address":
				return $this->address($value);
				break;
			case "city":
				return $this->city($value);
				break;
			case "state":
				return $this->state($value);
				break;
			case "phone":
				return $this->phone($value);
				break;
			case "email":
				return $this->email($value);
				break;
			case "dob":
				return $this->dob($value);
				break;
			case "age_range":
				return $this->age_range($value);
				break;
		}
	}
	/* THE REST OF THE FUNCTIONS ARE THE INDIVIDUAL REGULAR EXPRESSION FUNCTIONS*/
	private function name($value)
	{
		//Blame foreign people for having special characters in the name hehehehe
		
		$match = preg_match('/^[^\s\!\@\#\$\%\^\&\*\(\)\+\=\*0-9][\p{L}\'\-\s]{1,50}$/i', $value);
		return $this->setError($match);
	}
	private function address($value)
	{
		//Only characters that could make up an address are allowed.  
		$match = preg_match('/^[1-9a-z-\'#\-_ @*~`\\,&]{1,200}$/i', $value);
		return $this->setError($match);
	}
	private function city($value)
	{
		$match = preg_match('/^[^\s\!\@\#\$\%\^\&\*\(\)\+\=\*0-9][\p{L}\'\-\s]{1,50}$/i', $value);
		return $this->setError($match);
	}
	private function state($value)
	{
		$match = preg_match('/^(MI|OR|CA|FL|WA)$/', $value);
		return $this->setError($match);
	}
	private function phone($value)
	{
		$match = preg_match('/^(\d{3}\.\d{3}.\d{4})$/', $value);
		return $this->setError($match);
	}
	private function email($value)
	{
		/* Regular expressions are not a good choice for checking email addresses.
		I decided to use the filter_var() function instead.  */
		$match = filter_var($value, FILTER_VALIDATE_EMAIL);
		if ($match == false)
			return $this->setError(false);
		else
			return $this->setError(true);
	}
	private function dob($value)
	{
		//Only people from from 01/01/1900 to 31/12/2020
		$match = preg_match('/^(0[1-9]|[12][0-9]|3[01])\/(0[1-9]|1[012])\/(19[0-9][0-9]|20([0-1][0-9]|20))$/', $value);
		return $this->setError($match);
	}
	private function age_range($value)
	{
		//match only one of these: "10-18" or "19-30" or "31-50" or "51  "
		$match = preg_match('/^(10-18|19-30|31-50|51\+  )$/', $value);
		return $this->setError($match);
	}
	private function setError($match)
	{
		if (!$match) {
			$this->error = true;
			return "error";
		} else {
			return "";
		}
	}
	/* THE SET MATCH FUNCTION ADDS THE KEY VALUE PAR OF THE STATUS TO THE ASSOCIATIVE ARRAY */
	public function checkErrors()
	{
		return $this->error;
	}
}

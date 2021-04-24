
<?php
/* WRITE THE NECESSARY PHP CODE HERE.  YOU WILL NEED TO RETURN AN ARRAY THAT CONTAINS TWO INDEXES. 
FIRST INDEX IS A PLACE FOR A MESSAGE (MAYBE BLANK OR NOT DEPENDING ON THE SITUATION)
 AND THE OTHER IS THE FORM OR THE TABLE DISPLAYING THE DATA (SEE $RESULT VARIABLE BELOW). */

$resut = " ";

if(isset($_GET)){
	if($_GET['page'] === "form"){
		//CODE GOES HERE TO REQUIRE THE FORM.PHP PAGE AND CALL WHATEVER METHOD YOU WROTE

		require_once "php/form.php";
		$temp = new myForm();
		$result = $temp->returnForm();

	}
	else if($_GET['page'] === "display"){
		//CODE GOES HERE TO REQUIRE THE DISPLAYRECORDS.PHP PAGE AND CALL WHATEVER METHOD YOU WROTE
		

	}
	else {
		//HEADER REDIRECT HERE
	}
}

else {
	//HEADER REDIRECT HERE
}
?>

<!DOCTYPE html>
<html lang="en">
	<head>
		<title>Final Project</title>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
		<style>
			.error {
				color: red;
				margin-left: 5px;
			}
			.space {
				margin-right: 30px;
			}
			nav ul li {
				list-style: none;
			}
			input[type=submit]{
				margin: 10px 0;
			}
			</style>
	</head>

	<body class="container">
		<nav>
			<ul>
				<li><a href="index.php?page=form">Add Contact Information</a></li>
				<li><a href="index.php?page=display">Display All Contacts Information</a></li>
			</ul>
		</nav>
		
		<?php
			echo $result[0]; 
			echo $result[1]; 
		?>
	</body>
</html> 






<!--  
<!doctype html>
<html lang="en">

<head>
	
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

	
	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" integrity="sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z" crossorigin="anonymous">

	<title> Form Project </title>
</head>

<body>
	<div class="container">
		<form method="get" action="#">
			<div class="form-group">
				<div class="form-row">
					<label for="inputName">Name</label>
					<input type="email" class="form-control" id="inputName">
				</div>
				<div class="form-row">
					<label for="inputStreet">Address (just number and street)</label>
					<input type="password" class="form-control" id="inputStreet">
				</div>
				<div class="form-row">
					<label for="inputCity">City</label>
					<input type="text" class="form-control" id="inputCity">
				</div>
				<div class="form-row">
					<label for="InputState">State</label>
					<input type="text" class="form-control" id="InputState">
				</div>
				<div class="form-row">
					<label for="inputPhone">Phone</label>
					<input type="text" class="form-control" id="inputPhone">
				</div>
				<div class="form-row">
					<label for="inputEmail">Email Address</label>
					<input type="text" class="form-control" id="inputEmail">
				</div>
				<div class="form-row">
					<label for="inputDOB">Date of birth</label>
					<input type="text" class="form-control" id="inputDOB">
				</div>
				</br>
				<label class="form-check-label" for="contactType"> Please check all contact types you would like (optional) </label>
				<div class="form-row" id="contactType">
					<div class="form-check form-check-inline">
						<input class="form-check-input" type="checkbox" id="newsletterCheck" value="newsletter">
						<label class="form-check-label" for="newsletterCheck">Newsletter</label>
					</div>
					<div class="form-check form-check-inline">
						<input class="form-check-input" type="checkbox" id="emailCheck" value="emailUpdates">
						<label class="form-check-label" for="emailCheck">Email Updates</label>
					</div>
					<div class="form-check form-check-inline">
						<input class="form-check-input" type="checkbox" id="textCheck" value="textUpdates">
						<label class="form-check-label" for="textCheck">Text Updates </label>
					</div>
				</div>
				</br>
				<label class="form-check-label" for="ageRange"> Please select an age range (you must select one) </label>
				<div class="form-row" id="ageRange">
					<div class="form-check form-check-inline">
						<input class="form-check-input" type="radio" id="1018Radio" value="1018">
						<label class="form-check-label" for="1018Radio">10-18</label>
					</div>
					<div class="form-check form-check-inline">
						<input class="form-check-input" type="radio" id="1930Radio" value="1930">
						<label class="form-check-label" for="1930Radio">19-30</label>
					</div>
					<div class="form-check form-check-inline">
						<input class="form-check-input" type="radio" id="3150Radio" value="3150">
						<label class="form-check-label" for="3150Radio">31-50</label>
					</div>
					<div class="form-check form-check-inline">
						<input class="form-check-input" type="radio" id="51Radio" value="51">
						<label class="form-check-label" for="51Radio">51+</label>
					</div>
				</div>
				</br>
				<div class="form-row">
					<button type="submit" class="btn btn-primary">Submit</button>
				</div>
		</form>
	</div>
</body>

</html>
-->
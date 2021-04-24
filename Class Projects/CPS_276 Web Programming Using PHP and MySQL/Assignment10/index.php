<?php
/* WRITE THE NECESSARY PHP CODE HERE.  YOU WILL NEED TO RETURN AN ARRAY THAT CONTAINS TWO INDEXES. 
FIRST INDEX IS A PLACE FOR A MESSAGE (MAYBE BLANK OR NOT DEPENDING ON THE SITUATION)
 AND THE OTHER IS THE FORM OR THE TABLE DISPLAYING THE DATA (SEE $RESULT VARIABLE BELOW). */


require_once "php/form.php";
require_once "php/displayRecords.php";

$result = array("", "");

if (isset($_GET)) {
	if ($_GET['page'] === "form") {

		//CODE GOES HERE TO REQUIRE THE FORM.PHP PAGE AND CALL WHATEVER METHOD YOU WROTE
		$form = new myForm();

		if (isset($_POST["submit"]))
			$result = $form->processForm($_POST);
		else
			$result = $form->returnBlankForm();

		} else if ($_GET['page'] === "display") {

		//CODE GOES HERE TO REQUIRE THE DISPLAYRECORDS.PHP PAGE AND CALL WHATEVER METHOD YOU WROTE
		$display = new Records();

		if (isset($_POST["delete_button"]))
			$result = $display->updateRecords($_POST);
		else
			$result = $display->getRecords();

	} else {
		//HEADER REDIRECT HERE
		header("location: http://161.35.1.12/index.php?page=form");
	}
} else {
	//HEADER REDIRECT HERE
	header("location: http://161.35.1.12/index.php?page=form");
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

		input[type=submit] {
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
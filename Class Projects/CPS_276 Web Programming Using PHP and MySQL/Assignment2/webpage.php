<?php

$myTitle = "Diego's Title";
$myHeading = "CPS 276 - Exercise 2";
$myName = "Diego F. Perez";
$myFooter = "CPS 276 ©2020";

function textInsertLoop($loopCount=0){

	$baseString = file_get_contents("sample_text.txt");
	$returnString = "";

	for ($i=0; $i < $loopCount ; $i++) { 
		$returnString .= "$baseString<br><br>";
	}

	return $returnString;
}



?>

<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title><?php echo $myTitle ?></title>
	<style>
		* {margin: 0; padding: 0;}
		body {font: 120%/1.5 sans-serif;}
		#wrapper {width: 1000px; margin: 0 auto; border: 1px solid black;}
		header {background: green; height: 150px; padding: 20px;}
		header h1 {color: white;}
		main {padding: 10px;}
		main h2 {margin: 15px 0;}
		main p {margin-bottom: 15px;}
		footer {background: #eee; padding: 10px 0; text-align: center}
		footer p {font-size: .8em;}
	</style>
</head>
<body>
	<div id="wrapper">
		<header>
			<h1><?php echo $myHeading ?></h1>
		</header>
		<main>
			<h2>My name is <?php echo $myName ?></h2>
			<p><?php echo textInsertLoop(3) ?></p>
			
		</main>
		<footer>
			<p><?php echo $myFooter ?></p>
		</footer>
	</div>
	
</body>
</html>
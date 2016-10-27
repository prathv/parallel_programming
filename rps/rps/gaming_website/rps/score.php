<!Doctype html>

<?php

require_once("conn.php");

if(isset($_GET['store'])&& isset($_GET['log'])){

$user = $_GET['log'];
$score1 = $_GET['store'];

echo $score1;
echo $user;

$sql = "UPDATE Scores SET score = '$score1' WHERE username = '$user'";

//echo $sql;
$ret = mysqli_query($conn,$sql);

}


$sql = "SELECT * FROM Scores ORDER BY score DESC LIMIT 5";

if($ret1 = mysqli_query($conn,$sql)){


}

?>


<html>

<head>
<title> Home </title>
<link rel = "stylesheet" href = "style.css"/>

</head>

<body>



<h1> SCORES PAGE </h1>
	<div id = "info">
	<h2> HIGH SCORES </h2>
<?php 
	 
	if(isset($ret1)){
		echo "<p> </p>";
	 while($row = $ret1->fetch_assoc()) {
	       		
			echo $row['username'].' '.'='.' '.$row['score']."<br/><br/>";      
			
		}


	}

	else
	{

		echo "";
	}

	
	if(isset($ret)){

		echo "<p> Your Score has been Saved</p>";

	}
	else
	{

		echo "<p> Log in To Save Your Score <p></p>";
	}
	

?>
	<a href = "game.php?log=<?php echo $user?>">Click here to Get back To the Game </a>
	</div>
</body>

</html>

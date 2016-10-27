<?php
require_once("sessions.php");
require_once("conn.php");

if(isset($_GET['log'])){

$user = $_GET['log'];

$sql = "SELECT a.username,a.firstName,a.lastName,a.email,b.wins,b.loses,b.score FROM Users a,Scores b WHERE a.username = b.username and a.username = '$user'";


if($ret = mysqli_query($conn,$sql)){




}

}


?>

<html>

<head>
<title> Account Information </title>
<link rel = "stylesheet" href = "style.css"/>
<h1> Account Information </h1>
</head>

<body>

<ul>
		<li><?php echo "<a id = 'active' href = index.php?log=".$_GET['log'].">" ?> Home</a></li>
		<li><?php echo "<a href = game.php?log=".$_GET['log'].">" ?> Game</a></li>		
		<li><?php echo "<a href = about.php?log=".$_GET['log'].">" ?> About</a></li>		
		<li><?php echo "<a href = register.php?log=".$_GET['log'].">" ?> Register</a></li>		
		<li><?php echo "<a href = login.php?log=".$_GET['log'].">" ?> Login</a></li>		
		<li><?php echo "<a href = account.php?log=".$_GET['log'].">" ?> Account Info</a></li>				


		<li><?php echo "<a href = logout.php?log=".$_GET['log'].">" ?> Logout</a></li>				



</ul>


<div id = "accinfo">


<?php	


if($ret->num_rows > 0){

 while($row = $ret->fetch_assoc()) {
       
	echo "<p>"."Name =".$row['firstName']."<br/><br/>"."Score =".$row['score']."<br/><br/>"."Email =".$row['email']."<br/><br/>"."Lastname =".$row['lastName']."<br/><br/>"."Wins =".$row['wins']."<br/><br/>"."Loses=".$row['loses']."<br/><br/>"."</p>";	

    }




}

else {


	echo "<p>LOG IN to view account information";
}

?>

</div>


</body>
</html>


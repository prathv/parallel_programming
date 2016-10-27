<?php 
require_once("sessions.php");
	require_once("conn.php");
?>
<html>

<header>
<title> Register </title> 
<link rel = "stylesheet" href = "style.css"/>


<body>
<h1 style = "text-align : center;">Register Page </h1>

<ul>
		<li><?php echo "<a href = index.php?log=".$_POST['fname'].">" ?> Home</a></li>
		<li><?php echo "<a href = game.html?log=".$_POST['fname'].">" ?> Game</a></li>		
		<li><?php echo "<a href = about.php?log=".$_POST['fname'].">" ?> About</a></li>		
		<li><?php echo "<a id = active href = register.php?log=".$_POST['fname'].">" ?> Register</a></li>		
		<li><?php echo "<a href = login.php?log=".$_POST['fname'].">" ?> Login</a></li>		




</ul>

<title> My Account </title>
<h1> My Account </h1>

</header>

<?php

if ( $_SERVER['REQUEST_METHOD'] == 'POST' ) {echo "<span style = 'color:white;'> Welcome  ".$_POST['fname']."</span>" ;}

echo "<hr/>";
?>




<div style="background-color : lightgrey">


<?php
if ( $_SERVER['REQUEST_METHOD'] == 'POST' ) {


$user = $_POST['user'];
$password = $_POST['pass'];
$fname = $_POST['fname'];
$lname = $_POST['lname'];
$email = $_POST['mail'];
$game = 'rps';
$winstart = 0;
$losestart = 0;
$scorestart = 100;
echo "Email: ".$_POST['mail'] ;

echo "<br><br>";

echo "Lastname: ".$_POST['lname'] ;

echo "<br><br>";

echo "Username: ".$_POST['user'] ;

echo "<br><br>";

if(isset($_POST['check'])){

	echo "Agree to terms : Yes";

}
else
{

	echo "Agree to terms : No";


}

$mysql = "SELECT username FROM Users";
if($ret = mysqli_query($conn,$mysql)){

if($ret->num_rows > 0){

 while($row = $ret->fetch_assoc()) {
       $userdb = $row['username'];
	if($userdb == $user){	
	echo "<script type = 'text/javascript'>alert('Username is in use, Please select another');</script>";

	echo "<script type = 'text/javascript'>window.location = 'http://web.engr.oregonstate.edu/~raip/cs290/db/register.php'</script>";
	}

    }

}
}
else {

echo "cannot gather data from db";
}

if( isset($user) && isset($password) && isset($fname) && isset($lname) && isset($email)){

	$sql = "INSERT INTO Users (username,password,firstname,lastname,email) VALUES ('$user','$password','$fname','$lname','$email')";
	$scoresql = "INSERT INTO Scores (username,game,score,wins,loses) VALUES ('$user','$game','$scorestart','$winstart','$losestart')";
	
	$ret = mysqli_query($conn,$sql);
	
	$ret1 = mysqli_query($conn,$scoresql);
	
	echo "return values of first and second sql statements are".$ret1.$ret;	
	if($ret1)
{
	echo "Inserted values into Database";

}
	else
{
 	echo "failed to insert values".mysql_error();
}
			
}
else{

	
	echo "<script type = 'text/javascript'>alert('Please fill in all fields');</script>";

	echo "<script type = 'text/javascript'>window.location = 'http://web.engr.oregonstate.edu/~raip/cs290/db/register.php'</script>";
	




}
	


}
?>

</div>
</body>
<footer id = "footer"> Prathveer's Rock-Paper-Scissors Copyright @copy 2016 </footer>
</html>


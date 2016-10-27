<?php
require_once("sessions.php"); 

ini_set('display_errors', 'On');

 require_once('conn.php');

 ?>
<html>

<header>
<title> Login </title> 
<link rel = "stylesheet" href = "style.css"/>


<body>
<h1 style = "text-align : center;">Login Page </h1>

<ul>
		<li><a<?php if(!isset($_POST['fname'])){echo " href = 'index.php'";} else { echo "href = 'index.php?log=".$_POST['fname'];} ?>> Home </a></li>
		<li><a<?php if(!isset($_POST['fname'])){echo " href = 'game.php'";} else { echo "href = 'game.php?log=".$_POST['fname'];} ?>> Game </a></li>
		<li><a<?php if(!isset($_POST['fname'])){echo " href = 'about.php'";} else { echo "href = 'about.php?log=".$_POST['fname'];} ?>> About </a></li>
		<li><a<?php if(!isset($_POST['fname'])){echo " href = 'register.php'";} else { echo "href = 'register.php?log=".$_POST['fname'];} ?>> Register </a></li>
		<li><a<?php if(!isset($_POST['fname'])){echo " href = 'login.php'";} else { echo "href = 'login.php?log=".$_POST['fname'];} ?>> Login </a></li>




</ul>

<title> My Account </title>
<h1> My Account </h1>

</header>



<div  style="background-color : darkgrey; text-align : center;">

<?php
if ( $_SERVER['REQUEST_METHOD'] == 'POST' ) {

$user = $_POST['user'];
$pass = $_POST['pass'];

	// Select username exists in db
	$sql = "SELECT username FROM Users WHERE username = '$user' and password = '$pass'";
	
if($ret = mysqli_query($conn,$sql)){
echo "Login Successful";
if($ret->num_rows > 0){

 echo "<script type='text/javascript'>window.location = 'http://web.engr.oregonstate.edu/~raip/cs290/db/index.php?log=$user'</script>";
}


else {
echo "<p> User does not exist or Invalid Login Details Added </p>";
}
}

}

echo "<hr/>";
?>

</div>
</body>
<footer id = "footer"> Prathveer's Rock-Paper-Scissors Copyright @copy 2016 </footer>
</html>


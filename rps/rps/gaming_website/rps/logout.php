<?php
require_once("sessions.php");?>
<html>

<head>
<title> Home </title>
<link rel = "stylesheet" href = "style.css"/>
 <script type="text/javascript">


 function logout(){
<?php
if(isset($_SESSION['name'])){
session_destroy();
}
?>
 window.location = "http://web.engr.oregonstate.edu/~raip/cs290/db/logout.php";
}

 </script>


<h1> Logout Page </h1>
</head>

<body>

<ul>
		<li><?php echo "<a id = 'active' href = index.php?log=".$_GET['log'].">" ?> Home</a></li>
		<li><?php echo "<a href = game.php?log=".$_GET['log'].">" ?> Game</a></li>		
		<li><?php echo "<a href = about.php?log=".$_GET['log'].">" ?> About</a></li>		
		<li><?php echo "<a href = register.php?log=".$_GET['log'].">" ?> Register</a></li>		
		<li><?php echo "<a href = login.php?log=".$_GET['log'].">" ?> Login</a></li>		
						

</ul>

<div id = "newlog">
<?php

if(isset($_GET['log'])&&$_GET['log']!='')
{
echo "<p> Do you want to logout "."<button onclick = 'logout()'>"."Yes"."</button></p>";

}
else{

echo "<h1> You are logged out, Please log in Again </h1>";
}
?>

<p id = "show"> </p>
</div>
</body>

</html>

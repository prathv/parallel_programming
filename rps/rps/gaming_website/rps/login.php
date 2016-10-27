<?php
require_once("sessions.php");
?>
<html>

<header>
<title> Login </title> 
<link rel = "stylesheet" href = "style.css"/>
<script type="text/javascript" src="javascript1.js"></script>
</header>

<body>
<h1 style = "text-align : center;">Login Page </h1>



<?php if(isset($_GET['log'])){
	echo "<h2 style = 'color : white;'> Welcome ".$_GET['log']."</h2>";
	}
	?>




<ul>
		<li><?php echo "<a  href = index.php?log=".$_GET['log'].">" ?> Home</a></li>
		<li><?php echo "<a href = game.php?log=".$_GET['log'].">" ?> Game</a></li>		
		<li><?php echo "<a href = about.php?log=".$_GET['log'].">" ?> About</a></li>		
		<li><?php echo "<a href = register.php?log=".$_GET['log'].">" ?> Register</a></li>		
		<li><?php echo "<a id = 'active' href = login.php?log=".$_GET['log'].">" ?> Login</a></li>		
		<li><?php echo "<a href = account.php?log=".$_GET['log'].">" ?> Account Info</a></li>				


		<li><?php echo "<a href = logout.php?log=".$_GET['log'].">" ?> Logout</a></li>							



</ul>



<div class ="form">
<form name="myform" action="loginProcess.php" onsubmit=" validateForm();" method="post">


<h4> Username: </h4><input type="text" name="user"/>
<h4> Password: </h4><input type= "password" name = "pass"/>
<br>

<input type="submit" value="Login">
</form>
</div>
<footer id = "footer"> Prathveer's Rock-Paper-Scissors Copyright @copy 2016 </footer>

</body>
</html>

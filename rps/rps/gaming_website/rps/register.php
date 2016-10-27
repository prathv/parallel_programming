<!Doctype html>
<?php require_once("conn.php");?>
<html>

<header>
<title> Register </title> 
<link rel = "stylesheet" href = "style.css"/>
<script type="text/javascript" language="javascript"src="javascript.js">
</script>
</header>

<body>
<h1 style = "text-align : center;">Register Page </h1>






<?php if(isset($_GET['log'])){
	echo "<h2 style = 'color : white;'> Welcome ".$_GET['log']."</h2>";
	}
	?>




<ul>
		<li><?php echo "<a href = index.php?log=".$_GET['log'].">" ?> Home</a></li>
		<li><?php echo "<a href = game.php?log=".$_GET['log'].">" ?> Game</a></li>		
		<li><?php echo "<a href = about.php?log=".$_GET['log'].">" ?> About</a></li>		
		<li><?php echo "<a id = 'active' href = register.php?log=".$_GET['log'].">" ?> Register</a></li>		
		<li><?php echo "<a href = login.php?log=".$_GET['log'].">" ?> Login</a></li>		
		<li><?php echo "<a href = account.php?log=".$_GET['log'].">" ?> Account Info</a></li>				


		<li><?php echo "<a href = logout.php?log=".$_GET['log'].">" ?> Logout</a></li>					



</ul>






<div class = "form">
<form name="Myform" action="accountProcess.php" method = "post"  onsubmit="validate();" >

<h4>FirstName: </h4><input type="text" name="fname" />
<h4> LastName: </h4><input type="text" name="lname"/>
<h4> Username: </h4><input type="text" name="user"/>
<h4> Email: </h4><input type= "email" name = "mail"/>
<h4> Password: </h4><input type = "password" name = "pass"/>
<h4> Password Confirm : </h4> <input type = "password" name = "pass2"/>

Do you agree to the terms<input type = "checkbox" name = "check" value = "No" />
<br><br>


<input type="submit" value="Register">
</form>
</div>
<footer id = "footer"> Prathveer's Rock-Paper-Scissors Copyright @copy 2016 </footer>

</body>
</html>

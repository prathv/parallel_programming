<?php 
require_once("sessions.php");
?>


<html>

<head>
<title> AboutMe </title>
<link rel = "stylesheet" href = "style.css"/>

</head>


<body>

<h1> About The Game </h1>


<?php if(isset($_GET['log'])){
	echo "<h2 style = 'color : white;'> Welcome ".$_GET['log']."</h2>";
	}
	?>



<ul>
		<li><?php echo "<a  href = index.php?log=".$_GET['log'].">" ?> Home</a></li>
		<li><?php echo "<a href = game.php?log=".$_GET['log'].">" ?> Game</a></li>		
		<li><?php echo "<a id = 'active' href = about.php?log=".$_GET['log'].">" ?> About</a></li>		
		<li><?php echo "<a href = register.php?log=".$_GET['log'].">" ?> Register</a></li>		
		<li><?php echo "<a href = login.php?log=".$_GET['log'].">" ?> Login</a></li>		
		<li><?php echo "<a href = account.php?log=".$_GET['log'].">" ?> Account Info</a></li>				


		<li><?php echo "<a href = logout.php?log=".$_GET['log'].">" ?> Logout</a></li>							



</ul>


	


<div class = "container">
	
<p>Welcome to the online version of Rock-Paper-Scissors. Here the rules of the game will be established</p>

<p id = "content"> To start off, Each player (user and computer) are initially assigned 30 points each. If either of the player's points reduces to 0, the corresponding player loses the game.<br/>
The game works as follows.<br/><br/> The user is given 3 choices to choose from. These choices are - Rock, Paper and Scissors. The win situation is descirbed below.<br/> <br/>  Rock wins against Scissor.<br/> Scissor wins against Paper.<br/> And Paper wins against Rock.<br/><br/> A loss results in a deduction of 10 points. Hence, if a player reaches 0 points, he/she loses the game session and have to start again</p> 
<a href='details.php' style="color : black; font-weight : bold;">Click here to know about implementation of the game</a>
</div>
<footer id = "footer"> Prathveer's Rock-Paper-Scissors Copyright @copy 2016 </footer>

</body>
</html>

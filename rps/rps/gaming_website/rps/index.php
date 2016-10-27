<?php 
require_once("sessions.php");
if(isset($_GET['log'])){

	if(!isset($_SESSION['name'])){
	$_SESSION['name'] = $_GET['log'];
	}
	else{
	
	$_SESSION['name'] = $_GET['log'];
	
	
	}
}
else 
{

}

?>
<html>



<head>
<title> Home </title>
<link rel = "stylesheet" href = "style.css"/>

</head>


<body>

<h1> Rock-Paper-Scissors Online </h1>
<?php if(isset($_GET['log'])){
	echo "<h2 style = 'color : white;'> Welcome ".$_GET['log']."</h2>";
	}
	?>


<ul>
		<li><?php echo "<a id = 'active' href = index.php?log=".$_GET['log'].">" ?> Home</a></li>
		<li><?php echo "<a href = game.php?log=".$_GET['log'].">" ?> Game</a></li>		
		<li><?php echo "<a href = about.php?log=".$_GET['log'].">" ?> About</a></li>		
		<li><?php echo "<a href = register.php?log=".$_GET['log'].">" ?> Register</a></li>		
		<li><?php echo "<a href = login.php?log=".$_GET['log'].">" ?> Login</a></li>		
		<li><?php echo "<a href = account.php?log=".$_GET['log'].">" ?> Account Info</a></li>				


		<li><?php echo "<a href = logout.php?log=".$_GET['log'].">" ?> Logout</a></li>				



</ul>

<div class = "container">

	
<p>Welcome to the online version of Rock-Paper-Scissors. To know about the rules of the game click on the About page on the navigation bar. To play, first please login in, then please click on the Game page on the navigation bar. </p>

<p> Rock-paper-scissors is a zero-sum hand game usually played between two people, in which each player simultaneously forms one of three shapes with an outstretched hand. These shapes are "rock" (a simple fist), "paper" (a flat hand), and "scissors" (a fist with the index and middle fingers together forming a V). The game has only three possible outcomes other than a tie: a player who decides to play rock will beat another player who has chosen scissors ("rock crushes scissors") but will lose to one who has played paper ("paper covers rock"); a play of paper will lose to a play of scissors ("scissors cut paper"). If both players choose the same shape, the game is tied and is usually immediately replayed to break the tie.</p>
</div>
<footer id = "footer"> Prathveer's Rock-Paper-Scissors Copyright @copy 2016 </footer>
</body>
</html>

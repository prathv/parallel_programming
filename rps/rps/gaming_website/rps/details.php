
<html>



<head>
<title> Details</title>
<link rel = "stylesheet" href = "style.css"/>

</head>


<body>


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
	
<p>Welcome to the online version of Rock-Paper-Scissors. Here the implementation of the game will be established</p>

<p id = "content1"> 

The game uses implementations of PHP, Javascript, HTML, CSS and AJAX. PHP is used to process the database requests to store and retrieve game information, to and from the database. It store user login credentials and User Score details. It also handles session management of the application.<br/><br/> Javascript is used to process the logic of the game. Hence, based on the users interactions in the game certain events and values are processed and this is done by Javascript. Therefore, to determine who wins the round, how many points are gained after a user wins and such scenarios are processed by Javascript.<br/><br/>HTML and CSS maintain the layout of the page. Cascading Style Sheet or CSS, allows users to customize the layout of the content that resides in the page. While html contains the content in the page. Using CSS images, layouts and other design aspects of the page can be accessed.<br/><br/>Finally, Ajax is used to asynchronously add in user score to the database.
</p>
</div>
<footer id = "footer"> Prathveer's Rock-Paper-Scissors Copyright @copy 2016 </footer>


</body>




</html>

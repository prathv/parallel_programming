<?php 
require("sessions.php");
require_once("conn.php");
if(isset($_GET['log'])){


$user = $_GET['log'];

$_SESSION['name']=$user;
$sql = "SELECT score FROM Scores WHERE username = '$user'";


if($ret = mysqli_query($conn,$sql)){

if($ret->num_rows > 0){

 while($row = $ret->fetch_assoc()) {
       $score = $row['score'];
	

    }




}
}
}
?>
<html>

<head>
	<title> Game </title>
	<link rel = "stylesheet" href = "gamestyle.css"/>
	   <SCRIPT type="text/javascript" language="javascript" src="game1.js"> </SCRIPT>


<h1 style = "text-align : center ;"> HAVE FUN!!</h1>
	

	<noscript> There is no script being implemented </noscript>
	</head>

<body>

<div id = "scoreform">


Click Here, To Save your Score 

<input type ='button' id ='store' name ='store' onclick='updateDb()' value =<?php if(isset($_SESSION['name'])){echo $score; }?> >

<input type = "hidden" id ="name" value =<?php echo $user;?>>

</div>

<div class ="score">

<h2> User Score </h2>
<p id = "score" style = "text-align : center; font-weight : bold; font-size : 20px;"> <?php if(!isset($score)){echo 'Please Log in To post score';} else   echo $score; ?></p>


 
</div>

<div class = "container">

<h2 style = "text-align : center"> Please Pick One Option </h2>
	
	<div class = "rock">
		<button name ="rock" id = "rock"><img src = "rock.jpg" alt = "" /></button>
		<h2>Rock</h2>
	</div>
	
	<div class = "paper">
		<button name = "paper" id = "paper"><img src = "paper.jpg" alt = "" /></button>
		<h2>Paper</h2>
	</div>
	
	<div class = "scissor">
		<button  name = "scissor" id = "scissor"><img src = "scissor.jpg" alt = "" /></button>
		<h2>Scissor</h2>
	</div>
	

</div>

<div class = "container2">

<img id = "resultimg" src = "" alt = ""> </img>
<p id = "result"> User's Choice</p>
<span style = "font-weight :bold ; font-size : 40px;" > User Points Left</span> <p id = "user" style = "font-weight :bold ; font-size : 40px;">30</p>
<span style = "font-weight :bold ; font-size : 20px;">User Wins : </span> <p id ="userwins" style = "font-weight :bold ; font-size : 20px;"> 0 </p> 

</div>

<div class = "container3">
<img id = "resultimgcomp" src = "" alt = ""/>
<div id ="compsub">
<p id = "resultcomp">Computer's Choice  </p>
<span style = "font-weight :bold ; font-size : 40px;"> EvilComp	 Points Left </span> <p id = "comp" style = "font-weight :bold ; font-size : 40px;">30</p>
<span style = "font-weight :bold ; font-size : 20px;"> EvilComp Wins :  <p id ="compwins" style = "font-weight :bold ; font-size : 20px;"> 0 </p> 
</div>
</div>

<div class = "container4">
<p id = "resultgame" style = "font-weight : bold; font-size : 50px;"> </p>
</div>

<button id = "button"><a href = "index.php"> Go Back to Home </a></button>

<footer id = "footer"> Prathveer's Rock-Paper-Scissors Copyright @copy 2016 </footer>

</body>
</html>

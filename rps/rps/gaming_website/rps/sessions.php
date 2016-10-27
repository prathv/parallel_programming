<?php
ini_set("session.save_path",getcwd()."/gamesess");
session_start();
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

//echo " Get info not acquired ";

}


?>

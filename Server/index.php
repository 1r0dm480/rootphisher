<?php

session_start();

$sess = $_SESSION['username'];

if(isset($sess)) {

   header("Location: panel.php");

} else {

   header("Location: login.php");

}


?> 

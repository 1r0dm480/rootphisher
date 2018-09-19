<?php

session_start();

include('db.inc.php');

$sess = @($_SESSION['username']);

if(isset($sess)) {

   header("Location: index.php");

} else {

echo '<html><head><title>Login</title></head><body bgcolor="black"><center><h1 style="color: red;">RootPhisher</h1><h1 style="color: lime;">Login</h1><form action="#" method="POST"><input style="color: lime; background: black;" type="text" placeholder="Username" name="user"><br><br><input style="color: lime; background: black;" type="password" placeholder="Password" name="pass"><br><br><input style="color: lime; background: black;" type="submit" value="Login" name="login"></center></body></html>';

   $login = @($_POST['login']);
   if(isset($login)) {

      $user = $_POST['user'];
      $pass = $_POST['pass'];
      
      $q = "SELECT * FROM users WHERE username='$user'";
      $res = mysqli_query($link, $q);
      $row = mysqli_fetch_array($res, MYSQLI_ASSOC);
      $count = mysqli_num_rows($res);
      if($count == 1 && $row['password'] == $pass) {
 
         $_SESSION['username'] = $row['username'];
         header("Location: index.php");
 
      } else {
 
         echo '<text style="color: lime;">Incorrect Username or Password.</text>';
 
      }

 }

} 

?> 

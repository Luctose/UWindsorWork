<?php
    $myhost = 'localhost';
    $myuser = 'sarwehl';
    $mypassword = 'sushi';
    $mydb = 'sarwehl_sushi';

    $conn = new mysqli($myhost, $myuser, $mypassword, $mydb);
    // Check connection
    if($conn->connect_error){
        die("Connection failed: ".$conn->connect_error);
    }
?>
<?php
    echo $fname;
    $fname = $_GET["firstname"];
    $lname = $_GET["lastname"];
    $email = $_GET["email"];
    $password = $_GET["password"];

    $myhost = 'localhost';
    $myuser = 'da_sso_RvbBd2Y9o';
    $mypassword = 'sushi';
    $mydb = 'sarwehl_sushi';
    $link = mysql_connect($myhost, $myuser, $mypassword);

    if(!$link){
        echo 'Could not connect to mysql';
        exit;
    }
    if(!mysql_select_db($my_db, $link)) {
        echo 'Could not select database';
        exit;
    }
    
    $sql_insert = "INSERT INTO 'user_profile' ('firstname', 'lastname', 'email', 'password', 'date_created')
    VALUES (".$fname.",".$lname.", ".$email.", ".$password.", DEFAULT)";
    if ($link->query($sql_insert) === TRUE) {
    echo "New record created successfully";
    } else {
    echo "Error: ".$sql_insert."<br>".$link->error;}
    // commit the transaction
    echo "done";
    $link->commit();
    $conn->close();
?>
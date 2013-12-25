<?

    // require common code
    require_once("includes/common.php"); 

    // escape username to avoid SQL injection attacks
    $username = mysql_real_escape_string($_POST["username"]);

    // prepare SQL
    $sql = "SELECT * FROM users WHERE username='$username'";
    
    // execute query
    $result = mysql_query($sql);
    
    if (mysql_num_rows($result) == 1)
    {
    	apologize("USERENAME already exists!");
    }
    
    if (empty($_POST["username"]) || empty($_POST["password"]) || empty($_POST["password2"]))
    {
	apologize("You must fill out the form!");
    }
    
    if ($_POST["password"] != $_POST["password2"])
    {
    	apologize("Password doesn't match!");
    }
    
    // else report error
    $hash = crypt($_POST["password"], $row["hash"]);
    // prepare query
    $sql = "INSERT INTO users (username, hash, cash)
    VALUES('$username', '$hash', 10000.00)";
    mysql_query($sql);
    // remember that user's now logged in by caching user's ID in session
    $_SESSION["id"] = $row["id"];
	redirect("index.php");
 

?>


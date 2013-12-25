<?

    // require common code
   require_once("includes/common.php");
   
   $id = $_SESSION['id'];
   $sql = "SELECT * FROM users WHERE id='$id'";
   $result = mysql_query($sql);
   $row = mysql_fetch_array($result);
   $user = $row["username"];
   
   $hsql = "SELECT * FROM history WHERE ids='$id'";
   $hresult = mysql_query($hsql);
   
   
?>

<!DOCTYPE html>

<html>

  <head>
    <link href="css/styles.css" rel="stylesheet" type="text/css">
    <title>C$50 Finance: Home</title>
  </head>

  <body>

    <div id="pic">
      <a href="index.php"><img alt="C$50 Finance" height="110" src="images/logo.gif" width="544"></a>
    </div>
    
    
    
    <div id="logout">  
    	Hi <? echo strtoupper($user) . "  "; ?> 	
      <a href="logout.php">log out</a>      
    </div>
    
    
    <div id="hist">
  	<table id="table3"; border="1">
  		<tr>
  			<th bgcolor="#fa8072"; width='200'; height='25'>TRANSACTION</th>
			<th bgcolor="#fa8072"; width='200'; height='25'>SYMBOL</th>
			<th bgcolor="#fa8072"; width='200'; height='25'>NO. OF SHARES</th>
			<th bgcolor="#fa8072"; width='200'; height='25'>PRICE</th>
			<th bgcolor="#fa8072"; width='200'; height='25'>TIME & DATE</th>
		</tr>
		<? $hsql = "SELECT * FROM history WHERE ids='$id'";
		   $hresult = mysql_query($hsql);
		   $q = mysql_num_rows($hresult);
	   	   for($i = 1; $i <= $q; $i++)
	   	   {
	   	   	$hrow = mysql_fetch_array($hresult);
	   	?>
	   	 
	   	 	<tr <? if(strcmp($hrow["transaction"],'BUY') == 0) { ?> bgcolor="#27408B"; style="color:white" <?} else {?> bgcolor="#B0171F"; style="color:yellow" <? } ?>>
		   	 	<td><? echo strtoupper ($hrow["transaction"]); ?></td>
				<td><? echo strtoupper ($hrow["symbol"]); ?></td>
				<td><? echo $hrow["shares"]; ?></td>
				<td><? echo strtoupper ($hrow["price"]); ?></td>
				<td><? echo strtoupper ($hrow["time"]); ?></td>
			</tr>
  		   <? } ?>
    		
    	</table> 
   </div>
   
   <div id='port'>
    	<a href="index.php">BACK to Portfolio</a>
    </div> 
   
   
   </body>
</html>

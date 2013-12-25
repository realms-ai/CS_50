<?

    // require common code
   require_once("includes/common.php");
   
   $id = $_SESSION['id'];
   $sql = "SELECT * FROM users WHERE id='$id'";
   $result = mysql_query($sql);
   $row = mysql_fetch_array($result);
   $user = $row["username"];
   $cash = $row["cash"];    
   
   $hsql = "SELECT * FROM history WHERE ids='$id'";
   $hresult = mysql_query($hsql);
   /*GETTING QUOTES */
   if (isset($_POST["quotess"]))
   {      
      if(empty($_POST["symbol"]) || (lookup($_POST["symbol"]) == null))
   	{
    		$error = false;
   	}
      else
   	{
	   	$s = lookup($_POST["symbol"]);
	    	$error = true;
	
   	}   	
   }
       
   /*BUY A SHARE */
   if (isset($_POST["buy"]))
   	{   	   
   	   
   	   $s = lookup($_POST["symbol"]);
   	   $sym = $_POST["symbol"];   	   
	   $sql1 = "SELECT * FROM trading WHERE ids = '$id' AND symbol = '$sym'";
	   $result1 = mysql_query($sql1);
	   $row1 = mysql_fetch_array($result1);	      
	   $a = ($_POST["shares"] * ($s -> price)); 
	   $price = $s -> price;  	   ;
	   $ss = $_POST["shares"];	   	   
	   if( empty($_POST["shares"]) || empty($_POST["symbol"]) || $_POST["shares"] <= 0 )  
	   { 
	   	$err = true;
	   	
	   }
	   else if($a > $cash)
	   {
	   	$err1 = true;
	   	
	   }
	   else
	   {
	   	if(mysql_num_rows($result1) == 1)
	   	
	   	{	  		
	   		$sss = $row1["shares"] + $ss;
		   	$sql1 = "UPDATE trading SET shares = '$sss' where symbol = '$sym' and ids = '$id'";		   	
		}
		else	   	
			$sql1 = "INSERT INTO trading (ids, symbol, shares)
	   		VALUES('$id', '$sym', '$ss')";	   	 
	   	mysql_query($sql1);
	   	$hsql = "INSERT INTO history (ids, transaction, symbol, shares, price)
	   		VALUES('$id', 'BUY', '$sym', '$ss', '$price')";
	   	mysql_query($hsql);  	   	
	   	$cash = $cash - $a;
	   	$sql = "UPDATE users SET cash = '$cash' where username = '$user'";	
	   	mysql_query($sql);   	
	   	$err = false;
	   	$err1 = false;	        
	   }
	   unset($_POST["buy"]);
	}
   	
   /*SELL A SHARE */
   if (isset($_POST["sell"]))
   	{   	   
   	   $s = lookup($_POST["symbol"]);
   	   $sym = $_POST["symbol"];   	   
	   $sql1 = "SELECT * FROM trading WHERE ids = '$id' AND symbol = '$sym'";
	   $result1 = mysql_query($sql1);
	   $row1 = mysql_fetch_array($result1);	      
	   $a = ($_POST["shares"] * ($s -> price)); 
	   $price = $s -> price;	   	   
	   $ss = $_POST["shares"];	
 	   if(empty($_POST["shares"]) || empty($_POST["symbol"]) || $_POST["shares"] <= 0 || mysql_num_rows($result1) != 1 )   
	   	$serr = true;	
 	   else if($ss > $row1["shares"])
	   	$serr1 = true;
	   else
	   {
	   	$sss = $row1["shares"] - $ss;
	   	if($sss == 0)	   	
	   	{	  		
	   		$sql1 = "DELETE FROM trading where symbol = '$sym' and ids = '$id'";		   	
		}
		else	   	
			$sql1 = "UPDATE trading SET shares = '$sss' where symbol = '$sym' and ids = '$id'";
	   	mysql_query($sql1);
	   	$hsql = "INSERT INTO history (ids, transaction, symbol, shares, price)
	   		VALUES('$id', 'SELL', '$sym', '$ss', '$price')";
	   	mysql_query($hsql); 
	   	$cash = $cash + $a;
	   	$sql = "UPDATE users SET cash = '$cash' where username = '$user'";
	   	mysql_query($sql);
	   	$serr = false;
	   	$serr1 = false;		        
	   }	
	   unset($_POST["sell"]);	  
   	}
   	  	
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
    
     <div id="portpic">
      <img height="110" src="images/images.jpg" width="544">
    </div>
    

    <div id="logout">  
    	Hi <? echo strtoupper($user) . "  "; ?> 	
      <a href="logout.php">log out</a>      
    </div>
    
    
    <div id='history'>
    	<a href="history.php">View Last Transactions</a>
    </div> 
    
    
    <div id="quote">
     <form action="index.php" method="post">
        <table>
          <tr>
            <td>SYMBOL:</td>
            <td><input name="symbol" type="text" dir="ltr" ></td>
            <td colspan="2"><input name='quotess' type="submit" value="Get Quotes"></td>
          </tr>	
      	  </table>
      </form>    
	  <? if ($error): ?>
	    <div id="display">
	    	   	
	       	<table id="table1">
	    		<tbody>
	    			<tr>
	    				<th > NAME:  </th>
	    				<td style = "color:Red;text-align:center;"> <? echo $s -> name; ?> </td>
	    			</tr>
	    			<tr>
	    				<th> SYMBOL:  </th>
	    				<td > <? echo $s -> symbol; ?> </td>
	    			</tr>
	    			<tr>
	    				<th> PRICE:  </th>
	    				<td > <? echo $s -> price; ?> </td>
	    			</tr>
	    		</tbody>    	    	
	    	</table>    		
	    </div>	    
	   <? endif ?> 
   </div>
   
   
   <div id="buys">
   	<form action="index.php" method="post">
        <table id='table2'>
          <tr>
            <td>SYMBOL:</td>
            <td><input name="symbol" type="text" ></td>
          </tr>
          <tr>
            <td>No. of Shares:</td>
            <td><input name="shares" type="text" ></td>
          </tr>
          <tr>
            <td colspan="2"><input name='buy' type="submit" value="BUY"></td>
          </tr>	
      </table>	  
      </form>  
   </div>
   
   <div id="cass">  
    	<? echo "CASH IN HAND: $" . $cash; ?> 	
   </div>
   
   <? if (($err) || ($err1)):?>
   <div id='berr'>
   	<? if ($err): ?>
   		INVALID ENTRY
   	<? endif ?>
   	<? if ($err1): ?>
   		INSUFFICIENT MONEY
   	<? endif ?>
   </div>
   <? endif ?>
   
   
    <div id="sells">
   	<form action="index.php" method="post">
        <table id='table4'>
          <tr>
            <td>SYMBOL:</td>
            <td><input name="symbol" type="text" ></td>
          </tr>
          <tr>
            <td>No. of Shares:</td>
            <td><input name="shares" type="text" ></td>
          </tr>
          <tr>
            <td colspan="2"><input name='sell' type="submit" value="SELL"></td>
          </tr>	
      </table>	  
      </form>  
   </div>
   
   
   <?if (($serr) || ($serr1)):?>
   <div id='serr'>
   	<? if ($serr): ?>
   		INVALID ENTRY
   	<? endif ?>
   	<? if ($serr1): ?>
   		INSUFFICIENT SHARES
   	<? endif ?>	
   </div>
   <? endif ?>
   
  <div id="portfolio">
  	<table id="table3"; border="1">
  		<tr>
			<th bgcolor="#fa8072"; width='250'; height='25'>SYMBOL</th>
			<th bgcolor="#228b22"; width='250'; height='25'>NO. OF SHARES</th>
		</tr>
		<? $sql11 = "SELECT * FROM trading WHERE ids = '$id'";
	   	   $result11 = mysql_query($sql11);
	   	   $q = mysql_num_rows($result11);
	   	   for($i = 1; $i <= $q; $i++)
	   	   {
	   	   	$row11 = mysql_fetch_array($result11);
	   	?>
	   	 
	   	 	<tr <? if($i % 2 == 0) { ?> bgcolor="#CC33FF" <?} else {?> bgcolor="#33FFCC" <? } ?>>
				<td><? echo strtoupper ($row11["symbol"]); ?></td>
				<td><? echo $row11["shares"]; ?></td>
			</tr>
  		   <? } ?>
    		
    	</table> 
   </div>
   
   <div id="cass">  
    	<? echo "CASH IN HAND: $" . $cash; ?> 	
   </div>
   
   
  </body>

</html>

<?php
	// Connects to the Database 
	include('connect.php');
	$DB = connect();
	
	//if the login form is submitted 
	if (isset($_POST['submit'])) {
		
		$_POST['username'] = trim($_POST['username']);
		if(!$_POST['username'] | !$_POST['password']) {
			die('<p>You did not fill in a required field.
			Please go back and try again!</p>');
		}
		
		$password = $_POST['password'];
		
		$check = mysqli_query($DB, "SELECT * FROM users WHERE username = '".$_POST['username']."'")or die(mysqli_error($DB));
		
 		//Gives error if user already exist
 		$check2 = mysqli_num_rows($check);
		if ($check2 == 0) {
			die("<p>Sorry, user name does not exisits.</p>");
		}
		else
		{
			while($info = mysqli_fetch_array($check )) 	{
			 	//gives error if the password is wrong
				if ($password != $info['pass']) {
					die('Incorrect password, please try again.');
				}
			}
			$hour = time() + 3600; 
			setcookie('hackme', $_POST['username'], $hour); 
			setcookie('hackme_pass', $password, $hour);
			header("Location: members.php");
		}
	}
		?>  
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>hackme</title>
<link href="style.css" rel="stylesheet" type="text/css" media="screen" />
<?php
	include('header.php');
?>
<div class="post">
	<div class="post-bgtop">
		<div class="post-bgbtm">
        <h2 class = "title">hackme bulletin board</h2>
        	<?php
            if(!isset($_COOKIE['hackme'])){
				 die('Why are you not logged in?!');
			}else
			{
				print("<p>Logged in as <a>$_COOKIE[hackme]</a></p>");
			}
			?>
        </div>
    </div>
</div>

<?php
	$threads = mysqli_query($DB, "SELECT * FROM threads ORDER BY date DESC")or die(mysqli_error($DB));
	while($thisthread = mysqli_fetch_array( $threads )){
?>
	<div class="post">
	<div class="post-bgtop">
	<div class="post-bgbtm">
		<h2 class="title"><a href="show.php?pid=<?php echo $thisthread['id'] ?>"><?php echo $thisthread['title']?></a></h2>
							<p class="meta"><span class="date"> <?php echo date('l, d F, Y',$thisthread['date']) ?> - Posted by <a href="#"><?php echo $thisthread['username'] ?> </a></p>

	</div>
	</div>
	</div> 

<?php
}
	include('footer.php');
?>
</body>
</html>

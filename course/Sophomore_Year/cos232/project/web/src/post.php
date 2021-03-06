<?php
// Connects to the Database 
	include('connect.php');
	$DB = connect();
	session_start();

	function escape($string){
		return htmlspecialchars($string, ENT_QUOTES, 'UTF-8');
	}
	//if the login form is submitted 
	if ($_SESSION['csrf_token']) {
    		$csrf_token = $_SESSION['csrf_token'];
	} else {
    		$csrf_token = uniqid();
    		$_SESSION['csrf_token'] = $csrf_token;
	}
	
	if (isset($_POST['post_submit'])) {

		$goodMessage = escape($_POST['message']);
		$_POST['title'] = trim($_POST['title']);
		if(!$_POST['title'] | !$goodMessage) {
			include('header.php');
			die('<p>You did not fill in a required field.
			Please go back and try again!</p>');
		}

		if(!$_POST['token'] | $_POST['token'] != $csrf_token){
			header('location: 404.php');
			exit;
		}
 		

		$hackmeCookie = mysqli_real_escape_string($DB, $_COOKIE['hackme']);
		$title = mysqli_real_escape_string($DB, $_POST['title']);
		mysqli_query($DB, "INSERT INTO threads (username, title, message, date) VALUES('$hackmeCookie', '$title', '". $goodMessage."', '".time()."')")or die(mysqli_error($DB));
		
		header("Location: members.php");



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
            
            <h2 class="title">NEW POST</h2>
            <p class="meta">by <a href="#"><?php echo $_COOKIE['hackme'] ?> </a></p>
            <p> do not leave any fields blank... </p>
            
	    <form method="post" action="post.php">
		
	    <input type="hidden" name="token" value=<?=$csrf_token?>>
            Title: <input type="text" name="title" maxlength="50"/>
            <br />
            <br />
            Posting:
            <br />
            <br />
            <textarea name="message" cols="120" rows="10" id="message"></textarea>
            <br />
            <br />
            <input name="post_submit" type="submit" id="post_submit" value="POST" />
            </form>
        </div>
    </div>
</div>

<?php
	include('footer.php');
?>
</body>
</html>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>hackme</title>
<link href="style.css" rel="stylesheet" type="text/css" media="screen" />
<?php
	include('connect.php');
	include('header.php');
	$DB = connect();
?>
<div class="post">
	<div class="post-bgtop">
		<div class="post-bgbtm">
        <h2 class = "title">hackme Registration</h2>
        <?php
		//if the registration form is submitted 
		if (isset($_POST['submit'])) {
			
			$_POST['uname'] = trim($_POST['uname']);
			if(!$_POST['uname'] | !$_POST['password'] |
				!$_POST['fname'] | !$_POST['lname']) {
 				die('<p>You did not fill in a required field.
				Please go back and try again!</p>');
			}

			if(strlen($_POST['password']) <= 7){
                              die('<p>Your password is not at least 8 characters.</p>');
                        }

                        //if(strpos($_POST['password'], '!')| strpos($_POST['password'], '@')){
                        if(!preg_match('/[^a-zA-Z\d]/', $_POST['password'])){
                              die('<p>You must include at least one non dictionary character.</p>');
                        }

		

			$password = $_POST['password'];
			$hashed_password = password_hash($password, PASSWORD_BCRYPT);
			$uname = mysqli_real_escape_string($DB, $_POST['uname']);	
			$check = mysqli_query($DB, "SELECT * FROM users WHERE username = '$uname'") or die(mysqli_error($DB));
 
 		//Gives error if user already exist
 		$check2 = mysqli_num_rows($check);
		if ($check2 != 0) {
			die('<p>Sorry, user name already exisits.</p>');
		}
		else
		{
			$uname = mysqli_real_escape_string($DB, $_POST['uname']);
			$fname = mysqli_real_escape_string($DB, $_POST['fname']);
			$lname = mysqli_real_escape_string($DB, $_POST['lname']);
			mysqli_query($DB, "INSERT INTO users (username, pass, fname, lname) VALUES ('$uname', '". $hashed_password ."', '$fname', '$lname');")or die(mysqli_error());
			
			echo "<h3> Registration Successful!</h3> <p>Welcome ". $_POST['fname'] ."! Please log in...</p>";
		} 
        ?>    
        <?php
		}else{
        ?>
        	<form  method="post" action="register.php">
            <table>
                <tr>
                    <td> Username </td> 
                    <td> <input type="text" name="uname" maxlength="20"/> </td>
                    <td> <em>choose a login id</em> </td>
                </tr>
                <tr>
                    <td> Password </td>
                    <td> <input type="password" name="password" maxlength="40" /> </td>
                </tr>
                <tr>
                    <td> First Name </td>
                    <td> <input type="text" name="fname" maxlength="25"/> </td>
                </tr>
                 <tr>
                    <td> Last Name </td>
                    <td> <input type="text" name="lname" maxlength="25"/> </td>
                </tr>
                <tr>
                    <td> <input type="submit" name="submit" value="Register" /> </td>
                </tr>
            </table>
            </form>
        <?php
		}
		?>
        </div>
    </div>
</div>
<?php
	include('footer.php');
?>
</body>
</html>

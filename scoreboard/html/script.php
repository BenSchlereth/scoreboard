<?php
$value = $_POST["var1"];
file_put_contents("/home/pi/projects/code/value.txt", $value);

$select = $_POST["var2"];
file_put_contents("/home/pi/projects/code/segmentselect.txt", $select);
?>

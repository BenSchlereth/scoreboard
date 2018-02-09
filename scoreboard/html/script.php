<?php
$value = $_POST["var1"];
$cs = $_POST["var2"];
system("sudo python /var/www/html/shiftregister.py $value $cs");
echo $value;

?>

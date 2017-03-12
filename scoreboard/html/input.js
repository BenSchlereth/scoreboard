// score input and output

//init
var scoreHome = 0;
var scoreGuest = 0;
var score= 0;

$('#home').text(scoreHome);
$('#guest').text(scoreGuest);


//score for Home team
document.querySelector('box1').onclick = function() 
{
	var score = prompt('How many points where scored?');
	scoreHome = +scoreHome + +score;			//For adding numbers and not strings the (+) before the variable is needed
	$('#home').text(scoreHome);
	

	$.ajax({
	type: "POST",
	url: "script.php",
	data: {var1: scoreHome, var2: 1},
	});

}


//score for Guest team
document.querySelector('box2').onclick = function() 
{
	var score = prompt('How many points where scored?');
	scoreGuest = +scoreGuest + +score;	
	$('#guest').text(scoreGuest);
}



//Counter for Quarters
var count = 4;
$('#quarter').text("Quarter: " + count);
document.querySelector('h3').onclick = function() 
{
	if (count!=0) count--;
	else count = 4;
	$('#quarter').text("Quarter: " + count);
}



//Timer copied from http://stackoverflow.com/

var mins = 15;  		//Set the number of minutes you need
var secs = mins * 60;
var currentSeconds = 0;
var currentMinutes = 0;
var bool = 1;

setTimeout(Decrement,1000); 

document.querySelector('h2').onclick = function() 
{
	if (bool !== 1) bool = 1;
	else bool = 0; 
}

function Decrement() 
{
document.querySelector('h2').onclick = function() 
{
	if (bool !== 1) bool = 1;
	else bool = 0; 
}

	if (bool !== 0)
	{        
		currentMinutes = Math.floor(secs / 60);
		currentSeconds = secs % 60;
		if(currentSeconds <= 9) currentSeconds = "0" + currentSeconds;
		secs--;
		document.getElementById("timerText").innerHTML = currentMinutes + ":" + currentSeconds; //Set the element id you need the time put into.
		if(secs !== -1) setTimeout('Decrement()',1000);
	}
}


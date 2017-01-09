// score input and output



//init
var scoreHome = 0;
var scoreGuest = 0;
var score= 0;

$('#home').text(scoreHome);
$('#guest').text(scoreGuest);


function writeregister(n)
{
//console.log(n);
var count = 7;
var byte;
byte = Math.floor(n%10);
//console.log(byte);
console.log(typeof(byte));
	do
        {
                if(count===0)
                {
			write1();
                }
                else if(count===1 && (byte===1 || byte===4))
                {
                        write1();
                }
                else if(count===2 && (byte===5 || byte===6)) 
                {       
			write1();
                }
                else if(count===3 && byte===2)
                {       
			write1();
                }
                else if(count===4 && (byte===1 || byte===4 || byte===7)) 
                {
                        write1();
                }
                 else if(count===5 && (byte===1 || n===3 || n===4 || n===5 || n===7 || n===9))
                {
			write1();
                }
                else if(count===6 && (n===1 || n===2 || n===3 || n===7))
                {
			write1();
                }
                else if(count===7 && (n===0 || n===1 || n===7))
                {
			write1();
                }
                else
                {
			write0();
                }
      		count--;                                        //decrement count
        } while (count>=0);                               //exit when Bit0 is set
}

function write1()
{
var bit=1;
console.log(bit);
}

function write0()
{
var bit=0;
console.log(bit);
}

//score for Home team
document.querySelector('box1').onclick = function() 
{
	var score = prompt('How many points where scored?');
	scoreHome = +scoreHome + +score;			//For adding numbers and not strings the (+) before the variable is needed
	$('#home').text(scoreHome);
	writeregister(scoreHome);
	if(scoreHome>9) writeregister(scoreHome/10);
	else writeregister(0);	 
		
	
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



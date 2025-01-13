//Umschalten von Webseiteninhalten
	var colorButton = "#007878";
	let vordergrundAktiv = 1;
	let hintergrundAktiv = 0;
	
	var ready = 0;

	var red = 0; 
	var green = 0;
	var blue = 0;
	var white = 0;
	
	window.onload = function () {
        getColor();
		getParams();
    }
	
function vordergrund () {
	buttonReset();
	vordergrundAktiv = 1;
	hintergrundAktiv = 0;
	getColor();
	document.getElementById("button-menu-vordergrund").style.backgroundColor = colorButton;
	send();
}

function hintergrund () {
	buttonReset();
	vordergrundAktiv = 0;
	hintergrundAktiv = 1;
	getColor();
	document.getElementById("button-menu-hintergrund").style.backgroundColor = colorButton;
	send();
}

function farbe () {
	buttonReset();
	vordergrundAktiv = 0;
	hintergrundAktiv = 0;
	getColor();
	document.getElementById("button-menu-farbe").style.backgroundColor = colorButton;
	send();
}
function rainbow () {
	buttonReset();
	var xhttp = new XMLHttpRequest();
	xhttp.open("GET", "/rainbow", true);
	xhttp.send();
	document.getElementById("button-menu-regenbogen").style.backgroundColor = colorButton;
	document.getElementById("farbmischer").style.display="none";
}
function reeset() {
	buttonReset();
	
	vordergrundAktiv = 0;
	hintergrundAktiv = 1;
	
	document.getElementById("slider-red").value = 0;
	document.getElementById("slider-green").value = 0;
	document.getElementById("slider-blue").value = 0;
	document.getElementById("slider-white").value = 0;
	
	send();
	
	
	vordergrundAktiv = 1;
	hintergrundAktiv = 0;
	
	document.getElementById("slider-red").value = 0;
	document.getElementById("slider-green").value = 0;
	document.getElementById("slider-blue").value = 0;
	document.getElementById("slider-white").value = 60;
	document.getElementById("button-menu-vordergrund").style.backgroundColor = colorButton;
	send();
}
function config () {
	buttonReset();
	document.getElementById("button-menu-config").style.backgroundColor = colorButton;
	document.getElementById("farbmischer").style.display="none";
	document.getElementById("config").style.display="block";
}

function buttonReset () {
	document.getElementById("button-menu-vordergrund").style.backgroundColor = "#535353";
	document.getElementById("button-menu-hintergrund").style.backgroundColor = "#535353";
	document.getElementById("button-menu-farbe").style.backgroundColor = "#535353";
	document.getElementById("button-menu-regenbogen").style.backgroundColor = "#535353";
	document.getElementById("button-menu-animation").style.backgroundColor = "#535353";
	document.getElementById("button-menu-config").style.backgroundColor = "#535353";
	
	document.getElementById("farbmischer").style.display="block";
	document.getElementById("config").style.display="none";
}





function getParams () {
	var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
		var jsonResponse = JSON.parse(this.responseText);
		document.getElementById("time1").value = jsonResponse.ldrtime1;
		document.getElementById("time2").value = jsonResponse.ldrtime2;
		document.getElementById("time3").value = jsonResponse.ldrtime3;
		document.getElementById("setting1").value = jsonResponse.setting1;
		document.getElementById("setting2").value = jsonResponse.setting2;
		document.getElementById("setting3").value = jsonResponse.setting3;
    }
  };  
  xhttp.open("GET", "/getparams", false);
  xhttp.send();
}





function getColor () {
	var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
		var jsonResponse = JSON.parse(this.responseText);
		document.getElementById("slider-red").value = jsonResponse.red;
		document.getElementById("slider-green").value = jsonResponse.green;
		document.getElementById("slider-blue").value = jsonResponse.blue;
		document.getElementById("slider-white").value = jsonResponse.white;
		updateColor();
    }
  };  
  var ebene = 0;
  if(vordergrundAktiv == 0 && hintergrundAktiv == 1)ebene = 1;
  if(vordergrundAktiv == 0 && hintergrundAktiv == 0)ebene = 2;
  xhttp.open("GET", "/getcolor?ebene=" + ebene, false);
  xhttp.send();
}




function updateColor() {
	
	if(vordergrundAktiv){
	red = document.getElementById("slider-red").value;
	green = document.getElementById("slider-green").value;
	blue = document.getElementById("slider-blue").value;
	if(document.getElementById("slider-white").value > 1){red = 255; green = 255; blue = 255;}
    let backgroundColor = `rgb(${red},${green},${blue})`
	document.getElementById("topbar").style.color = backgroundColor;
	}
	
	if(hintergrundAktiv){
	red = document.getElementById("slider-red").value;
	green = document.getElementById("slider-green").value;
	blue = document.getElementById("slider-blue").value;
	if(document.getElementById("slider-white").value > 1){red = 255; green = 255; blue = 255;}
    let backgroundColor = `rgb(${red},${green},${blue})`;
	document.getElementById("topbar").style.backgroundColor = backgroundColor;
	}
	
	document.getElementById("redvalue").innerHTML = document.getElementById("slider-red").value;
	document.getElementById("greenvalue").innerHTML = document.getElementById("slider-green").value;
	document.getElementById("bluevalue").innerHTML = document.getElementById("slider-blue").value;
	document.getElementById("whitevalue").innerHTML = document.getElementById("slider-white").value;
}

function syncSlider(){
	document.getElementById("slider-white").value = 0;
	send();
}


function syncWhiteSlider(){
	document.getElementById("slider-red").value = 0;
	document.getElementById("slider-green").value = 0;
	document.getElementById("slider-blue").value = 0;
	send();
}

function send(){
	updateColor();
	var xhttp = new XMLHttpRequest();
  red = document.getElementById("slider-red").value;
  green = document.getElementById("slider-green").value;
  blue = document.getElementById("slider-blue").value;
  white = document.getElementById("slider-white").value;
  if(vordergrundAktiv)xhttp.open("GET", "/vordergrund?red=" + red + "&&green=" + green +"&&blue=" + blue + "&&white=" + white, true);
  if(hintergrundAktiv)xhttp.open("GET", "/hintergrund?red=" + red + "&&green=" + green +"&&blue=" + blue + "&&white=" + white, true);
  if(hintergrundAktiv == 0 && vordergrundAktiv == 0)xhttp.open("GET", "/farbe?red=" + red + "&&green=" + green +"&&blue=" + blue, true);
  xhttp.send();
}

function sendconfig(){
	var xhttp = new XMLHttpRequest();
  var time1 = document.getElementById("time1").value;
  var time2 = document.getElementById("time2").value;
  var time3 = document.getElementById("time3").value;
  var setting1 = document.getElementById("setting1").value;
  var setting2 = document.getElementById("setting2").value;
  var setting3 = document.getElementById("setting3").value;
  xhttp.open("GET", "/config?timeeins=" + time1 + "&&settingeins=" + setting1 + "&&timezwei=" + time2 + "&&settingzwei=" + setting2 + "&&timedrei=" + time3 + "&&settingdrei=" + setting3 , true);
  xhttp.send();
}

function settime(){
var xhttp = new XMLHttpRequest();
  xhttp.open("GET", "/settime" , true);
  xhttp.send();
}

function presetRot(){
	document.getElementById("slider-red").value = 255;	
	document.getElementById("slider-green").value = 0;	
	document.getElementById("slider-blue").value = 0;
	document.getElementById("slider-white").value = 0;	
	send();
}

function presetGruen(){
	document.getElementById("slider-red").value = 0;	
	document.getElementById("slider-green").value = 255;	
	document.getElementById("slider-blue").value = 0;	
	document.getElementById("slider-white").value = 0;	
	send();
}
function presetBlau(){
	document.getElementById("slider-red").value = 0;	
	document.getElementById("slider-green").value = 0;	
	document.getElementById("slider-blue").value = 255;	
	document.getElementById("slider-white").value = 0;	
	send();
}
function presetWeiß(){
	document.getElementById("slider-red").value = 0;	
	document.getElementById("slider-green").value = 0;	
	document.getElementById("slider-blue").value = 0;	
	document.getElementById("slider-white").value = 255;	
	send();
}
function presetLila(){
	document.getElementById("slider-red").value = 221;	
	document.getElementById("slider-green").value = 0;	
	document.getElementById("slider-blue").value = 255;	
	document.getElementById("slider-white").value = 0;	
	send();
}
function presetGelb(){
	document.getElementById("slider-red").value = 255;	
	document.getElementById("slider-green").value = 221;	
	document.getElementById("slider-blue").value = 0;	
	document.getElementById("slider-white").value = 0;	
	send();
}
function presetTuerkis(){
	document.getElementById("slider-red").value = 0;	
	document.getElementById("slider-green").value = 238;
	document.getElementById("slider-blue").value = 255;	
	document.getElementById("slider-white").value = 0;	
	send();
}
function presetSchwarz(){
	document.getElementById("slider-red").value = 0;	
	document.getElementById("slider-green").value = 0;	
	document.getElementById("slider-blue").value = 0;	
	document.getElementById("slider-white").value = 0;	
	send();
}

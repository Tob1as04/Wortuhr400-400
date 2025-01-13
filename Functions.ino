void lichttest();
void vor();
void nach();


void lichttest(){
  tlc.setBrightness(200);  
  for(int i=0; i<239;i++)
  {
    if(i != 0)tlc.setPixel(i-1, 0);
    tlc.setPixel(i,true);
    //if(i != 0)tlc.setPixel(i-1, false);
    tlc.show();
    delay(800);
  }
  tlc.show();
  delay(4000);
  tlc.clear();
  tlc.show();
  delay(1000);
  tlc.off();

  rgb.clear();
  for(int i=0; i<NUM_RGB; i++) { // For each pixel...
    rgb.setPixelColor(i, rgb.Color(50, 0, 0));
  }
  rgb.show();
  delay(10000);
  rgb.clear();
  for(int i=0; i<NUM_RGB; i++) { // For each pixel...
    rgb.setPixelColor(i, rgb.Color(0, 50, 0));
  }
  rgb.show();
  delay(10000);
  rgb.clear();
  for(int i=0; i<NUM_RGB; i++) { // For each pixel...
    rgb.setPixelColor(i, rgb.Color(0, 0, 50));
  }
  rgb.show();
  delay(10000);
  rgb.clear();
  rgb.show();
}

void farbe(){
  for(int i = 0; i < 118; i++){
    rgb.setPixelColor(i, rgb.Color(farbered*240/255, farbegreen*240/255, farbeblue*240/255));
  }
  tlc.off();
  rgb.show();
}

void rainbow(){
  tlc.off();
  if(millis() > lastMillis){
    lastMillis = millis();
    rainbowcounter += 100;
    if(rainbowcounter > 65535)rainbowcounter = 0;
    rgb.rainbow(rainbowcounter);
    rgb.show();
  }
}


void update(){
  update(red,green,blue,white,backgroundred,backgroundgreen, backgroundblue);
}
void update(int red, int green, int blue, int white, int backgroundred, int backgroundgreen, int backgroundblue){ 
  hour = timeinfo->tm_hour;
  tlc.clear();
  rgb.clear();
  for(int i = 0; i < 118; i++){
    rgb.setPixelColor(i, rgb.Color(backgroundred, backgroundgreen, backgroundblue));
  }
  //Minutenstriche
  if(minute % 5 >= 1){
    rgb.setPixelColor(110, rgb.Color(red, green, blue));
    tlc.setPixel(8,true);
    tlc.setPixel(7,true);
    rgb.setPixelColor(111, rgb.Color(red, green, blue));
    tlc.setPixel(9,true);
    tlc.setPixel(6,true);
  }
  if(minute % 5 >= 2){
    rgb.setPixelColor(112, rgb.Color(red, green, blue));
    tlc.setPixel(10,true);
    tlc.setPixel(5,true);
    rgb.setPixelColor(113, rgb.Color(red, green, blue));
    tlc.setPixel(11,true);
    tlc.setPixel(4,true);
  }
  if(minute % 5 >= 3){
    rgb.setPixelColor(114, rgb.Color(red, green, blue));
    tlc.setPixel(12,true);
    tlc.setPixel(3,true);
    rgb.setPixelColor(115, rgb.Color(red, green, blue));
    tlc.setPixel(13,true);
    tlc.setPixel(2,true);
  }
  if(minute % 5 == 4){
    rgb.setPixelColor(116, rgb.Color(red, green, blue));
    tlc.setPixel(14,true);
    tlc.setPixel(1,true);
    rgb.setPixelColor(117, rgb.Color(red, green, blue));
    tlc.setPixel(15,true);
    tlc.setPixel(0,true);
  }
   //Es ist
  rgb.setPixelColor(0, rgb.Color(red, green, blue));
  tlc.setPixel(168,true);
  tlc.setPixel(167,true);
  rgb.setPixelColor(1, rgb.Color(red, green, blue));
  tlc.setPixel(169,true);
  tlc.setPixel(166,true);
  rgb.setPixelColor(3, rgb.Color(red, green, blue));
  tlc.setPixel(171,true);
  tlc.setPixel(164,true);
  rgb.setPixelColor(4, rgb.Color(red, green, blue));
  tlc.setPixel(172,true);
  tlc.setPixel(163,true);
  rgb.setPixelColor(5, rgb.Color(red, green, blue));
  tlc.setPixel(173,true);
  tlc.setPixel(162,true);

  //fünf nach
  if(minute >= 5 && minute < 10){
    rgb.setPixelColor(7, rgb.Color(red, green, blue));
    tlc.setPixel(175,true);
    tlc.setPixel(160,true);
    rgb.setPixelColor(8, rgb.Color(red, green, blue));
    tlc.setPixel(177,true);
    tlc.setPixel(176,true);
    rgb.setPixelColor(9, rgb.Color(red, green, blue));
    tlc.setPixel(179,true);
    tlc.setPixel(178,true);
    rgb.setPixelColor(10, rgb.Color(red, green, blue));
    tlc.setPixel(181,true);
    tlc.setPixel(180,true);
    nach(red, green, blue);
  }
  //zehn nach
  if(minute >= 10 && minute < 15){
    rgb.setPixelColor(21, rgb.Color(red, green, blue));
    tlc.setPixel(152,true);
    tlc.setPixel(151,true);
    rgb.setPixelColor(20, rgb.Color(red, green, blue));
    tlc.setPixel(153,true);
    tlc.setPixel(150,true);
    rgb.setPixelColor(19, rgb.Color(red, green, blue));
    tlc.setPixel(154,true);
    tlc.setPixel(149,true);
    rgb.setPixelColor(18, rgb.Color(red, green, blue));
    tlc.setPixel(155,true);
    tlc.setPixel(148,true);
    nach(red, green, blue);
  }

  //viertel nach
  if(minute >= 15 && minute < 20){
    rgb.setPixelColor(26, rgb.Color(red, green, blue));
    tlc.setPixel(140,true);
    tlc.setPixel(131,true);
    rgb.setPixelColor(27, rgb.Color(red, green, blue));
    tlc.setPixel(141,true);
    tlc.setPixel(130,true);
    rgb.setPixelColor(28, rgb.Color(red, green, blue));
    tlc.setPixel(142,true);
    tlc.setPixel(129,true);
    rgb.setPixelColor(29, rgb.Color(red, green, blue));
    tlc.setPixel(143,true);
    tlc.setPixel(128,true);
    rgb.setPixelColor(30, rgb.Color(red, green, blue));
    tlc.setPixel(188,true);
    tlc.setPixel(189,true);
    rgb.setPixelColor(31, rgb.Color(red, green, blue));
    tlc.setPixel(190,true);
    tlc.setPixel(191,true);
    rgb.setPixelColor(32, rgb.Color(red, green, blue));
    tlc.setPixel(192,true);
    tlc.setPixel(193,true);
    nach(red, green, blue);
  }
    
  //zwanzig nach
  if(minute >= 20 && minute < 25){
    rgb.setPixelColor(17, rgb.Color(red, green, blue));
    tlc.setPixel(156,true);
    tlc.setPixel(147,true);
    rgb.setPixelColor(16, rgb.Color(red, green, blue));
    tlc.setPixel(157,true);
    tlc.setPixel(146,true);
    rgb.setPixelColor(15, rgb.Color(red, green, blue));
    tlc.setPixel(158,true);
    tlc.setPixel(145,true);
    rgb.setPixelColor(14, rgb.Color(red, green, blue));
    tlc.setPixel(159,true);
    tlc.setPixel(144,true);
    rgb.setPixelColor(13, rgb.Color(red, green, blue));
    tlc.setPixel(183,true);
    tlc.setPixel(182,true);
    rgb.setPixelColor(12, rgb.Color(red, green, blue));
    tlc.setPixel(184,true);
    tlc.setPixel(185,true);
    rgb.setPixelColor(11, rgb.Color(red, green, blue));
    tlc.setPixel(186,true);
    tlc.setPixel(187,true);
    nach(red, green, blue);
  }
   //fünf vor halb
  if(minute >=25 && minute < 30){
    rgb.setPixelColor(7, rgb.Color(red, green, blue));
    tlc.setPixel(175,true);
    tlc.setPixel(160,true);
    rgb.setPixelColor(8, rgb.Color(red, green, blue));
    tlc.setPixel(177,true);
    tlc.setPixel(176,true);
    rgb.setPixelColor(9, rgb.Color(red, green, blue));
    tlc.setPixel(179,true);
    tlc.setPixel(178,true);
    rgb.setPixelColor(10, rgb.Color(red, green, blue));
    tlc.setPixel(181,true);
    tlc.setPixel(180,true);
    vor(red, green, blue);
    rgb.setPixelColor(44, rgb.Color(red, green, blue));
    tlc.setPixel(104,true);
    tlc.setPixel(103,true);
    rgb.setPixelColor(45, rgb.Color(red, green, blue));
    tlc.setPixel(105,true);
    tlc.setPixel(102,true);
    rgb.setPixelColor(46, rgb.Color(red, green, blue));
    tlc.setPixel(106,true);
    tlc.setPixel(101,true);
    rgb.setPixelColor(47, rgb.Color(red, green, blue));
    tlc.setPixel(107,true);
    tlc.setPixel(100,true);
  }
  
  //halb 
  if(minute >=30 && minute < 35){
    rgb.setPixelColor(44, rgb.Color(red, green, blue));
    tlc.setPixel(104,true);
    tlc.setPixel(103,true);
    rgb.setPixelColor(45, rgb.Color(red, green, blue));
    tlc.setPixel(105,true);
    tlc.setPixel(102,true);
    rgb.setPixelColor(46, rgb.Color(red, green, blue));
    tlc.setPixel(106,true);
    tlc.setPixel(101,true);
    rgb.setPixelColor(47, rgb.Color(red, green, blue));
    tlc.setPixel(107,true);
    tlc.setPixel(100,true);
  }
  
  //fünf nach halb
  if(minute >=35 && minute < 40){
    rgb.setPixelColor(7, rgb.Color(red, green, blue));
    tlc.setPixel(175,true);
    tlc.setPixel(160,true);
    rgb.setPixelColor(8, rgb.Color(red, green, blue));
    tlc.setPixel(177,true);
    tlc.setPixel(176,true);
    rgb.setPixelColor(9, rgb.Color(red, green, blue));
    tlc.setPixel(179,true);
    tlc.setPixel(178,true);
    rgb.setPixelColor(10, rgb.Color(red, green, blue));
    tlc.setPixel(181,true);
    tlc.setPixel(180,true);
    nach(red, green, blue);
    rgb.setPixelColor(44, rgb.Color(red, green, blue));
    tlc.setPixel(104,true);
    tlc.setPixel(103,true);
    rgb.setPixelColor(45, rgb.Color(red, green, blue));
    tlc.setPixel(105,true);
    tlc.setPixel(102,true);
    rgb.setPixelColor(46, rgb.Color(red, green, blue));
    tlc.setPixel(106,true);
    tlc.setPixel(101,true);
    rgb.setPixelColor(47, rgb.Color(red, green, blue));
    tlc.setPixel(107,true);
    tlc.setPixel(100,true);
  }
  
  //zwanzig vor
  if(minute >=40 && minute < 45){
    rgb.setPixelColor(17, rgb.Color(red, green, blue));
    tlc.setPixel(156,true);
    tlc.setPixel(147,true);
    rgb.setPixelColor(16, rgb.Color(red, green, blue));
    tlc.setPixel(157,true);
    tlc.setPixel(146,true);
    rgb.setPixelColor(15, rgb.Color(red, green, blue));
    tlc.setPixel(158,true);
    tlc.setPixel(145,true);
    rgb.setPixelColor(14, rgb.Color(red, green, blue));
    tlc.setPixel(159,true);
    tlc.setPixel(144,true);
    rgb.setPixelColor(13, rgb.Color(red, green, blue));
    tlc.setPixel(183,true);
    tlc.setPixel(182,true);
    rgb.setPixelColor(12, rgb.Color(red, green, blue));
    tlc.setPixel(184,true);
    tlc.setPixel(185,true);
    rgb.setPixelColor(11, rgb.Color(red, green, blue));
    tlc.setPixel(186,true);
    tlc.setPixel(187,true);
    vor(red, green, blue);
  }
  //viertel vor //dreiviertel
    if(minute >=45 && minute < 50){
      
      rgb.setPixelColor(26, rgb.Color(red, green, blue));
      tlc.setPixel(140,true);
      tlc.setPixel(131,true);
      rgb.setPixelColor(27, rgb.Color(red, green, blue));
      tlc.setPixel(141,true);
      tlc.setPixel(130,true);
      rgb.setPixelColor(28, rgb.Color(red, green, blue));
      tlc.setPixel(142,true);
      tlc.setPixel(129,true);
      rgb.setPixelColor(29, rgb.Color(red, green, blue));
      tlc.setPixel(143,true);
      tlc.setPixel(128,true);
      rgb.setPixelColor(30, rgb.Color(red, green, blue));
      tlc.setPixel(188,true);
      tlc.setPixel(189,true);
      rgb.setPixelColor(31, rgb.Color(red, green, blue));
      tlc.setPixel(190,true);
      tlc.setPixel(191,true);
      rgb.setPixelColor(32, rgb.Color(red, green, blue));
      tlc.setPixel(192,true);
      tlc.setPixel(193,true);
      vor(red, green, blue);

      /*
      rgb.setPixelColor(22, rgb.Color(red, green, blue));
      tlc.setPixel(136,true);
      tlc.setPixel(135,true);
      rgb.setPixelColor(23, rgb.Color(red, green, blue));
      tlc.setPixel(137,true);
      tlc.setPixel(134,true);
      rgb.setPixelColor(24, rgb.Color(red, green, blue));
      tlc.setPixel(138,true);
      tlc.setPixel(133,true);
      rgb.setPixelColor(25, rgb.Color(red, green, blue));
      tlc.setPixel(139,true);
      tlc.setPixel(132,true);
      rgb.setPixelColor(26, rgb.Color(red, green, blue));
      tlc.setPixel(140,true);
      tlc.setPixel(131,true);
      rgb.setPixelColor(27, rgb.Color(red, green, blue));
      tlc.setPixel(141,true);
      tlc.setPixel(130,true);
      rgb.setPixelColor(28, rgb.Color(red, green, blue));
      tlc.setPixel(142,true);
      tlc.setPixel(129,true);
      rgb.setPixelColor(29, rgb.Color(red, green, blue));
      tlc.setPixel(143,true);
      tlc.setPixel(128,true);
      rgb.setPixelColor(30, rgb.Color(red, green, blue));
      tlc.setPixel(188,true);
      tlc.setPixel(189,true);
      rgb.setPixelColor(31, rgb.Color(red, green, blue));
      tlc.setPixel(190,true);
      tlc.setPixel(191,true);
      rgb.setPixelColor(32, rgb.Color(red, green, blue));
      tlc.setPixel(192,true);
      tlc.setPixel(193,true);
      */
    }
    
    //zehn vor
    if(minute >=50 && minute < 55){
      rgb.setPixelColor(21, rgb.Color(red, green, blue));
      tlc.setPixel(152,true);
      tlc.setPixel(151,true);
      rgb.setPixelColor(20, rgb.Color(red, green, blue));
      tlc.setPixel(153,true);
      tlc.setPixel(150,true);
      rgb.setPixelColor(19, rgb.Color(red, green, blue));
      tlc.setPixel(154,true);
      tlc.setPixel(149,true);
      rgb.setPixelColor(18, rgb.Color(red, green, blue));
      tlc.setPixel(155,true);
      tlc.setPixel(148,true);
      vor(red, green, blue);
    }
    
    //fünf vor
    if(minute >=55){
      rgb.setPixelColor(7, rgb.Color(red, green, blue));
      tlc.setPixel(175,true);
      tlc.setPixel(160,true);
      rgb.setPixelColor(8, rgb.Color(red, green, blue));
      tlc.setPixel(177,true);
      tlc.setPixel(176,true);
      rgb.setPixelColor(9, rgb.Color(red, green, blue));
      tlc.setPixel(179,true);
      tlc.setPixel(178,true);
      rgb.setPixelColor(10, rgb.Color(red, green, blue));
      tlc.setPixel(181,true);
      tlc.setPixel(180,true);
      vor(red, green, blue);

    }

    
    //Ab fünf vor Halb Stunde um 1 erhöhen
    if(minute >= 25){hour++;}
    //if(minute >=25 && hour == 23) war falsch
    if(hour >= 24){hour = 0;}

    switch(hour){
      //ein
      case 1: 
      case 13:
      rgb.setPixelColor(65, rgb.Color(red, green, blue));
      tlc.setPixel(88,true);
      tlc.setPixel(87,true);
      rgb.setPixelColor(64, rgb.Color(red, green, blue));
      tlc.setPixel(89,true);
      tlc.setPixel(86,true);
      rgb.setPixelColor(63, rgb.Color(red, green, blue));
      tlc.setPixel(90,true);
      tlc.setPixel(85,true);
      if(minute > 4)
      {
        rgb.setPixelColor(62, rgb.Color(red, green, blue));
        tlc.setPixel(91,true);
        tlc.setPixel(84,true);
      }
      break;

      //zwei
      case 2:
      case 14:
      rgb.setPixelColor(58, rgb.Color(red, green, blue));
      tlc.setPixel(95,true);
      tlc.setPixel(80,true);
      rgb.setPixelColor(57, rgb.Color(red, green, blue));
      tlc.setPixel(209,true);
      tlc.setPixel(208,true);
      rgb.setPixelColor(56, rgb.Color(red, green, blue));
      tlc.setPixel(211,true);
      tlc.setPixel(210,true);
      rgb.setPixelColor(55, rgb.Color(red, green, blue));
      tlc.setPixel(213,true);
      tlc.setPixel(212,true);
      break;

      //drei
      case 3:
      case 15:
      rgb.setPixelColor(66, rgb.Color(red, green, blue));
      tlc.setPixel(72,true);
      tlc.setPixel(71,true);
      rgb.setPixelColor(67, rgb.Color(red, green, blue));
      tlc.setPixel(73,true);
      tlc.setPixel(70,true);
      rgb.setPixelColor(68, rgb.Color(red, green, blue));
      tlc.setPixel(74,true);
      tlc.setPixel(69,true);
      rgb.setPixelColor(69, rgb.Color(red, green, blue));
      tlc.setPixel(75,true);
      tlc.setPixel(68,true);
      break;

      //vier
      case 4:
      case 16:
      rgb.setPixelColor(73, rgb.Color(red, green, blue));
      tlc.setPixel(79,true);
      tlc.setPixel(64,true);
      rgb.setPixelColor(74, rgb.Color(red, green, blue));
      tlc.setPixel(215,true);
      tlc.setPixel(214,true);
      rgb.setPixelColor(75, rgb.Color(red, green, blue));
      tlc.setPixel(216,true);
      tlc.setPixel(217,true);
      rgb.setPixelColor(76, rgb.Color(red, green, blue));
      tlc.setPixel(218,true);
      tlc.setPixel(219,true);
      break;

      //fünf
      case 5:
      case 17:
      rgb.setPixelColor(51, rgb.Color(red, green, blue));
      tlc.setPixel(111,true);
      tlc.setPixel(96,true);
      rgb.setPixelColor(52, rgb.Color(red, green, blue));
      tlc.setPixel(200,true);
      tlc.setPixel(205,true);
      rgb.setPixelColor(53, rgb.Color(red, green, blue));
      tlc.setPixel(201,true);
      tlc.setPixel(204,true);
      rgb.setPixelColor(54, rgb.Color(red, green, blue));
      tlc.setPixel(202,true);
      tlc.setPixel(203,true);
      break;

      //sechs
      case 6:
      case 18:
      rgb.setPixelColor(87, rgb.Color(red, green, blue));
      tlc.setPixel(56,true);
      tlc.setPixel(55,true);
      rgb.setPixelColor(86, rgb.Color(red, green, blue));
      tlc.setPixel(57,true);
      tlc.setPixel(54,true);
      rgb.setPixelColor(85, rgb.Color(red, green, blue));
      tlc.setPixel(58,true);
      tlc.setPixel(53,true);
      rgb.setPixelColor(84, rgb.Color(red, green, blue));
      tlc.setPixel(59,true);
      tlc.setPixel(52,true);
      rgb.setPixelColor(83, rgb.Color(red, green, blue));
      tlc.setPixel(60,true);
      tlc.setPixel(51,true);
      break;

      //sieben
      case 7:
      case 19:
      rgb.setPixelColor(88, rgb.Color(red, green, blue));
      tlc.setPixel(40,true);
      tlc.setPixel(39,true);
      rgb.setPixelColor(89, rgb.Color(red, green, blue));
      tlc.setPixel(41,true);
      tlc.setPixel(38,true);
      rgb.setPixelColor(90, rgb.Color(red, green, blue));
      tlc.setPixel(42,true);
      tlc.setPixel(37,true);
      rgb.setPixelColor(91, rgb.Color(red, green, blue));
      tlc.setPixel(43,true);
      tlc.setPixel(36,true);
      rgb.setPixelColor(92, rgb.Color(red, green, blue));
      tlc.setPixel(44,true);
      tlc.setPixel(35,true);
      rgb.setPixelColor(93, rgb.Color(red, green, blue));
      tlc.setPixel(45,true);
      tlc.setPixel(34,true);
      break;

      //acht
      case 8:
      case 20:
      rgb.setPixelColor(80, rgb.Color(red, green, blue));
      tlc.setPixel(63,true);
      tlc.setPixel(48,true);
      rgb.setPixelColor(79, rgb.Color(red, green, blue));
      tlc.setPixel(220,true);
      tlc.setPixel(221,true);
      rgb.setPixelColor(78, rgb.Color(red, green, blue));
      tlc.setPixel(222,true);
      tlc.setPixel(223,true);
      rgb.setPixelColor(77, rgb.Color(red, green, blue));
      tlc.setPixel(224,true);
      tlc.setPixel(225,true);
      break;

      //neun
      case 9:
      case 21:
      rgb.setPixelColor(106, rgb.Color(red, green, blue));
      tlc.setPixel(27,true);
      tlc.setPixel(20,true);
      rgb.setPixelColor(105, rgb.Color(red, green, blue));
      tlc.setPixel(28,true);
      tlc.setPixel(19,true);
      rgb.setPixelColor(104, rgb.Color(red, green, blue));
      tlc.setPixel(29,true);
      tlc.setPixel(18,true);
      rgb.setPixelColor(103, rgb.Color(red, green, blue));
      tlc.setPixel(30,true);
      tlc.setPixel(17,true);
      break;

      //zehn
      case 10:
      case 22:
      rgb.setPixelColor(109, rgb.Color(red, green, blue));
      tlc.setPixel(24,true);
      tlc.setPixel(23,true);
      rgb.setPixelColor(108, rgb.Color(red, green, blue));
      tlc.setPixel(25,true);
      tlc.setPixel(22,true);
      rgb.setPixelColor(107, rgb.Color(red, green, blue));
      tlc.setPixel(26,true);
      tlc.setPixel(21,true);
      rgb.setPixelColor(106, rgb.Color(red, green, blue));
      tlc.setPixel(27,true);
      tlc.setPixel(20,true);
      break;

      //elf
      case 11:
      case 23:
      rgb.setPixelColor(49, rgb.Color(red, green, blue));
      tlc.setPixel(109,true);
      tlc.setPixel(98,true);
      rgb.setPixelColor(50, rgb.Color(red, green, blue));
      tlc.setPixel(110,true);
      tlc.setPixel(97,true);
      rgb.setPixelColor(51, rgb.Color(red, green, blue));
      tlc.setPixel(111,true);
      tlc.setPixel(96,true);
      break;

      //zwölf
      case 12:
      case 0:
      rgb.setPixelColor(94, rgb.Color(red, green, blue));
      tlc.setPixel(46,true);
      tlc.setPixel(33,true);
      rgb.setPixelColor(95, rgb.Color(red, green, blue));
      tlc.setPixel(47,true);
      tlc.setPixel(32,true);
      rgb.setPixelColor(96, rgb.Color(red, green, blue));
      tlc.setPixel(226,true);
      tlc.setPixel(229,true);
      rgb.setPixelColor(97, rgb.Color(red, green, blue));
      tlc.setPixel(227,true);
      tlc.setPixel(230,true);
      rgb.setPixelColor(98, rgb.Color(red, green, blue));
      tlc.setPixel(228,true);
      tlc.setPixel(231,true);
      break;

      //Kein Plan welche Uhrzeit
      default:
      break;
      }
    

    //Uhr (zur vollen Stunde)
    if(minute < 5){
      rgb.setPixelColor(101, rgb.Color(red, green, blue));
      tlc.setPixel(232,true);
      tlc.setPixel(237,true);
      rgb.setPixelColor(100, rgb.Color(red, green, blue));
      tlc.setPixel(233,true);
      tlc.setPixel(236,true);
      rgb.setPixelColor(99, rgb.Color(red, green, blue));
      tlc.setPixel(234,true);
      tlc.setPixel(235,true);
    }

    tlc.off();
    rgb.show();
    tlc.setBrightness(white);
    tlc.show();
}

void nach(int red, int green, int blue){
  rgb.setPixelColor(36, rgb.Color(red, green, blue));
  tlc.setPixel(127,true);
  tlc.setPixel(112,true);
  rgb.setPixelColor(35, rgb.Color(red, green, blue));
  tlc.setPixel(194,true);
  tlc.setPixel(197,true);
  rgb.setPixelColor(34, rgb.Color(red, green, blue));
  tlc.setPixel(195,true);
  tlc.setPixel(198,true);
  rgb.setPixelColor(33, rgb.Color(red, green, blue));
  tlc.setPixel(196,true);
  tlc.setPixel(199,true);
}


void vor(int red, int green, int blue){
  rgb.setPixelColor(43, rgb.Color(red, green, blue));
  tlc.setPixel(120,true);
  tlc.setPixel(119,true);
  rgb.setPixelColor(42, rgb.Color(red, green, blue));
  tlc.setPixel(121,true);
  tlc.setPixel(118,true);
  rgb.setPixelColor(41, rgb.Color(red, green, blue));
  tlc.setPixel(122,true);
  tlc.setPixel(117,true);
}


void onOTAStart() {
  // Log when OTA has started
  Serial.println("OTA update started!");
  // <Add your own code here>
}

void onOTAProgress(size_t current, size_t final) {
  // Log every 1 second
  if (millis() - ota_progress_millis > 1000) {
    ota_progress_millis = millis();
    Serial.printf("OTA Progress Current: %u bytes, Final: %u bytes\n", current, final);
  }
}

void onOTAEnd(bool success) {
  // Log when OTA has finished
  if (success) {
    Serial.println("OTA update finished successfully!");
  } else {
    Serial.println("There was an error during OTA update!");
  }
  // <Add your own code here>
}


void syncTime(){
  configTime("CET-1CEST,M3.5.0,M10.5.0/3", 0, ntpServer1, ntpServer2);//Konfiguriert die Zeit, hier kein Timeoffset und Daylightoffset, da dies später durch die Zeitzone gesetzt wird.
  delay(300);
  time(&rawtime);
}
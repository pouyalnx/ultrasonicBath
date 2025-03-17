#include "menu.h"
#include "lcd.h"
#include "r1.h"
#include "button.h"




const unsigned short int sin_table[]={
0,6,12,18,25,31,37,44,50,56,62
,69,75,81,87,94,100,106,113,119,125,131
,138,144,150,156,163,169,175,182,188,194,200
,207,213,219,225,232,238,244,250,257,263,269
,275,281,288,294,300,306,313,319,325,331,337
,344,350,356,362,368,374,381,387,393,399,405
,411,418,424,430,436,442,448,454,461,467,473
,479,485,491,497,503,509,515,521,528,534,540
,546,552,558,564,570,576,582,588,594,600,606
,612,618,624,630,636,642,648,654,660,665,671
,677,683,689,695,701,707,713,719,724,730,736
,742,748,754,759,765,771,777,783,788,794,800
,806,811,817,823,829,834,840,846,851,857,863
,869,874,880,885,891,897,902,908,914,919,925
,930,936,941,947,952,958,963,969,974,980,985
,991,996,1002,1007,1013,1018,1023,1029,1034,1040,1045
,1050,1056,1061,1066,1072,1077,1082,1088,1093,1098,1103
,1109,1114,1119,1124,1129,1135,1140,1145,1150,1155,1160
,1165,1171,1176,1181,1186,1191,1196,1201,1206,1211,1216
,1221,1226,1231,1236,1241,1246,1251,1256,1260,1265,1270
,1275,1280,1285,1289,1294,1299,1304,1309,1313,1318,1323
,1327,1332,1337,1342,1346,1351,1355,1360,1365,1369,1374
,1378,1383,1388,1392,1397,1401,1406,1410,1414,1419,1423
,1428,1432,1436,1441,1445,1450,1454,1458,1462,1467,1471
,1475,1480,1484,1488,1492,1496,1500,1505,1509,1513,1517
,1521,1525,1529,1533,1537,1541,1545,1549,1553,1557,1561
,1565,1569,1573,1577,1581,1584,1588,1592,1596,1600,1603
,1607,1611,1615,1618,1622,1626,1629,1633,1637,1640,1644
,1647,1651,1654,1658,1662,1665,1668,1672,1675,1679,1682
,1686,1689,1692,1696,1699,1702,1706,1709,1712,1715,1719
,1722,1725,1728,1731,1735,1738,1741,1744,1747,1750,1753
,1756,1759,1762,1765,1768,1771,1774,1777,1780,1782,1785
,1788,1791,1794,1796,1799,1802,1805,1807,1810,1813,1815
,1818,1821,1823,1826,1828,1831,1833,1836,1838,1841,1843
,1846,1848,1851,1853,1855,1858,1860,1862,1865,1867,1869
,1871,1874,1876,1878,1880,1882,1884,1886,1889,1891,1893
,1895,1897,1899,1901,1903,1904,1906,1908,1910,1912,1914
,1916,1918,1919,1921,1923,1925,1926,1928,1930,1931,1933
,1934,1936,1938,1939,1941,1942,1944,1945,1947,1948,1950
,1951,1952,1954,1955,1956,1958,1959,1960,1961,1963,1964
,1965,1966,1967,1969,1970,1971,1972,1973,1974,1975,1976
,1977,1978,1979,1980,1981,1981,1982,1983,1984,1985,1985
,1986,1987,1988,1988,1989,1990,1990,1991,1992,1992,1993
,1993,1994,1994,1995,1995,1996,1996,1997,1997,1997,1998
,1998,1998,1999,1999,1999,1999,2000,2000,2000,2000,2000
,2000,2000,2000,2000,2000,2000,2000};





int sin_t(int i){
	if(i<0) i+=2000;
	if(i>1999) i-=2000;
	
	
	if(i<1000){
		if(i<500){
		return sin_table[i];	
		}
		else{
		return sin_table[1000-i];	
		}
	}
	else{
		if(i<1500){
		return sin_table[i-1000]*(-1);	
		}
		else{
		return sin_table[2001-i]*(-1);	
		}
	}
	
	
	
}


int cos_t(int i){
	if(i<0) i+=2000;
	if(i>1999) i-=2000;
	
	
		if(i<1000){
		if(i<500){
			return sin_table[500-i];
		}
		else{
			return sin_table[i-500]*(-1);
		}
	}
	else{
		if(i<1500){
			return sin_table[1500-i]*(-1);
		}
		else{
			return sin_table[i-1499];
		}
	}
	

	
}


/****************************************************
function input: pixel accesslear

function output:

description:for better peformance i use an global varible for  change colour

notic:
*************************************************************/

unsigned char colour_change;
void pixel(int x,int y){
	y*=80;
	if(x%2){
		page_lcd[y+x/2]&=0xf;
		page_lcd[y+x/2]|=colour_change*16;
	}
	else{
		page_lcd[y+x/2]&=0xf0;
		page_lcd[y+x/2]|=colour_change;		
	}
}





/****************************************************
function input:        bar.val 
                      0<val<2000

function output:

description:

notic:
*************************************************************/
#define high_temp_color 10
#define low_temp_colour 12

#define start_circle_with 65
#define end_circle_with   76


#define x_change_locate   80
#define y_change_locate   80


void cicle(void){
  int gpv0,gpv1,gpv2,gpv3;
	int x,y;
	
	colour_change=high_temp_color;
	
	if(page_1_bar.value>page_1_bar_shodow.value){
		gpv0=page_1_bar_shodow.value;
		gpv1=page_1_bar.value;
	}
	else{
		gpv1=page_1_bar_shodow.value;
		gpv0=page_1_bar.value;
    colour_change=low_temp_colour;		
	}
	
	
	for(gpv2=start_circle_with;gpv2<end_circle_with;gpv2++){
	for(gpv3=gpv0;gpv3<gpv1;gpv3++){
		x=(gpv2*cos_t(gpv3-1500))/2000+x_change_locate;
		y=(gpv2*sin_t(gpv3-1500))/2000+y_change_locate;
		pixel(x,y);
	}
	}
}



/****************************************************
FUNCTION NAME:print an char on faurate postion

function input:x and y

function output:on screen

description:
cls_mode:depended to the size of function will be clear data

notic:
*************************************************************/
#define text_colour_code 5
#define back_colour_code 14

int draw_num_high_size_font(int x,int y,int num,int cls_mode_zero_active){
	int gpv0,gpv1,gpv2,gpv3,gpv4,gpv5;
	unsigned char gp0,gp1,gp2;
	gp1=exo_2[1]/8;
	gp2=exo_2[num+4];
	colour_change=back_colour_code;
	
	if(exo_2[1]%8){
	gp1=exo_2[1]/8+1;
	}
	else{
	gp1=exo_2[1]/8;	
	}	
	
	for(gp0=0,gpv1=0;gp0<num;gp0++){
	gp2=exo_2[gp0+4];	
	gpv1+=gp1*gp2;	
	}
	gpv1+=14;
	
	
	gp1=exo_2[1]/8;	
 	gp2=exo_2[num+4];
	
	for(gp0=0;gp0<gp1;gp0++){
	gpv4=x;	
	
	for(gpv0=0;gpv0<gp2;gpv0++){
	gpv5=y;
	gpv2=exo_2[gpv1++];	
	
	for(gpv3=1;gpv3<256;gpv3*=2){	
		
		if(cls_mode_zero_active){
		if(gpv2 & gpv3){
    colour_change=text_colour_code;
		}
    else{
    colour_change=back_colour_code;
		}
	  }
		
		pixel(gpv4,gpv5);
   gpv5++;		
	}

	gpv4++;
	}
	
	y+=8;	
	}
	
	
	if(exo_2[1]%8){
	gpv4=x;	
	for(gpv0=0;gpv0<gp2;gpv0++){
	gpv5=y;
	gpv2=exo_2[gpv1++];	
	
	for(gpv3=1;gpv3<256;gpv3*=2){	
		
		if(cls_mode_zero_active){
		if(gpv2 & gpv3){
    colour_change=text_colour_code;
		}
    else{
    colour_change=back_colour_code;
		}
	  }
		
		pixel(gpv4,gpv5);
   gpv5++;		
	}

	gpv4++;
	}	
	
	}

return gpv4;
}



/****************************************************
FUNCTION NAME: an complex function that uae upper layer function

function input:

function output:

description:

notic:
*************************************************************/




void print_power_factor(void){
int x,y;
y=56;	
	
if(page_1_bar_text_shodow.value<10){
x=64;	
draw_num_high_size_font(x,y,page_1_bar_text_shodow.value,0);
}
else{
if(page_1_bar_text_shodow.value==100){
x=35;
x=draw_num_high_size_font(x,y,1,0);
x=draw_num_high_size_font(x,y,0,0);
x=draw_num_high_size_font(x,y,0,0);	
}
else{
x=47;		
x=draw_num_high_size_font(x,y,page_1_bar_text_shodow.value/10,0);
x=draw_num_high_size_font(x,y,page_1_bar_text_shodow.value%10,0);	
}
}
	

page_1_bar_text_shodow.value=page_1_bar_text.value;


if(page_1_bar_text_shodow.value<10){
x=64;	
draw_num_high_size_font(x,y,page_1_bar_text_shodow.value,1);
}
else{
if(page_1_bar_text_shodow.value==100){
x=35;
x=draw_num_high_size_font(x,y,1,1);
x=draw_num_high_size_font(x,y,0,1);
x=draw_num_high_size_font(x,y,0,1);	
}
else{
x=47;		
x=draw_num_high_size_font(x,y,page_1_bar_text_shodow.value/10,1);
x=draw_num_high_size_font(x,y,page_1_bar_text_shodow.value%10,1);	
}
}


}


/****************************************************
FUNCTION NAME:page 0 timer value monitor

function input:

function output:

description:
desined for showing two number
notic:
*************************************************************/

unsigned char *pointer_page_0_timer_monitor;
#define draw_colour_page0_time  12
#define back_colour_page0_time  14


void pixel_text_func_page_0(int x,int y){
	y*=28;
	if(x%2){
		page_lcd_2[y+x/2]&=0xf;
		page_lcd_2[y+x/2]|=colour_change*16;
	}
	else{
		page_lcd_2[y+x/2]&=0xf0;
		page_lcd_2[y+x/2]|=colour_change;		
	}
}


int page_0_print_a_number(int num,int x,int y){
	unsigned char gp0,gp1,gp2,gp3;
	int gpv0,gpv1,gpv2;
	int xf,yf;
	gp0=franklin_gothic_demi[1]/8;
	gp1=franklin_gothic_demi[0];
	
	if(franklin_gothic_demi[1]%8){
		gpv0=num*gp1*(gp0+1)+4;
	}
	else{
		gpv0=num*gp1*gp0+4;		
	}
	
	
	for(gp2=0;gp2<gp0;gp2++){
		xf=x;		
		for(gp3=0;gp3<gp1;gp3++){
		gpv1=franklin_gothic_demi[gpv0++];
		yf=y;
		for(gpv2=1;gpv2<256;gpv2*=2){
		if(gpv1 & gpv2) colour_change=draw_colour_page0_time;	
		else            colour_change=back_colour_page0_time;	
    pixel_text_func_page_0(xf,yf++);
		}			
		xf++;	
		}
		y+=8;
	}
	
  if(franklin_gothic_demi[1]%8){
		xf=x;		
		for(gp3=0;gp3<gp1;gp3++){
		gpv1=franklin_gothic_demi[gpv0++];
		yf=y;
		for(gpv2=1;gpv2<256;gpv2*=2){
		if(gpv1 & gpv2) colour_change=draw_colour_page0_time;	
		else            colour_change=back_colour_page0_time;	
    pixel_text_func_page_0(xf,yf++);
		}			
		xf++;	
		}				
	}
	
	return xf;
}




void install_page_0_time_bar(void){
	//pointer_page_0_timer_monitor=(unsigned char *)(page_lcd +14800);
}


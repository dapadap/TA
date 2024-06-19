/* VERSI 1
0000    kondisi mati
0001    lampu grup1 menyala
0010    lampu grup2 menyala
0011    lampu grup1 mati
0100    lmapu grup2 mati
0101    humidifier grup1 menyala
0110    humidifier grup2 menyala
0111    humidifier grup1 mati
1000    humidifier grup2 mati
1001    fan grup1 menyala
1010    fan grup2 menyala
1011    fan grup1 mati
1100    fan grup2 mati
*/
/*
versi 1
void mati(){
  digitalWrite(relay1,0);digitalWrite(relay2,0);digitalWrite(relay3,0);digitalWrite(relay4,0);
}

void lampu1_on(){
   digitalWrite(relay1,0);digitalWrite(relay2,0);digitalWrite(relay3,0);digitalWrite(relay4,1);
   //lcd.setCursor(1,0);lcd.print("L1N");
}

void lampu2_on(){
   digitalWrite(relay1,0);digitalWrite(relay2,0);digitalWrite(relay3,1);digitalWrite(relay4,0);
   //lcd.setCursor(1,0);lcd.print("L2N");
}

void lampu1_off(){
   digitalWrite(relay1,0);digitalWrite(relay2,0);digitalWrite(relay3,1);digitalWrite(relay4,1);
   //lcd.setCursor(1,0);lcd.print("L1F");
}

void lampu2_off(){
   digitalWrite(relay1,0);digitalWrite(relay2,1);digitalWrite(relay3,0);digitalWrite(relay4,0);
   //lcd.setCursor(1,0);lcd.print("L2F");
}

void humidifier1_on(){
   digitalWrite(relay1,0);digitalWrite(relay2,1);digitalWrite(relay3,0);digitalWrite(relay4,1);
   //lcd.setCursor(1,0);lcd.print("H1N");
}

void humidifier2_on(){
   digitalWrite(relay1,0);digitalWrite(relay2,1);digitalWrite(relay3,1);digitalWrite(relay4,0);
  // lcd.setCursor(1,0);lcd.print("H2N");
}

void humidifier1_off(){
   digitalWrite(relay1,0);digitalWrite(relay2,1);digitalWrite(relay3,1);digitalWrite(relay4,1);
   //lcd.setCursor(1,0);lcd.print("H1F");
}

void humidifier2_off(){
   digitalWrite(relay1,1);digitalWrite(relay2,0);digitalWrite(relay3,0);digitalWrite(relay4,0);
   //lcd.setCursor(1,0);lcd.print("H2F");
}

void fan1_on(){
   digitalWrite(relay1,1);digitalWrite(relay2,0);digitalWrite(relay3,0);digitalWrite(relay4,1);
   //lcd.setCursor(1,0);lcd.print("F1N");
}

void fan2_on(){
   digitalWrite(relay1,1);digitalWrite(relay2,0);digitalWrite(relay3,1);digitalWrite(relay4,0);
   //lcd.setCursor(1,0);lcd.print("F2N");
}

void fan1_off(){
   digitalWrite(relay1,1);digitalWrite(relay2,0);digitalWrite(relay3,1);digitalWrite(relay4,1);
   //lcd.setCursor(1,0);lcd.print("F1F");
}

void fan2_off(){
   digitalWrite(relay1,1);digitalWrite(relay2,1);digitalWrite(relay3,0);digitalWrite(relay4,0);
   //lcd.setCursor(1,0);lcd.print("F2F");
}
*/
/*
VERSI2
0000    kondisi mati
0001    L1AN L1BN 12AN L2BN
0010    L1AF L1BN 12AN L2BN
0011    L1AN L1BF 12AN L2BN
0100    L1AF L1BF 12AN L2BN
0101    L1AF L1BF L2AF L2BF
0110    LIAF L1BF L2BF L2BN
0111    LIAF L1BF L2BN L2BF
1000    fan 1 off
1001    fan 2 off
1010    humidifier 1 on
1011    humidifier 2 on
1100    humidifier 2 off
1101    humidifier 2 off
1110
1111

*/
void mati(){
digitalWrite(relay1,0);digitalWrite(relay2,0);digitalWrite(relay3,0);digitalWrite(relay4,0);
}

void mode1(){
digitalWrite(relay1,0);digitalWrite(relay2,0);digitalWrite(relay3,0);digitalWrite(relay4,1);
}

void mode2(){
digitalWrite(relay1,0);digitalWrite(relay2,0);digitalWrite(relay3,1);digitalWrite(relay4,0);
}

void mode3(){
digitalWrite(relay1,0);digitalWrite(relay2,0);digitalWrite(relay3,1);digitalWrite(relay4,1);
}

void mode4(){
digitalWrite(relay1,0);digitalWrite(relay2,1);digitalWrite(relay3,0);digitalWrite(relay4,0);
}

void mode5(){
digitalWrite(relay1,0);digitalWrite(relay2,1);digitalWrite(relay3,0);digitalWrite(relay4,1);
}

void mode6(){
digitalWrite(relay1,0);digitalWrite(relay2,1);digitalWrite(relay3,1);digitalWrite(relay4,0);  
}

void mode7(){
digitalWrite(relay1,0);digitalWrite(relay2,1);digitalWrite(relay3,1);digitalWrite(relay4,1);  
}

void fan1_off(){
digitalWrite(relay1,1);digitalWrite(relay2,0);digitalWrite(relay3,0);digitalWrite(relay4,0);  
}

void fan2_off(){
digitalWrite(relay1,0);digitalWrite(relay2,0);digitalWrite(relay3,0);digitalWrite(relay4,1);  
}

void humidifier1_on(){
digitalWrite(relay1,1);digitalWrite(relay2,0);digitalWrite(relay3,1);digitalWrite(relay4,0);  
}

void humidifier2_on(){
digitalWrite(relay1,1);digitalWrite(relay2,0);digitalWrite(relay3,1);digitalWrite(relay4,1);  
}

void humidifier1_off(){
digitalWrite(relay1,1);digitalWrite(relay2,1);digitalWrite(relay3,0);digitalWrite(relay4,0);  
}

void humidifier2_off(){
digitalWrite(relay1,1);digitalWrite(relay2,1);digitalWrite(relay3,0);digitalWrite(relay4,1);  
}

void baca_sensor()
{
  for (int i = 0; i < 4; i++) {
    t[i] = dht[i].readTemperature();
    h[i] = dht[i].readHumidity();
  }

  for (int i = 0; i < 4; i++) {
   /* Serial.print(F("Temperature "));
    Serial.print(i);
    Serial.println(t[i]);
    Serial.print(F("Humidity "));
    Serial.print(i);
   *///Serial.println(h[i]);
  }
  t_B1 = (t[0]+t[1])/2;
  t_B2 = (t[2]+t[3])/2;
  h_B1 = (h[0]+h[1])/2;
  h_B2 = (h[2]+h[3])/2;

 delay(50);

 if(digitalRead(next)==LOW){
  nilai_sensor++;
  delay(50);
 }if(nilai_sensor==10){
  nilai_sensor=0;
 }

 switch(nilai_sensor){
 case 0:
 lcd.setCursor(1,0);lcd.print("Pembacaan Sensor");
 lcd.setCursor(18,0);lcd.print(nilai_sensor+1);
 lcd.setCursor(1,1);lcd.print("                    ");
 lcd.setCursor(1,2);lcd.print("Suhu     : ");lcd.print(t[0]);lcd.print("C");
 lcd.setCursor(1,3);lcd.print("Klmbaban : ");lcd.print(h[0]);lcd.print("%");
 break;

 case 1:
 lcd.setCursor(1,0);lcd.print("Pembacaan Sensor");
 lcd.setCursor(18,0);lcd.print(nilai_sensor+1);
 lcd.setCursor(1,1);lcd.print("                    ");
 lcd.setCursor(1,2);lcd.print("Suhu     : ");lcd.print(t[1]);lcd.print("C");
 lcd.setCursor(1,3);lcd.print("Klmbaban : ");lcd.print(h[1]);lcd.print("%");
 break;

 case 2:
 lcd.setCursor(1,0);lcd.print("Pembacaan Sensor");
 lcd.setCursor(18,0);lcd.print(nilai_sensor+1);
 lcd.setCursor(1,1);lcd.print("                    ");
 lcd.setCursor(1,2);lcd.print("Suhu     : ");lcd.print(t[2]);lcd.print("C");
 lcd.setCursor(1,3);lcd.print("Klmbaban : ");lcd.print(h[2]);lcd.print("%");
 break;

 case 3:
 lcd.setCursor(1,0);lcd.print("Pembacaan Sensor");
 lcd.setCursor(18,0);lcd.print(nilai_sensor+1);
 lcd.setCursor(1,1);lcd.print("                    ");
 lcd.setCursor(1,2);lcd.print("Suhu     : ");lcd.print(t[3]);lcd.print("C");
 lcd.setCursor(1,3);lcd.print("Klmbaban : ");lcd.print(h[3]);lcd.print("%");
 break;
 
 case 4:
 lcd.setCursor(0,0);lcd.print("        PLTS        ");
 lcd.setCursor(1,1);lcd.print("V : ");lcd.print(voltage1);lcd.print("V       ");
 lcd.setCursor(1,2);lcd.print("I : ");lcd.print(current1);lcd.print("A        ");
 lcd.setCursor(1,3);lcd.print("P : ");lcd.print(power1);lcd.print("Watt      ");
 break;

 case 5:
 lcd.setCursor(0,0);lcd.print("        PLTS        ");
 lcd.setCursor(1,1);lcd.print("E : ");lcd.print(energy1);lcd.print("kWh      ");
 lcd.setCursor(1,2);lcd.print("F : ");lcd.print(frequency1);lcd.print("Hz      ");
 lcd.setCursor(1,3);lcd.print("pF : ");lcd.print(pf1);lcd.print("              ");
 break;
 
 case 6:
 lcd.setCursor(0,0);lcd.print("         PLN         ");
 lcd.setCursor(1,1);lcd.print("V : ");lcd.print(voltage2);lcd.print("V       ");
 lcd.setCursor(1,2);lcd.print("I : ");lcd.print(current2);lcd.print("A         ");
 lcd.setCursor(1,3);lcd.print("P : ");lcd.print(power2);lcd.print("Watt");
 break;

 case 7:
 lcd.setCursor(0,0);lcd.print("         PLN        ");
 lcd.setCursor(1,1);lcd.print("E : ");lcd.print(energy2);lcd.print("kWh");
 lcd.setCursor(1,2);lcd.print("F : ");lcd.print(frequency2);lcd.print("Hz        ");
 lcd.setCursor(1,3);lcd.print("pF : ");lcd.print(pf2);lcd.print("          ");
 break;

 case 8:
 lcd.setCursor(1,0);lcd.print("Pembacaan Sensor B1");
 //lcd.setCursor(18,0);lcd.print(nilai_sensor+1);
 lcd.setCursor(1,1);lcd.print("                    ");
 lcd.setCursor(1,2);lcd.print("Suhu     : ");lcd.print((t[0]+t[1])/2);lcd.print("C");
 lcd.setCursor(1,3);lcd.print("Klmbaban : ");lcd.print((h[0]+h[1])/2);lcd.print("%");
 break;

 case 9:
 lcd.setCursor(1,0);lcd.print("Pembacaan Sensor B2");
 //lcd.setCursor(18,0);lcd.print(nilai_sensor+1);
 lcd.setCursor(1,1);lcd.print("                    ");
 lcd.setCursor(1,2);lcd.print("Suhu     : ");lcd.print((t[2]+t[3])/2);lcd.print("C");
 lcd.setCursor(1,3);lcd.print("Klmbaban : ");lcd.print((h[2]+h[3])/2);lcd.print("%");
 break;
/*
 case 4:
 lcd.setCursor(0,0);lcd.print("        PLN         ");
 lcd.setCursor(1,1);lcd.print("V : ");lcd.print(pzems[1].voltage());lcd.print("V       ");
 lcd.setCursor(1,2);lcd.print("I : ");lcd.print(pzems[1].current());lcd.print("A       ");
 lcd.setCursor(1,3);lcd.print("P : ");lcd.print(pzems[2].power());lcd.print("Watt      ");
 break;
*/
 }

}

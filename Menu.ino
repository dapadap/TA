void menu(){
if(digitalRead(sett)==LOW){
opsi++;
delay(100);
}if(digitalRead(avai1)==LOW){
opsi--;
delay(100);
}if(opsi==8){
  opsi=1;
}

switch(opsi){
  case 1:
  lcd2.setCursor(16,1);lcd2.print("Set");
  lcd2.setCursor(15,2);lcd2.print("Point");
  lcd2.setCursor(1,0);lcd2.print("t_max : ");lcd2.print(t_set_max);lcd2.print("C");
  lcd2.setCursor(1,1);lcd2.print("t_min : ");lcd2.print(t_set_min);lcd2.print("C");
  lcd2.setCursor(1,2);lcd2.print("h_max : ");lcd2.print(h_set_max);lcd2.print("%");
  lcd2.setCursor(1,3);lcd2.print("h_min : ");lcd2.print(h_set_min);lcd2.print("%");
  lcd2.setCursor(13,3); lcd2.print(" ");
  lcd2.setCursor(13,0); lcd2.print("<");
  if(digitalRead(up)==LOW){
    t_set_max++;
    EEPROM.write(1,t_set_max);
    delay(100);
  }
    if(digitalRead(down)==LOW){
    t_set_max--;
    EEPROM.write(1,t_set_max);
    delay(100);
  }
  break;

  case 2:
  lcd2.setCursor(16,1);lcd2.print("Set");
  lcd2.setCursor(15,2);lcd2.print("Point");
  lcd2.setCursor(1,0);lcd2.print("t_max : ");lcd2.print(t_set_max);lcd2.print("C");
  lcd2.setCursor(1,1);lcd2.print("t_min : ");lcd2.print(t_set_min);lcd2.print("C");
  lcd2.setCursor(1,2);lcd2.print("h_max : ");lcd2.print(h_set_max);lcd2.print("%");
  lcd2.setCursor(1,3);lcd2.print("h_min : ");lcd2.print(h_set_min);lcd2.print("%");  
  lcd2.setCursor(13,0); lcd2.print(" ");
  lcd2.setCursor(13,1); lcd2.print("<");
    if(digitalRead(up)==LOW){
    t_set_min++;
    EEPROM.write(2,t_set_min);
    delay(100);
  }
    if(digitalRead(down)==LOW){
    t_set_min--;
    EEPROM.write(2,t_set_min);
    delay(100);
  }
  break;

  case 3:
  lcd2.setCursor(16,1);lcd2.print("Set");
  lcd2.setCursor(15,2);lcd2.print("Point");
  lcd2.setCursor(1,0);lcd2.print("t_max : ");lcd2.print(t_set_max);lcd2.print("C");
  lcd2.setCursor(1,1);lcd2.print("t_min : ");lcd2.print(t_set_min);lcd2.print("C");
  lcd2.setCursor(1,2);lcd2.print("h_max : ");lcd2.print(h_set_max);lcd2.print("%");
  lcd2.setCursor(1,3);lcd2.print("h_min : ");lcd2.print(h_set_min);lcd2.print("%");
  lcd2.setCursor(13,1); lcd2.print(" ");
  lcd2.setCursor(13,2); lcd2.print("<");
    if(digitalRead(up)==LOW){
    h_set_max++;
    EEPROM.write(3,h_set_max);
    delay(100);
  }
    if(digitalRead(down)==LOW){
    h_set_max--;
    EEPROM.write(3,h_set_max);
    delay(100);
  }
  break;

  case 4:
  lcd2.setCursor(16,1);lcd2.print("Set");
  lcd2.setCursor(15,2);lcd2.print("Point");
  lcd2.setCursor(1,0);lcd2.print("t_max : ");lcd2.print(t_set_max);lcd2.print("C");
  lcd2.setCursor(1,1);lcd2.print("t_min : ");lcd2.print(t_set_min);lcd2.print("C");
  lcd2.setCursor(1,2);lcd2.print("h_max : ");lcd2.print(h_set_max);lcd2.print("%");
  lcd2.setCursor(1,3);lcd2.print("h_min : ");lcd2.print(h_set_min);lcd2.print("%");
  lcd2.setCursor(13,3); lcd2.print("<");
  lcd2.setCursor(13,2); lcd2.print(" ");
    if(digitalRead(up)==LOW){
    h_set_min++;
    EEPROM.write(4,h_set_min);
    delay(50);
  }
    if(digitalRead(down)==LOW){
    h_set_min--;
    EEPROM.write(4,h_set_min);
    delay(50);
  }
  break;

  case 5:
  lcd2.setCursor(1,0);lcd2.print("Day      : ");lcd2.print(day);
  lcd2.setCursor(1,1);lcd2.print(jam);lcd2.print(":");lcd2.print(menit);lcd2.print(":");lcd2.print(detik);lcd2.print(" ");
  lcd2.print(tanggal);lcd2.print("/");lcd2.print(bulan);lcd2.print("/");lcd2.print(tahun);lcd2.print("");
  lcd2.setCursor(1,2);lcd2.print("Set Day  : ");lcd2.print(set_day);lcd2.print("       ");
  lcd2.setCursor(1,3);lcd2.print("Set Clock: ");lcd2.print(set_hour);lcd2.print(":");lcd2.print(set_minute);

    if(digitalRead(up)==LOW){
    set_day++;
    EEPROM.write(5,set_day);
    delay(50);
  }
    if(digitalRead(down)==LOW){
    EEPROM.write(5,set_day);
    set_day--;
    delay(50);
  }
  break;

  case 6:
  lcd2.setCursor(1,0);lcd2.print("Day      : ");lcd2.print(day);
  lcd2.setCursor(1,1);lcd2.print(jam);lcd2.print(":");lcd2.print(menit);lcd2.print(":");lcd2.print(detik);lcd2.print(" ");
  lcd2.print(tanggal);lcd2.print("/");lcd2.print(bulan);lcd2.print("/");lcd2.print(tahun);lcd2.print("");
  lcd2.setCursor(1,2);lcd2.print("Set Day  : ");lcd2.print(set_day);lcd2.print("       ");
  lcd2.setCursor(1,3);lcd2.print("Set Clock: ");lcd2.print(set_hour);lcd2.print(":");lcd2.print(set_minute);

    if(digitalRead(up)==LOW){
    set_hour++;
    EEPROM.write(6,set_hour);
    delay(50);
  }
    if(digitalRead(down)==LOW){
    set_hour--;
    EEPROM.write(6,set_hour);
    delay(50);
  }
  break;

  case 7:
  lcd2.setCursor(1,0);lcd2.print("Day      : ");lcd2.print(day);
  lcd2.setCursor(1,1);lcd2.print(jam);lcd2.print(":");lcd2.print(menit);lcd2.print(":");lcd2.print(detik);lcd2.print(" ");
  lcd2.print(tanggal);lcd2.print("/");lcd2.print(bulan);lcd2.print("/");lcd2.print(tahun);lcd2.print("");
  lcd2.setCursor(1,2);lcd2.print("Set Day  : ");lcd2.print(set_day);lcd2.print("       ");
  lcd2.setCursor(1,3);lcd2.print("Set Clock: ");lcd2.print(set_hour);lcd2.print(":");lcd2.print(set_minute);

    if(digitalRead(up)==LOW){
    set_minute++;
    EEPROM.write(7,set_minute);
    delay(50);
  }
    if(digitalRead(down)==LOW){
    set_minute--;
    EEPROM.write(7,set_minute);
    delay(50);
  }
  break;
  

}

}

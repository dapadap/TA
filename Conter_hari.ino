void Conter_hari() {
  int count_bts=0;
  if(/*jam==23.59&&menit==59&&*/detik==59&&count_bts==0){
    day++;
    EEPROM.write(8,day);
    count_bts=1;
    delay(50);
  }else{
    count_bts=0;
  }
}
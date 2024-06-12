void kirim_data() {
  // put your main code here, to run repeatedly:
//Serial2.print("#220#polines#dapa#abc#1234#$");
waktu_sekarang = millis();
if(waktu_sekarang-waktu_sebelum>=5000){
status = !status;
if(status){
Serial.println("kirim");
//Serial2.println("#2 ampare#38,5#sha#123#220 kwH");  
 Serial2.print("@");
 Serial2.print(t_set_max);Serial2.print("@");
 Serial2.print(t_set_min);Serial2.print("@");
 Serial2.print(h_set_max);Serial2.print("@");
 Serial2.print(h_set_min);Serial2.print("@");
 Serial2.print(t[0]);Serial2.print("@");
 Serial2.print(h[0]);Serial2.print("@");
 Serial2.print(t[1]);Serial2.print("@");
 Serial2.print(h[1]);Serial2.print("@");
 Serial2.print(t[2]);Serial2.print("@");
 Serial2.print(h[2]);Serial2.print("@");
 Serial2.print(t[3]);Serial2.print("@");   
 Serial2.print(h[3]);Serial2.print("@");
 Serial2.print(voltage1);Serial2.print("@");
 Serial2.print(current1);Serial2.print("@");
 Serial2.print(power1);Serial2.print("@");
 Serial2.print(energy1);Serial2.print("@");
 Serial2.print(frequency1);Serial2.print("@");
 Serial2.print(pf1);Serial2.print("@");
 Serial2.print(voltage2);Serial2.print("@");
 Serial2.print(current2);Serial2.print("@");
 Serial2.print(power2);Serial2.print("@");
 Serial2.print(energy2);Serial2.print("@");
 Serial2.print(frequency2);Serial2.print("@");
 Serial2.print(pf2);
 
}else{

}
waktu_sebelum=waktu_sekarang;
}

/*
Serial2.println("#2 ampare#38,5#sha#123#220 kwH");
delay(2000);*/

}
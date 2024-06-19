void kirim_data() {
  // put your main code here, to run repeatedly:
//Serial2.print("#220#polines#dapa#abc#1234#$");
waktu_sekarang = millis();
if(waktu_sekarang-waktu_sebelum>=5000){
status = !status;
if(status){
//Serial.println("kirim");
 Serial2.print("@");
 Serial2.print(t_set_max);Serial2.print("@");//1
 Serial2.print(t_set_min);Serial2.print("@");//2
 Serial2.print(h_set_max);Serial2.print("@");//3
 Serial2.print(h_set_min);Serial2.print("@");//4
 Serial2.print((t[0]+t[1])/2);Serial2.print("@");//5
 Serial2.print((h[0]+h[1])/2);Serial2.print("@");//6
 Serial2.print((t[2]+t[3])/2);Serial2.print("@");//7
 Serial2.print((h[2]+h[3])/2);Serial2.print("@");//8/
 Serial2.print(day);Serial2.print("@");//9
 Serial2.print(set_day);Serial2.print("@");//10
 Serial2.print(set_hour);Serial2.print("@");//11   
 Serial2.print(set_minute);Serial2.print("@");//12
 Serial2.print(voltage1);Serial2.print("@");//13
 Serial2.print(current1);Serial2.print("@");//14
 Serial2.print(energy1);Serial2.print("@");//15
 Serial2.print(voltage2);Serial2.print("@");  //16
 Serial2.print(current2);Serial2.print("@");//17
 Serial2.print(energy2);Serial2.print("@");//18
 Serial2.print(day);Serial2.print("@");//19

 
}else{

}
waktu_sebelum=waktu_sekarang;
}

/*
Serial2.println("#2 ampare#38,5#sha#123#220 kwH");
delay(2000);*/

}

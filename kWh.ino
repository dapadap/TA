void kWh(){
 float vol;
   // for(int i = 0; i < NUM_PZEMS; i++){
        //Print the Address of the PZEM
/*       lcd2.setCursor(0,0);
        lcd2.print("PZEM ");
        lcd2.print("1");
        lcd2.print("Adrs:");
        lcd2.println(pzems[0].getAddress(), HEX);
        //Serial.println("===================");
        lcd2.setCursor(1,1);
        lcd2.print("PZEM ");
        lcd2.print("2");
        lcd2.print("Adrs:");
        lcd2.println(pzems[1].getAddress(), HEX);
*/

     if(isnan(pzems[0].voltage())){
  //          Serial.println("Error reading voltage");
        }else{
          voltage1 = pzems[0].voltage();
          current1 = pzems[0].current();
          power1 = pzems[0].power();
          energy1 = pzems[0].energy();
          frequency1 = pzems[0].frequency();
          pf1 = pzems[0].pf();         
        }

        if(isnan(pzems[1].voltage())){
    //        Serial.println("Error reading voltage");
        }else{
        // Read the data from the sensor
        voltage2 = pzems[1].voltage();
        current2 = pzems[1].current();
        power2 = pzems[1].power();
        energy2 = pzems[1].energy();
        frequency2 = pzems[1].frequency();
        pf2 = pzems[1].pf();     
        }
}
  
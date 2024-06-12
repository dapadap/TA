#include <DHT.h>
#include <PZEM004Tv30.h>

#include "RTClib.h"
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Ahad", "Senin", "Selasa", "Rabu", "Kamis", "Jum'at", "Sabtu"};
int jam, menit, detik;
int tanggal, bulan, tahun;
String hari;

int set_day;
int set_hour;
int set_minute;

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
LiquidCrystal_I2C lcd2(0x21, 20, 4);
#define up 36
#define down 39
#define sett 34
#define next 35
#define avai1 32
#define avai2 33
int opsi = 1;
int nilai_sensor=0;

#define relay1 25
#define relay2 26
#define relay3 27
#define relay4 14


int t_set_max = 41;
int t_set_min = 39;
int h_set_max = 70;
int h_set_min = 50;

#define DHTPIN1 13
#define DHTPIN2 5
#define DHTPIN3 18 
#define DHTPIN4 19 
#define DHTTYPE DHT22

DHT dht[] = {
  {DHTPIN1, DHT22},
  {DHTPIN2, DHT22},
  {DHTPIN3, DHT22},
  {DHTPIN4, DHT22},
};

float t[4];
float h[4];


#if !defined(PZEM_RX_PIN) && !defined(PZEM_TX_PIN)
#define PZEM_RX_PIN 3
#define PZEM_TX_PIN 1
#endif

#if !defined(PZEM_SERIAL)
#define PZEM_SERIAL Serial
#endif

#define NUM_PZEMS 2

PZEM004Tv30 pzems[NUM_PZEMS];

//#define USE_SOFTWARE_SERIAL



#if defined(USE_SOFTWARE_SERIAL) && defined(ESP32)
    #error "Can not use SoftwareSerial with ESP32"
#elif defined(USE_SOFTWARE_SERIAL)

#include <SoftwareSerial.h>

SoftwareSerial pzemSWSerial(PZEM_RX_PIN, PZEM_TX_PIN);
#endif

float voltage1;
float current1;
float power1;
float energy1;
float frequency1;
float pf1;
float voltage2;
float current2;
float power2;
float energy2;
float frequency2;
float pf2;

unsigned long waktu_sekarang;
unsigned long waktu_sebelum;
bool status=true;


void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);

  //dht
  for (int i = 0; i < 4; i++) {
   dht[i].begin();
  }

  //rtc 
  if (! rtc.begin()) {
    Serial.println("RTC tidak terbaca");
    while (1);
  }
  if (rtc.lostPower()) {
    //atur waktu sesuai waktu pada komputer
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    //atur waktu secara manual
    // January 21, 2019 jam 10:30:00
    // rtc.adjust(DateTime(2019, 1, 25, 10, 30, 0));
  }

  //PZEM KWH
      for(int i = 0; i < NUM_PZEMS; i++)
    {

#if defined(USE_SOFTWARE_SERIAL)
        pzems[i] = PZEM004Tv30(pzemSWSerial, 0x5 + i);
#elif defined(ESP32)
        pzems[i] = PZEM004Tv30(PZEM_SERIAL, PZEM_RX_PIN, PZEM_TX_PIN, 0x5 + i);
#else
        pzems[i] = PZEM004Tv30(PZEM_SERIAL, 0x5 + i);
#endif
    }

  //input
  pinMode(up,INPUT_PULLUP);
  pinMode(down,INPUT_PULLUP);
  pinMode(sett,INPUT_PULLUP);
  pinMode(next,INPUT_PULLUP);
  pinMode(avai1,INPUT_PULLUP); //button fan 1
  pinMode(avai2,INPUT_PULLUP);

  //output
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relay3,OUTPUT);
  pinMode(relay4,OUTPUT);

  lcd.init();lcd.backlight();
  lcd2.init();lcd2.backlight();
  lcd.setCursor(1,0);lcd.print("Daffa Fajar S");
  lcd.setCursor(1,1);lcd.print("Hanna Yasmin EFAQ");
  lcd.setCursor(1,2);lcd.print("Trisna Mega F");
  lcd.setCursor(1,3);lcd.print("Yefi Wahyu P");
  lcd2.setCursor(3,0);lcd2.print("TUGAS AKHIR");
  lcd2.setCursor(3,1);lcd2.print("  POLINES  ");
  lcd2.setCursor(3,2);lcd2.print("Crevotech.id");
  delay(3000);
  lcd.clear(); lcd2.clear(); 
}

void loop() {
 delay(10);
 // waktu();
 kWh();
 baca_sensor();
 menu();

 kirim_data();

if(t[0]<t_set_min&&t[1]<t_set_min&&t[2]<t_set_min&&t[3]<t_set_min){
  mode1();
}else if ((t[0]>t_set_min||t[1]>t_set_min)&&t[2]<t_set_min&&t[3]<t_set_min){
 mode2();
}else if (t[0]<t_set_min&&t[1]<t_set_min&&(t[2]>t_set_min||t[3]>t_set_min)){
  mode3();
}else if((t[0]>t_set_max&&t[1]>t_set_max)&&(t[2]>t_set_max&&t[3]>t_set_max)){
  mode5();
}else if((t[0]>t_set_min&&t[1]>t_set_min)&&(t[2]>t_set_min&&t[3]>t_set_min)){
  //mode4();
}else if((t[0]>t_set_min||t[1]>t_set_min)&&(t[2]>t_set_min||t[3]>t_set_min)){
  mode4();
}
 
/*
//---------------LAMPU----------------//
 if(t[0]>t_set_max && t[1]>t_set_max ){
  lampu1_off();
 }else if(t[0]<t_set_min || t[1]<t_set_min){
  lampu1_on();
 }

 if(t[2]>t_set_max && t[3]>t_set_max ){
  lampu2_off();
 }else if(t[2]<t_set_min || t[3]<t_set_min ){
  lampu2_on();
 }
*/
//------------HUMIDIFIER-------------//
//---------------FAN----------------//

 }  
  



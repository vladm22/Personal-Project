
//******************* Declaration des Librairies ***********************//
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>

//******************* Declaration pins pour RFID ***********************//
#define RST_PIN     9
#define SS_PIN      10
//Créez une instance de la bibliothèque MFRC522
MFRC522 mfrc522(SS_PIN, RST_PIN);

//******************* Declaration pins pour OLED ***********************//
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//******************* Declaration pins LED et Buzzer *******************//
#define LED_GREEN_PIN 7
#define LED_RED_PIN 6
#define BUZZER_PIN 5
#define WAVE_BUZZER 100


//******************* Declaration USB vers prossessing *****************//
const int txPin = 1;  // Broche de transmission
const int rxPin = 0;  // Broche de réception
SoftwareSerial mySerial(rxPin, txPin);


//******************* Declaration variables globales *******************//
int New_Id_State = 0;
int Index_DataBase = 0;
int Id_Recognized = 0;
String Card_ID = "";
String inputString = "";
String ID_Read = "";
String Name_Read = "";
volatile bool newData = false;
int Data_Stock = 0;


//******************* Declaration des Sous-programmes ******************//
void Update_State_LED_GREEN();
void Update_State_LED_RED();
void Start_Buzzer();
void Update_Display();
void Scan_RFID();
void State_Machine();


//******************************** SETUP *******************************//
void setup() 
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Attacher l'interruption à la fonction interruptFunction lorsque des données sont disponibles
  mySerial.begin(9600);
  digitalWrite(LED_GREEN_PIN, LOW);
  digitalWrite(LED_RED_PIN, LOW);
  Start_Buzzer();
  delay(1000);
}

//******************************** LOOP *******************************//
void loop() 
{
  Scan_RFID();
  State_Machine();
  
  if (mySerial.available() > 0) 
  {
    if(Data_Stock == 0)
    {
      Name_Read = Serial.readStringUntil('\n');
      Name_Read.trim();  // Supprimer les espaces éventuels

      if(Name_Read == "" || Name_Read == " ")
      {
        Data_Stock = 0;
      }
      else
      {
        Data_Stock = 1;
      }
    }
    else
    {
      ID_Read = Serial.readStringUntil('\n');
      ID_Read.trim();  // Supprimer les espaces éventuels

      if(ID_Read == "" || ID_Read == " ")
      {
        Data_Stock = 0;
      }
      else
      {
        Data_Stock = 2;
      }
    }
  }
}

//***************************** Scan_RFID *****************************//
void Scan_RFID()
{
  Card_ID = "";

  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) 
  {
    for (byte i = 0; i < mfrc522.uid.size; i++) 
    {
      Card_ID.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
  }

  delay(100);
}


//*************************** State_Machine ***************************//
void State_Machine()
{
  if(Card_ID == "")
  {
  }
  else
  {
    Serial.println(Card_ID);

    Start_Buzzer();
  }

  if (Data_Stock == 2) 
  {
    if(Name_Read == "0")
    {
      Update_State_LED_RED();
    }
    else
    {
      Update_State_LED_GREEN();
    }

    // Réinitialiser 
    Data_Stock = 0;
    ID_Read = "";
    Name_Read = "";
  }

  Update_Display();
} 

//***************************  DEVICES ***************************//
void Update_State_LED_GREEN()
{
  digitalWrite(LED_GREEN_PIN, HIGH);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(47,0);
  display.println("ECE");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,30);
  display.print("ID : ");
  display.println(ID_Read);
  display.setCursor(0,40);
  display.print("Name : ");
  display.println(Name_Read);
  display.display();
  delay(2000);
  digitalWrite(LED_GREEN_PIN, LOW);
}

void Update_State_LED_RED()
{
  digitalWrite(LED_RED_PIN, HIGH);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(47,0);
  display.println("ECE");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,30);
  display.println("ID : Not Recognized");
  display.setCursor(10,40);
  display.println("Or already used");
  display.display();
  delay(2000);
  digitalWrite(LED_RED_PIN, LOW);
}

void Start_Buzzer()
{
  digitalWrite (BUZZER_PIN, HIGH);
  delay (WAVE_BUZZER);
  digitalWrite (BUZZER_PIN, LOW);
}

void Update_Display()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(47,0);
  display.println("ECE");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,30);
  display.print("ID : ");
  display.println("____________");
  display.setCursor(0,40);
  display.print("Name : ");
  display.println("__________");
  display.display();
}


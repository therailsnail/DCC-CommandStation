// Bluetooth setup sketch (Arduino Mega version). Version 1.2 - 27th Dec 2021
//
// Serial UART 3 (at 38400 BAUD) is used for communication with the Bluetooth module.
// USB Serial (at 9600 BAUD) connects to the computer
  
void setup() 
{
    // Mega USB port communication set to 9600 BAUD 
    Serial.begin(9600);
    delay(500); 
  
    Serial.println("Arduino Mega 2560/HC-05 Simple Bluetooth Terminal/DCC++ Setup - 231221");
    Serial.println("----------------------------------------------------------------------");
    Serial.println(" ");
    Serial.println("IMPORTANT Pre-checks ");
    Serial.println("1. Arduino Serial Monitor Setup:- Both NL & CR is selected AND BAUD rate is set to 9600.");
    Serial.println("2. The HC-05's serial data flying leads (green/yellow) are connected to Mega UART 3 (pins 14/TX3/yellow and 15/RX3/green)...");
    Serial.println("3. The HC-05's power flying leads (red/blue) are connected to Mega +5V/Gnd ...");
    Serial.println("4. Ensure the HC-05 is in 'AT' mode when the Arduino/HC-05 is powered on by...");
    Serial.println(" ");
    Serial.println("Powering on the Controller/HC-05 with the small button on the HC-05 pressed");
    Serial.println("Then release the button - The LED on the HC-05 should now flash on/off every 2 seconds (approx.)");
    Serial.println("-------------------------------------------------------------------------------------------------");
     
    Serial.println(" ");
    Serial.println("First we will check that the Mega can communicate with the HC-05 by sending the AT+VERSION command.");
    Serial.println("If the HC-05 is in 'AT' mode (see above) AND serial communications is functioning between the Mega UART3 and HC-05 serial data pins");
    Serial.println("then we should see the HC-05 firmware revision and OK printed below...");
 
    Serial.println(" ");
    Serial.println("If you do not see this, then check:-");
    Serial.println("");
    Serial.println("1. The HC-05 is in AT Mode. LED blinking 2 secs on/ 2secs off repeating.");
    Serial.println("If the LED is flashing rapidly (indicating pairing mode), then power on the controller/HC-05 again while pressing the HC-05 small reset button");
    Serial.println("and try again...");
    Serial.println("");
    Serial.println("2. The Bluetooth Module is a supported version");
    Serial.println("");
    Serial.println("3. The HC-05/Adapter Board/Flying leads wiring to the Mega UART 3 Serial Port and Power referring to the build documentation");
    Serial.println(" ");
    Serial.println(" ");
 
    // set communication with the BT module on Serial3 to 38400 BAUD, then send VERSION command to HC-05
    Serial3.begin(38400); 
    delay(1000);    
    Serial3.print("AT+VERSION\r\n");
   
    Serial.println(" ");
    Serial.println(" ");
    Serial.println("If the communications test is successful - set the HC-05 BAUD rate (compulsory), Bluetooth Name/PIN... Commands shown below "); 
    Serial.println(" ");
    Serial.println("AT+UART=115200,0,0     MANDATORY   - Sets BAUD rate between HC-05 and Mega to be 115200 ");
    Serial.println("AT+NAME=DCCppBT        RECOMMENDED - Sets Bluetooth name to be DCCpp (default is HC-05)");
    Serial.println("AT+PSWD=\"1122\"       RECOMMENDED - Sets the Bluetooth pairing PIN to be 1122 (default is 1234) ");
    Serial.println("AT+POLAR=1,0           MANDATORY for Bluetooth Version   - Sets HC-05 STATE signal to Active Low ");
    Serial.println(" ");
    Serial.println("Expect to see +VERSION:2.xxx (or similar) on the next line... If you do not see this, there is a problem - so carefully read the stuff above and try again. ");
 
}
   
void loop() 
{
    // while there is serial data available on UART 3 from HC-05, relay it to the USB port (and on to computer)
    if ( Serial3.available() )   {  Serial.write( Serial3.read() );  }
  
    // while there is serial data available from the USB port (attached computer), relay it to the HC-05 (on UART 3)
   if ( Serial.available() )   {  Serial3.write( Serial.read() );  }
}

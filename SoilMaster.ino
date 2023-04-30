const int soilMoistureSensor = A0; // Analog input pin for soil moisture sensor
const int relay = 2; // Digital output pin for relay

void setup() {
  pinMode(relay, OUTPUT); // Set relay as output
  digitalWrite(relay, HIGH); // Turn off the relay
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int soilMoistureValue = analogRead(soilMoistureSensor); // Read soil moisture sensor value
  Serial.print("Soil Moisture: "); 
  Serial.println(soilMoistureValue); // Print soil moisture value to serial monitor
  
  if (soilMoistureValue < 500) { // If soil moisture is below threshold
    digitalWrite(relay, LOW); // Turn on the relay to water the plant
    Serial.println("Watering the plant.");
    delay(5000); // Water the plant for 5 seconds
    digitalWrite(relay, HIGH); // Turn off the relay
    Serial.println("Plant has been watered.");
  }
  
  delay(1000); // Delay for 1 second before checking soil moisture again
}

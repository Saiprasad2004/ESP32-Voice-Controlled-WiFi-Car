#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

#define IN1 25
#define IN2 26
#define IN3 27
#define IN4 14

#define ENA 33
#define ENB 32

//int speedValue = 180;


void front()
{
  ledcWrite(ENA,200);
  ledcWrite(ENB,200);
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  Serial.println("Moving Forward");
}

void stopCar()
{
  ledcWrite(ENA,0);
  ledcWrite(ENB,0);
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  Serial.println("STOP");
}
void left()
{
  ledcWrite(ENA,200);
  ledcWrite(ENB,200);
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  Serial.println("left");
}
void right()
{
  ledcWrite(ENA,200);
  ledcWrite(ENB,200);
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  Serial.println("right");
}
void back()
{
   ledcWrite(ENA,200);
  ledcWrite(ENB,200);
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  Serial.println("back");
}


void handleRoot()
{
  server.send(200, "text/html",

  "<h1>ESP32 Car Control</h1>"

  "<button onclick='startListening()'>Voice Command</button><br><br>"

  "<button onclick=\"sendCommand('forward')\">Forward</button><br><br>"

  "<button onclick=\"sendCommand('left')\">Left</button>"
  "&nbsp;&nbsp;&nbsp;&nbsp;"
  "<button onclick=\"sendCommand('right')\">Right</button><br><br>"

  "<button onclick=\"sendCommand('back')\">Backward</button><br><br>"

  "<button onclick=\"sendCommand('stop')\">Stop</button>"

  "<script>"

  "function sendCommand(command){"
    "fetch('http://192.168.4.1/' + command)"
    ".then(response => response.text())"
    ".then(data => console.log(data))"
    ".catch(error => alert('Error: ' + error));"
  "}"

  "function startListening(){"

    "if(!('webkitSpeechRecognition' in window)){"
      "alert('Speech Recognition not supported');"
      "return;"
    "}"

    "var recognition = new webkitSpeechRecognition();"

    "recognition.lang='en-US';"
    "recognition.continuous=false;"
    "recognition.interimResults=false;"

    "recognition.onstart=function(){"
      "alert('Listening...');"
    "};"

    "recognition.onerror=function(event){"
      "alert('Error: ' + event.error);"
    "};"

    "recognition.onresult=function(event){"

      "var command=event.results[0][0].transcript.toLowerCase();"

      "if(command.includes('forward')){"
        "sendCommand('forward');"
        "setTimeout(function(){sendCommand('stop');},1500);"
      "}"

      "else if(command.includes('back')){"
        "sendCommand('back');"
        "setTimeout(function(){sendCommand('stop');},1500);"
      "}"

      "else if(command.includes('left')){"
        "sendCommand('left');"
        "setTimeout(function(){sendCommand('stop');},1500);"
      "}"

      "else if(command.includes('right')){"
        "sendCommand('right');"
        "setTimeout(function(){sendCommand('stop');},1500);"
      "}"

      "else if(command.includes('stop')){"
        "sendCommand('stop');"
      "}"

    "};"

    "recognition.start();"

  "}"

  "</script>"

  );
}

void setup() {
  Serial.begin(115200);

  WiFi.softAP("ESP32CAR", "12345678");

    pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT); 
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  ledcAttach(ENA, 5000, 8);
  ledcAttach(ENB, 5000, 8);

  server.on("/", handleRoot); 

  Serial.println("Hotspot Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/forward", []() {

  front();

  delay(1500);

  stopCar();

  server.send(200, "text/plain", "Forward Done");
  });

  server.on("/stop", []() {
    stopCar();
    server.send(200, "text/plain", "Stopped");
  });

  server.on("/left", []() {

  left();

  delay(800);

  stopCar();

  server.send(200, "text/plain", "Left Done");
   });

  server.on("/right", []() {

  right();

  delay(800);

  stopCar();

  server.send(200, "text/plain", "Right Done");
  });

  server.on("/back", []() {

  back();

  delay(1500);

  stopCar();

  server.send(200, "text/plain", "Back Done");
  });

  
  server.begin();

}

void loop() {
  server.handleClient();
}






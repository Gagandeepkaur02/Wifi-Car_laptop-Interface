#include <ESP8266WiFi.h>

#define ENA D5
#define ENB D6

#define IN1 D8
#define IN2 D7
#define IN3 D4
#define IN4 D3

const char* ssid = "Add wifi name";
const char* password = "Add wifi password";

WiFiServer server(80);

void setup()
{
  Serial.begin(115200);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, 100);
  analogWrite(ENB, 100);

  stopMotor();

  Serial.println();
  Serial.println("Connecting to WiFi...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();

  Serial.println("Server Started");
  Serial.println("Open the IP shown above in your browser");
}

void loop()
{
  WiFiClient client = server.available();

  if (!client)
  {
    return;
  }

  while (!client.available())
  {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);

  client.flush();

  if (request.indexOf("/FORWARD") != -1)
  {
    Serial.println("FORWARD");
    forward();
  }

  else if (request.indexOf("/BACKWARD") != -1)
  {
    Serial.println("BACKWARD");
    backward();
  }

  else if (request.indexOf("/LEFT") != -1)
  {
    Serial.println("LEFT");
    left();
  }

  else if (request.indexOf("/RIGHT") != -1)
  {
    Serial.println("RIGHT");
    right();
  }

  else if (request.indexOf("/STOP") != -1)
  {
    Serial.println("STOP");
    stopMotor();
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();

  client.println("<!DOCTYPE html>");
  client.println("<html>");
  client.println("<head>");
  client.println("<meta name='viewport' content='width=device-width, initial-scale=1'>");
  client.println("<title>ESP8266 Robot Car</title>");
  client.println("</head>");

  client.println("<body style='text-align:center;font-family:Arial;'>");

  client.println("<h1>ESP8266 Robot Car</h1>");

  client.println("<p>");
  client.println("<a href='/FORWARD'><button style='width:200px;height:70px;font-size:20px;'>FORWARD</button></a>");
  client.println("</p>");

  client.println("<p>");
  client.println("<a href='/LEFT'><button style='width:120px;height:70px;font-size:20px;'>LEFT</button></a>");
  client.println("&nbsp;&nbsp;");
  client.println("<a href='/STOP'><button style='width:120px;height:70px;font-size:20px;'>STOP</button></a>");
  client.println("&nbsp;&nbsp;");
  client.println("<a href='/RIGHT'><button style='width:120px;height:70px;font-size:20px;'>RIGHT</button></a>");
  client.println("</p>");

  client.println("<p>");
  client.println("<a href='/BACKWARD'><button style='width:200px;height:70px;font-size:20px;'>BACKWARD</button></a>");
  client.println("</p>");

  client.println("</body>");
  client.println("</html>");
}

void backward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left()
{
  // Left wheel backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Right wheel backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void right()
{
  // Left wheel forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right wheel forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopMotor()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

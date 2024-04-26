#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#include "token.h"

//Token de Telegram BOT se obtenienen desde Botfather en telegram
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
unsigned long tiempoAnterior; //última vez que se realizó el análisis de mensajes

String chat_id, text;
//const char * ID_Chat = "tu_id_chat";//ID_Chat se obtiene de telegram
int PIN_RELAY = 4;

void setup()
{
  Serial.begin(115200);
  pinMode(PIN_RELAY, OUTPUT); //inicializar  pin digital como salida.
  // Intenta conectarse a la red wifi
  Serial.println("Conectando a la red ");
  WiFi.begin(SSID, PASS);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); //Agregar certificado raíz para api.telegram.org
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("Conectado a la red wifi. Dirección IP: ");
  Serial.println(WiFi.localIP());
}
 
void loop()
{
  //Verifica si hay datos nuevos en telegram cada 1 segundo
  if (millis() - tiempoAnterior > tiempo)
  {
    int numerosMensajes = bot.getUpdates(bot.last_message_received + 1);
 
    while (numerosMensajes)
    {
      mensajesNuevos(numerosMensajes);
      Serial.printf("Comando recibido:  %s \n" , text);
      numerosMensajes = bot.getUpdates(bot.last_message_received + 1);
    }
    tiempoAnterior = millis();
  }
}

void mensajesNuevos(int numerosMensajes)
{
  for (int i = 0; i < numerosMensajes; i++)
  {
    String chat_id = bot.messages[i].chat_id;
//    String text = bot.messages[i].text;
    text = bot.messages[i].text;
    if (text == "/on")
    {
      digitalWrite(PIN_RELAY, HIGH); // 
      bot.sendMessage(chat_id, "Relé CERRADO!", "");
    }
 
    if (text == "/off")
    {
      digitalWrite(PIN_RELAY, LOW); // 
      bot.sendMessage(chat_id, "Relé ABIERTO!", "");
    }
  }
}
 
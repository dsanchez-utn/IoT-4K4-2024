#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#include "token.h"

//Token de Telegram BOT se obtenienen desde Botfather en telegram
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
unsigned long tiempoAnterior; //última vez que se realizó el análisis de mensajes

String chat_id;
//const char * ID_Chat = "tu_id_chat";//ID_Chat se obtiene de telegram

void setup()
{
  Serial.begin(115200);
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
    String text = bot.messages[i].text;
    bot.sendMessage(chat_id, text);
    Serial.println("Mensaje reenviado: "+ text + " --- al ID: " + chat_id);
  }
}
 
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define DHTPIN A3   
#define DHTTYPE DHT22  
#define tamanho_coluna 20
#define tamanho_linha 4

byte erro, endereco;
uint8_t endereco_disp = 0;
int quantidade_disp = 0;
bool sensorIniciado = false;

const char* getSensorName() {
    if(DHTTYPE == DHT11){
      return "DHT11";
    }else if(DHTTYPE == DHT22){
      return "DHT22";
    }else{
      return "de temperatura e umidade.";
    }
}

// Inicialização de dispositivos
DHT dht(DHTPIN, DHTTYPE); //Inicializa o sensor DHT no pino de dados.
LiquidCrystal_I2C* tela; // Inicializa a tela (ou display) I2C

void (*reiniciaSistema)(void) = 0; //Função que reinicia o Sistema. Ela aponta para o endereço 0.
void setup() {
  Serial.begin(9600);
  Wire.begin();
  dht.begin();

  Serial.println("Sistema ligado.");
  Serial.println("Escaneando dispositivos I2C, aguarde...\n");
  for (int i = 0; i < 60; i++) {
    Serial.print("."); 
    delay(100);          
  }
  Serial.println("\n");


  //Escaneamento de dispositivos I2C
  for (endereco = 1; endereco < 127; endereco++) {
    Wire.beginTransmission(endereco);
    erro = Wire.endTransmission();
    if (erro == 0) { 
      quantidade_disp++;  //Dispositivo encontrado
      Serial.print("Dispositivo(s) encontrado(s) no endereço: 0x");
      if (endereco < 16) Serial.print("0"); // Formatação para endereços menores
      Serial.println(endereco, HEX);
      Serial.print("\n");
      endereco_disp = endereco;  //Primerio endereço encontrado 
    }else if (erro == 4) {
      Serial.print("Erro no endereço 0x");
      if (endereco < 16) Serial.print("0");
      Serial.println(endereco, HEX);
      Serial.print("\n");
    }
  }
  //Mostra o resultado do escaneamento
  if(quantidade_disp == 0){
    Serial.println("Nenhum dispositivo I2C encontrado!");
  }else{
    Serial.println("Escaneamento concluído!");
    Serial.print("Foram encontrados ");
    Serial.print(quantidade_disp);
    Serial.println(" dispositivo(s) I2C");
    Serial.println("________________________________________________\n");
  }

  Serial.println("Iniciando dispositivos I2C encontrados.\n");

  tela = new LiquidCrystal_I2C(endereco_disp, tamanho_coluna, tamanho_linha);
  tela->init();
  tela->backlight();
  tela->clear();
  tela->setCursor(0, 0);
  tela->print("Iniciando sistema...");
  delay(4000);

  // Teste para saber se o sensor iniciou corretamente
  float teste_umidade = dht.readHumidity();
  float teste_temperatura = dht.readTemperature();

  tela->clear();

  if(isnan(teste_umidade) || isnan(teste_temperatura)){
    sensorIniciado = false;
    Serial.println("Falha ao iniciar o sensor!");
    tela->print("Erro no Sensor!");
    delay(3000);
    tela->clear();
    tela->print("Reiniciando...");
    Serial.println("Reiniciando Sistema...");
    delay(3000);
    tela->noBacklight();
    tela->noDisplay();
    reiniciaSistema();  //Reinicia o sistema em caso de falha no Sensor.
  } else {
    sensorIniciado = true;
    Serial.print("Sensor ");
    Serial.print(getSensorName());
    Serial.println(" iniciado, com sucesso.");
    tela->print("Sensor iniciado.");
  }
  delay(3000);
  Serial.println("\nColetando temperatura e umidade do ar, aguarde...\n");
  tela->setCursor(0, 0);
  tela->print("Coletando dados...");
  
  for (int i = 0; i < 3; i++) {
  Serial.print("."); 
  delay(2500);  // Tempo que o sensor coleta os dados na 1ª vez.        
  }
  Serial.println("\n");
}

void loop() {
  // Inicia as medidas do sensor DHT
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if(isnan(umidade) || isnan(temperatura) || sensorIniciado == false){
    Serial.println("Falha na coleta de informações do sensor.");
    tela->print("Falha no sensor."); 
    delay(3500);
    tela->clear();
    tela->print("Sistema");
    tela->setCursor(0, 1);
    tela->print("Inoperante");
    Serial.println("Sistema inoperante, devido falha no sensor");
    delay(3500);
    tela->noBacklight();
    tela->noDisplay();
    tela->clear();
  }else{
    // Exibe no monitor serial
    Serial.println("**************************************************");
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println("ºC");
    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.println("%");
    Serial.println("**************************************************");

    // Exibe no display I2C
    tela->setCursor(0, 0);
    tela->print("Temperatura: ");
    tela->print(temperatura);
    tela->write(223);
    tela->print("C");
    tela->setCursor(0, 1);
    tela->print("Umidade: ");
    tela->print(umidade);
    tela->print("%");
  }
  delay(3000); //Tempo para a próxima leitura.
}
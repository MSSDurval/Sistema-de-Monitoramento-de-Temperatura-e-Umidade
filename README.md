# DIAGNÓSTICO E TEORIZAÇÃO

## 1.1. Identificação das partes interessadas e parceiros

- **Partes envolvidas**:
  - Agricultores e Jardineiros
  - Pessoas que possuem uma geladeira e ar-condicionado
- **Partes Interessadas**:
  - Empresas de Armazenamento e Logística
  - Farmácias

## 1.2. Problemática e/ou problemas identificados

A equipe do projeto, através de encontros e conversas, detectou que as partes envolvidas tinham dificuldades em monitorar a temperatura e a umidade de certos ambientes, como estufas, terrários, campos e outros locais em que se armazenam alimentos e medicamentos, como geladeiras, frigoríficos e prateleiras refrigeradas.

## 1.3. Justificativa

A implementação do Sistema de Monitoramento de Temperatura e Umidade permite que os seus usuários possam visualizar em tempo real a temperatura e a umidade do ambiente escolhido. Dessa forma, as partes envolvidas e interessadas podem realizar checagens nessas informações e regular a temperatura ou umidade conforme o desejado ou mover seus produtos para outro local mais adequado.

## 1.4. Objetivos/resultados/efeitos a serem alcançados

O objetivo deste sistema é monitorar constantemente a temperatura e umidade de um ambiente, utilizando sensores ligados a uma placa microcontroladora para a transmissão desses dados a uma interface de monitoramento. Assim, o público envolvido poderá observar com maior eficácia e precisão, dados sobre o ambiente em questão.

---

# PLANEJAMENTO E DESENVOLVIMENTO DO PROJETO

## 2.1. Plano de trabalho

O projeto foi planejado e identificado pela equipe. Com base nisso, a equipe criou um documento que descreve quais são os componentes necessários e como é realizada a montagem do circuito. Nesse documento temos os seguintes termos:

- **Objetivo**:
  - Desenvolver um sistema utilizando Arduino para monitorar a temperatura e umidade de um ambiente de forma precisa e constante, com o auxílio de sensores para transmissão dos dados a uma interface de monitoramento, até o data limite de novembro de 2024.

- **Componentes Necessários**:
  - Placa Arduino Uno (ou Similar).
  - Sensor DHT22 (ou da mesma família) para medir a temperatura e a umidade.
  - Display LCD 20x04 com o módulo de Comunicação Serial I2C PCF8574.
  - Resistor PULL-UP de 4,7 kΩ (Ohms).
  - Jumpers macho-fêmea para a conexão dos componentes no circuito.
  - Protoboard para montagem do circuito.

- **Etapas do Projeto**:
  1. **Configuração do Ambiente de Trabalho**:
     - Baixar e instalar o Arduino IDE no site oficial do Arduino em um computador.
     - Preparar os drivers da placa Arduino.
     - Conectar a placa ao computador e instalar os drivers necessários.
     - Adicionar as bibliotecas “DHT.h”, “Wire.h” e “LiquidCrystal_I2C.h” ao Arduino IDE.
  2. **Montagem do Circuito**:
     - Primeiro encaixar o Sensor DHT22 nos furos do Protoboard.
     - Em seguida, conectar o pino de alimentação 5V e o pino terra GND ao Protoboard, conforme o Diagrama, usando os Jumpers macho-fêmea.
     - Agora conectar, através do Protoboard, o pino de alimentação 5V ao pino VCC do Sensor DHT22, e o pino terra GND ao pino terra GND do Sensor DHT22.
     - Conectar o pino analógico A3 da Placa Arduino com o pino SDA do Sensor DHT22 para que ele consiga enviar os dados coletados ao microcontrolador da Placa Arduino.
     - Conectar um Resistor PULL-UP de 4,7 kΩ (Ohms) ao pino SDA e ao pino de alimentação de 5V, conforme indicado no diagrama do circuito.
     - Conectar os pinos GND, VCC, SDA e SCL do Display LCD I2C aos respectivos pinos GND, 5V, A4 e A5 da Placa Arduino.
  3. **Desenvolvimento do Sistema de Monitoramento**:
     - Criar um Sketch do circuito montado.
     - Programar a Placa Arduino.
     - Realizar simulações e testes para corrigir falhas e erros que possam ocorrer durante a execução do Sistema.

Cada etapa do projeto foi realizada com prazo de dois meses, a partir da data de início do projeto que foi em setembro de 2024, dentro da residência de uma das partes envolvidas neste projeto.

## 2.2. Descrição da forma de envolvimento do público participante

Dentro da residência de uma das partes envolvidas no projeto, foram realizados encontros nos quais eles relataram os problemas em monitorar e acompanhar a temperatura de um frigobar, local onde estavam mantidos alimentos perecíveis que precisavam estar em um ambiente refrigerado a uma certa temperatura. Logo, os integrantes do projeto decidiram aplicar os conhecimentos adquiridos nas aulas de “Programação de Microcontroladores” com o Orientador Gabriel Bau para criar um Sistema que pudesse realizar medições de temperatura em graus Celsius e exibi-los em uma interface, que para este caso foi uma pequena tela acoplada ao frigobar.

## 2.3. Avaliação dos Resultados Alcançados

A eficácia do sistema será avaliada através da comparação da facilidade do monitoramento dos dados antes e depois da implementação, como também na satisfação dos envolvidos através de questionários e na observação direta da eficácia operacional da leitura e exibição da temperatura e umidade.

---

# ENCERRAMENTO DO PROJETO

## 3.1. Relato de Experiência Individual

- **Equipe do Projeto**:
  - Matheus de Souza Santos Durval (Aluno universitário)
    - Matrícula: 202208867588
    - Disciplina: Programação de Microcontroladores

### CONTEXTUALIZAÇÃO
A equipe criadora e participante do projeto vivenciou uma excelente experiência no desenvolvimento de circuitos com o Arduino Uno, além do desenvolvimento e do descobrimento de novos módulos e formas de criar tarefas automatizadas, que podem inclusive ser controladas remotamente, usando um controle ou um celular. O aprendizado das aulas de “Programação de Microcontroladores” contribuiu significativamente para a criação do projeto, onde todo o conhecimento adquirido foi aplicado para entendermos como seria construído o Sistema e como ele iria funcionar.

### METODOLOGIA
O projeto foi planejado e construído em fases, onde cada uma delas descreve etapas que foram necessárias para a finalização do projeto, dentre elas a Configuração do Ambiente de Trabalho, Montagem do Circuito e o Desenvolvimento do Sistema de Monitoramento.

### RESULTADOS E DISCUSSÃO
O resultado do projeto foi dentro do esperado pelo público participante, com uma expectativa de que o Sistema de Monitoramento possa chegar a demais pessoas físicas e jurídicas na comunidade, com melhorias e novas funcionalidades.

## 3.2. Evidências das atividades realizadas

O Sistema de Monitoramento de Temperatura e Umidade pode ser conferido em:
- Wokwi: https://wokwi.com/projects/414720456481561601
- Github: https://github.com/MSSDurval/Sistema-de-Monitoramento-de-Temperatura-e-Umidade.git

A documentação do projeto, incluindo o Diagrama do Circuito e os Detalhes do Projeto pode ser vista em:
- Documentação do Projeto: https://github.com/MSSDurval/Sistema-de-Monitoramento-de-Temperatura-e-Umidade/tree/6627db899c979ab691acdeb374f6d01472399b15/Documenta%C3%A7%C3%A3o%20do%20Projeto

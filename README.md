# SANCI - Sistema de Alerta Noturno para Cuidadores de Idosos

Manual para utilização do Alarme Noturno (Projeto desenvolvido para a disciplina de Programação Estruturada 2019.1, utilizando o Qt Creator e com uma interface Web)

## O que é?

Sanci é um sistema de alarme noturno que tem como objetivo auxiliar cuidadores de idosos, através do uso de um sistema de alarme inteligente.


## Como funciona?

O alarme poderá ser acionado ou destivado pelo cuidador através da interface WEB ou pelo aplicativo. Quando o alarme estiver ativado, ele irá disparar toda vez que o sensor infravermelho(receptor/emissor), colocado próximo a cama, tiver o sinal interrompido, ou seja, toda vez que alguem passar por ele. Podendo ser desativado através do site "projetoin.herokuapp.com" 

## Como utlizar SANCI pela WEB?

Acesse o site "projetoin.herokuapp.com". Ele irá abrir na página abaixo:

IMAGEM

Ao clicar no botão "Ativar" o sistema de alarme será ativado e o status do alarme será atualizado para "Ativado".

IMAGEM

Ao clicar no botão "Desativar" o Buzzer será desativado e o status do alarme será atualizado para "Desativado".
 
IMAGEM

No site também aparecerá os dados recebidos pelo sensor infravermelho. Valores abaixo de 1000(mil), significa que o sensor está recebendo sinal. Valores maiores que mil, significa que o sinal foi interrompido, ou seja, o idoso passou pelos sensores e está acordado.

IMAGEM

## Como utilizar SANCI com o QT Creator?

## Materiais utilizados:

NodeMcu ESP32: O módulo Wifi ESP32 NodeMCU é uma placa de desenvolvimento que combina o chip ESP32, uma interface usb-serial e um regulador de tensão 3.3V. A programação pode ser feita usando LUA ou a IDE do Arduino.

Arduino UNO: O Arduino Uno é uma placa de microcontrolador baseado no ATmega328 ( datasheet ).Ele pode ser alimentado através da conexão USB ou com uma fonte de alimentação externa.

Buzzer: Componente eletrônico que é composto por 2 camadas de Metal e uma terceira camada interna de cristal Piezoeléctrico, este componente recebe uma fonte de energia e através dela emite uma frequência sonora.

Led Emissor e Receptor Infravermelho IR: Componente que funciona a partir da tecnologia infravermelha. Este LED emite um sinal IR que pode ser reconhecido por diversos receptores infravermelho.

Led: Componente para um projeto que necessita de uma fonte de luz ou algum efeito de sinalização. Ele é formado por um material semicondutor, que emite luz quando uma tensão é aplicada aos seus terminais.

Resistor 330 ohms e 100K ohms: utilizado em ambiente de testes e reparo de circuitos eletrônicos em geral.

### Obrigada!

Para mais informações, entre em contato:

Nicoly Matos Martins - nicolymatos@gmail.com

Maria Isabelle Freire Correia - mariaisabelle170498@gmail.com

# SANCI - Sistema de Alerta Noturno para Cuidadores de Idosos

Manual para utilização do Alarme Noturno (Projeto desenvolvido para a disciplina de Programação Estruturada 2019.1, utilizando o Qt Creator e com uma interface Web)

## O que é?

Sanci é um sistema de alarme noturno que tem como objetivo auxiliar cuidadores de idosos, através do uso de um sistema de alarme inteligente.


## Como funciona?

O alarme poderá ser acionado ou destivado pelo cuidador através da interface WEB ou pelo aplicativo. Quando o alarme estiver ativado, ele irá disparar toda vez que o sensor infravermelho(receptor/emissor), colocado próximo a cama, tiver o sinal interrompido, ou seja, toda vez que alguém passar por ele. Podendo ser desativado através do site "projetoin.herokuapp.com" 

## Como utlizar SANCI pela WEB?

Acesse o site "projetoin.herokuapp.com". Ele irá abrir na página abaixo:
![Alt ou título da imagem](https://github.com/NicolyMatos/Projeto-Nicoly-e-Isabelle/blob/master/imagens/Inicio.png)

Ao clicar no botão "Ativar" o sistema de alarme será ativado e o status do alarme será atualizado para "Ativado".
![Alt ou título da imagem](https://github.com/NicolyMatos/Projeto-Nicoly-e-Isabelle/blob/master/imagens/Ativado.png)

Ao clicar no botão "Desativar" o Buzzer será desativado e o status do alarme será atualizado para "Desativado".
![Alt ou título da imagem](https://github.com/NicolyMatos/Projeto-Nicoly-e-Isabelle/blob/master/imagens/Desativado.png)

No site também aparecerá os dados recebidos pelo sensor infravermelho. Valores abaixo de 1000(mil), significa que o sensor está recebendo sinal. Valores maiores que mil, significa que o sinal foi interrompido, ou seja, o idoso passou pelos sensores e está acordado.

## Como utilizar SANCI com o QT Creator?

Primeiramente, devemos abrir a interface do QT Creator.
![Alt ou título da imagem](https://github.com/NicolyMatos/Projeto-Nicoly-e-Isabelle/blob/master/imagens/InicioQT.png)

### Comunicação QT-Arduino

Para inicializar a comunicao QT-Arduino basta selecionar a porta do arduino "COM4".
![Alt ou título da imagem](https://github.com/NicolyMatos/Projeto-Nicoly-e-Isabelle/blob/master/imagens/EscolhaPortaQT.png)

Logo em seguida, alterar a velocidade para "9600" e, em seguida, clicar no botao "Abrir".
![Alt ou título da imagem](https://github.com/NicolyMatos/Projeto-Nicoly-e-Isabelle/blob/master/imagens/EscolhaPorta9600_QT.png)
![Alt ou título da imagem](https://github.com/NicolyMatos/Projeto-Nicoly-e-Isabelle/blob/master/imagens/StatusConectado.png)

Logo, aparecera o status da comunicação.

Caso queira finalizar a comunicacao QT-Arduino, basta clicar em "Fechar". Assim, o staus da comunicacao será alterado para "Desconectado".
![Alt ou título da imagem](https://github.com/NicolyMatos/Projeto-Nicoly-e-Isabelle/blob/master/imagens/StatusDesconectado.png)

### Ativando o amlarme no QT:

Para ativar o alarme basta clicar no botão "Ativar", ao apertar irá aparecer na tela que o alarme está ativado
![Alt ou título da imagem](https://github.com/NicolyMatos/Projeto-Nicoly-e-Isabelle/blob/master/imagens/AlarmeAtivadoQT.png)

### Desativando o alarme no QT:

Para desativar o alarme basta clicar no botão "Desativar", ao apertar irá aparecer na tela que o alarme está ativado
![Alt ou título da imagem](https://github.com/NicolyMatos/Projeto-Nicoly-e-Isabelle/blob/master/imagens/AlarmeDesativadoQT.png)

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

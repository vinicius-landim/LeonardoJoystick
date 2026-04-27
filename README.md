# LeonardoJoystick

Interface de comunicação HID (Human Interface Device) utilizando um **Arduino Leonardo** para transformar a leitura de um transdutor linear em um eixo de joystick de 16 bits.
## Hardware
- **Microcontrolador:** Arduino Leonardo (ATmega32U4).
- **Sensor:** Transdutor Linear KTC1 (ou potenciômetro deslizante).
- **Conexão:** USB nativa para emulação HID.

## Especificações Técnicas
- **Resolução de Entrada:** 10-bit (0 a 1023) via ADC interno.
- **Resolução de Saída:** 16-bit Signed Integer (-32768 a 32767).
- **Perfil HID:** `JOYSTICK_TYPE_GAMEPAD`.

## Conexão
| Componente (Pino) | Arduino Leonardo | Função |
| :--- | :--- | :--- |
| **Pino 1** | **GND** | Referência de tensão (0V) |
| **Pino 2** | **A0** | Sinal de saída |
| **Pino 3** | **5V** | Alimentação positiva (+5V) |

## Setup de Software

### 1. Requisitos
- [Arduino IDE](https://www.arduino.cc/en/software)
- Biblioteca [ArduinoJoystickLibrary](https://github.com/MHeironimus/ArduinoJoystickLibrary).

### 2. Configuração do Ambiente
1. Baixe o arquivo `.zip` em [ArduinoJoystickLibrary](https://github.com/MHeironimus/ArduinoJoystickLibrary).
2. Instale a biblioteca `Joystick` na sua pasta de libraries do Arduino.
3. Compile e faça o upload do sketch `LeonardoJoystick.ino`.

## Verificação do Dispositivo

### No Linux
Para validar a leitura dos 16 bits brutos no terminal, instale o pacote `joystick` e execute:
```bash
sudo apt install joystick
jstest /dev/input/js0
```
Para verificação visual, utilize o `jstest-gtk`
```bash
sudo apt install jstest-gtk
jstest-gtk
```
E acesse *Properties* para monitorar o movimento.

### No Windows
1. Pressione `Win+R` e execute `joy.cpl`
2. Selecione Arduino Leonardo > Properties > Test
3. Verifique a movimentação no eixo X.

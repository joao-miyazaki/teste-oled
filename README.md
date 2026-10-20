# Bad Apple no ESP32 com Display OLED

Este projeto executa a famosa animação **"Bad Apple"** diretamente em um microcontrolador **ESP32** acoplado a um display OLED monocromático, utilizando a biblioteca Adafruit GFX. A taxa de quadros é controlada por software para garantir uma reprodução fluida na tela.

## 🚀 O que o código faz?
- **Inicialização do I2C**: Configura os pinos de comunicação e inicializa o display OLED via protocolo I2C (endereço `0x3C`).
- **Tela de Carregamento**: Exibe uma mensagem inicial ("Loading Bad Apple...") antes de iniciar a animação.
- **Renderização de Bitmaps**: Faz um loop por todos os frames da animação (`TOTAL_FRAMES`) armazenados em um arquivo de cabeçalho (`bad_apple_frames.h`) e os desenha na tela de 128x64 pixels.
- **Controle de FPS (Frames por Segundo)**: Calcula o tempo de processamento de cada frame e aplica um atraso dinâmico para estabilizar a taxa de reprodução em aproximadamente 30 FPS (`33ms` por frame).

## 🔌 Pinagem utilizada (ESP32 ➔ Display OLED)

O projeto utiliza os pinos padrão de I2C remapeados do ESP32 para o display:

| pino do ESP32 | Pino do Display OLED | Descrição |
| :--- | :--- | :--- |
| **GPIO 32** | `SDA` | Dados I2C (Serial Data) |
| **GPIO 33** | `SCL` | Clock I2C (Serial Clock) |
| **GND** | `GND` | Terra comum |
| **3V3** | `VCC` | Alimentação (3.3V) |

## 🛠️ Dependências (PlatformIO / Arduino)
Certifique-se de incluir as seguintes bibliotecas no seu `platformio.ini`:
- `adafruit/Adafruit GFX Library`
- `adafruit/Adafruit SSD1306`
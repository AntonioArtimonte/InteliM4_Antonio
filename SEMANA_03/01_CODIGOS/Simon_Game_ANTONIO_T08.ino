
// Declarar variáveis
const int nivel_maximo  = 20; // Varíavel nivel máximo ( QUANTO MAIOR, MAIS NÍVEIS )
int sequence[nivel_maximo]; // Array sequência dos leds
int your_sequence[nivel_maximo]; // Array sequência dos botões
int fase  = 1; // Váriavel nivel atual

int dificuldade = 1000; // Váriavel delay entre "piscadas" dos leds



void setup() {
Serial.begin(9600); // Iniciar com o valor 9600 para o SM

// Declarar pinos dos botões
pinMode(23, INPUT_PULLUP);
pinMode(4,  INPUT_PULLUP);
pinMode(15, INPUT_PULLUP);
pinMode(13, INPUT_PULLUP);

// Pino botão reset
pinMode(22, INPUT_PULLUP);

// Declarar pinos dos LEDs
pinMode(16, OUTPUT);
pinMode(17,  OUTPUT);
pinMode(18, OUTPUT);
pinMode(19, OUTPUT);

// Desligar todos os LEDs
digitalWrite(16, LOW);
digitalWrite(17,  LOW);
digitalWrite(18, LOW);
digitalWrite(19, LOW);

}

void loop()
{

// Iniciar o jogo com o botão de reset/início
if(digitalRead(22) == LOW && fase == 1){
  mostrar_sequencia(); // Chamar a função de mostrar as sequências com os leds
  pegar_sequencia(); // Chamar a função de pegar a sequência do usuário
  
}

if  (fase == 1)
gerar_sequencia(); // Gerar a sequência caso a fase seja 1

if (fase != 1) 
{
mostrar_sequencia();  // Ao mudar de fase, mostrar as novas sequencias e adquirir as sequências do usuário
pegar_sequencia();     
}
}

void  mostrar_sequencia() // Função de mostrar sequência
{

// Desligar os LEDs
digitalWrite(16, LOW);
digitalWrite(17,  LOW);
digitalWrite(18, LOW);
digitalWrite(19, LOW);


// Iterar entre os valores da sequência, sendo sempre menor ao número relacionado da fase
for (int i = 0; i < fase; i++)
{
digitalWrite(sequence[i],  HIGH); // Acender o LED
delay(dificuldade); // Delay relacionado a fase do usuário
digitalWrite(sequence[i], LOW); // Desligar o LED
delay(200);
}
}

void  pegar_sequencia() // Função para pegar a sequência do usuário
{
int flag = 0; // Varíavel para checar se a sequencia está correta


for  (int i = 0; i < fase; i++) // Iterar para todos os valores de I da sequência relacionada a fase
{
flag = 0;
while(flag == 0) // Enquanto a sequência estiver correta e a quantidade de itens na array do usuário ser menor que o número de fases, executar código abaixo
{
if (digitalRead(23)  == LOW) // Se o botão relacionado ao LED azul ser pressionado, executará o código abaixo
{
digitalWrite(16, HIGH); // Ligar o LED azul
your_sequence[i] = 16; // Adicionar a array dos botões o botão 16 = AZUL
flag = 1; // Mudar para 1 a flag, mostrando que um botão foi adicionado a array
delay(200);
if  (your_sequence[i] != sequence[i]) // Checar a array do usuário e dos LEDs para checar se estão corretas
{
sequencia_errada(); // Caso estejam erradas as arrays, chamar a função "sequência errada"
return;
}

digitalWrite(16,  LOW); // Desligar o LED azul
}

if (digitalRead(4) == LOW) // Se o botão relacionado ao LED verde ser pressionado, executará o código abaixo
{
digitalWrite(17, HIGH); // Ligar o LED verde
your_sequence[i]  = 17; // Adicionar a array dos botões o botão 17 = VERDE
flag = 1; // Mudar para 1 a flag, mostrando que um botão foi adicionado a array
delay(200);
if (your_sequence[i] != sequence[i])  // Checar a array do usuário e dos LEDs para checar se estão corretas
{
sequencia_errada(); // Caso estejam erradas as arrays, chamar a função "sequência errada"
return;
}
digitalWrite(17,  LOW); // Desligar o LED azul
}

if (digitalRead(15) == LOW) // Se o botão relacionado ao LED amarelo ser pressionado, executará o código abaixo
{
digitalWrite(18, HIGH); // Ligar o LED amarelo
your_sequence[i]  = 18; // Adicionar a array dos botões o botão 15 = AMARELO
flag = 1; // Mudar para 1 a flag, mostrando que um botão foi adicionado a array
delay(200);
if (your_sequence[i] != sequence[i]) // Checar a array do usuário e dos LEDs para checar se estão corretas
{
sequencia_errada(); // Caso estejam erradas as arrays, chamar a função "sequência errada"
return;
}
digitalWrite(18,  LOW); // Desligar o LED amarelo
}

if (digitalRead(13) == LOW) // Se o botão relacionado ao LED vermelho ser pressionado, executará o código abaixo
{
digitalWrite(19, HIGH); // Ligar o LED vermelho
your_sequence[i]  = 19; // Adicionar a array dos botões o botão 13 = VERMELHO
flag = 1; // Mudar para 1 a flag, mostrando que um botão foi adicionado a array
delay(200);
if (your_sequence[i] != sequence[i]) // Checar a array do usuário e dos LEDs para checar se estão corretas
{
sequencia_errada(); // Caso estejam erradas as arrays, chamar a função "sequência errada"
return;
}
digitalWrite(19,  LOW); // Desligar o LED vermelho
}

if (digitalRead(22) == LOW) // Se o botão de reset for pressionado, executará o código abaixo
{
your_sequence[i]  = 22; // Adicionar o botão de reset, 22 a array de botões
flag = 1; // Adicionar a flag afim de evitar erros
delay(200);
if (your_sequence[i] != sequence[i]) // Como o botão de reset, 22 não tem um LED referenciável, ira retornar a sequencia errada diretamente
{
sequencia_errada(); // Caso estejam erradas as arrays, chamar a função "sequência errada"
return;
}
}

}
}
sequencia_correta(); // Caso a sequência seja correta, chamar a função "sequencia_correta"
}

void gerar_sequencia() // Função para gerar a sequencia
{
randomSeed(millis());  // Função de randomizar

for (int i = 0; i < nivel_maximo; i++) // Gerar a sequência de 0 até o nivel máximo dito na váriavel no começo
{
sequence[i]  = random(16,20); // Adicionar a array da sequência dos LEDs números randomizados entre 16 e 19 que são os respectivos pinos dos LEDs
}
}
void sequencia_errada() // Função caso a sequência seja errada
{
for (int i = 0; i < 3;  i++) // Irá iterar na quantidade de LEDs
{
// Acenderá e apagará todos os LEDs
digitalWrite(16, HIGH);
digitalWrite(17,  HIGH);
digitalWrite(18, HIGH);
digitalWrite(19, HIGH);
delay(250);
digitalWrite(16, LOW);
digitalWrite(17,  LOW);
digitalWrite(18, LOW);
digitalWrite(19, LOW);
delay(250);
}
// Voltará a fase para 1 
fase  = 1;
// Voltará a dificuldade para 1000
dificuldade = 1000;
}

void sequencia_correta() // Função caso a sequência seja correta
{
// Apagar, acender e apagar todos os LEDs
digitalWrite(16, LOW);
digitalWrite(17,  LOW);
digitalWrite(18, LOW);
digitalWrite(19, LOW);
delay(250);

digitalWrite(16, HIGH);
digitalWrite(17,  HIGH);
digitalWrite(18, HIGH);
digitalWrite(19, HIGH);
delay(500);
digitalWrite(16, LOW);
digitalWrite(17,  LOW);
digitalWrite(18, LOW);
digitalWrite(19, LOW);
delay(500);

if  (fase < nivel_maximo); // Caso a fase seja menor que o nivel maximo, irá auemntar a fase em 1 e, "aumentar" a dificuldade em 50
fase++;

dificuldade -= 50;
}

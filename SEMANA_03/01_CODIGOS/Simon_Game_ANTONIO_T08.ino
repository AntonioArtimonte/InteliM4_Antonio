#define buttonStart 22
#define buttonB 23
#define buttonG 16
#define buttonY 18
#define buttonR 19
#define ledB 32
#define ledG 33
#define ledY 25
#define ledR 26

int fase = 1; // Váriavel relacionada a fase do jogo
int status = 0; // Váriavel relacionada ao status dos leds dentro das fases (ORDEM)
int buttonPresses[4] = {0};  
int currentIndex = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledB, OUTPUT); // Declara leds como OUTPUTS
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);  
  pinMode(buttonStart, INPUT_PULLUP); // Declara botões como INPUTS
  pinMode(buttonB, INPUT_PULLUP);
  pinMode(buttonG, INPUT_PULLUP);
  pinMode(buttonY, INPUT_PULLUP);
  pinMode(buttonR, INPUT_PULLUP);
  digitalWrite(ledB, LOW); // Desliga todos os leds
  digitalWrite(ledG, LOW);
  digitalWrite(ledY, LOW);
  digitalWrite(ledR, LOW);
}

void loop() {
  // IF para iniciar o jogo
  if (digitalRead(buttonStart) == LOW && fase == 1) {
    delay(1000);
    digitalWrite(ledB, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    delay(300);
    status = 1;
    Serial.println(status);
  }


  if (digitalRead(buttonB) == LOW) {
    storeButtonPress(1);
    delay(200);  // Debounce delay
  }
  if (digitalRead(buttonG) == LOW) {
    storeButtonPress(2);
    delay(200);  // Debounce delay
  }
  if (digitalRead(buttonY) == LOW) {
    storeButtonPress(3);
    delay(200);  // Debounce delay
  }
    if (digitalRead(buttonR) == LOW) {
    storeButtonPress(4);
    delay(200);  // Debounce delay
  }


  // IF para checar se o botão pressionado foi o correto de acordo com a fase
  if (digitalRead(buttonB) == LOW && fase == 1 && status == 1) {
    digitalWrite(ledB, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    delay(1000);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    delay(1000);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    status = 0;
    fase = 2;
  }

  // Se foi o botão errado, reiniciar o jogo
  if ((digitalRead(buttonG) == LOW || digitalRead(buttonY) == LOW || digitalRead(buttonR) == LOW) && fase == 1 && status == 1) {
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    status = 0;
    fase = 1;
  }


  // IF para iniciar a segunda fase

  if(fase == 2 && status == 0) {
    delay(1500);
    digitalWrite(ledB, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    delay(300);
    digitalWrite(ledG, HIGH);
    delay(300);
    digitalWrite(ledG, LOW);
    status = 1;
  }

  // IF para checar se o botão pressionado foi o correto de acordo com a fase

  if(digitalRead(buttonB) == LOW && fase == 2 && status == 1) {
    digitalWrite(ledB, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    status = 2;
  }

    // Se foi o botão errado, reiniciar o jogo

  if ((digitalRead(buttonG) == LOW || digitalRead(buttonY) == LOW || digitalRead(buttonR) == LOW) && fase == 2 && status == 1) {
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    status = 0;
    fase = 1;
  }

  // IF para checar se o botão pressionado foi o correto de acordo com a fase

  if(digitalRead(buttonG) == LOW && fase == 2 && status == 2) {
    digitalWrite(ledG, HIGH);
    delay(300);
    digitalWrite(ledG, LOW);
    status = 0;
    fase = 3;
    delay(1000);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    delay(1000);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
  }


    // Se foi o botão errado, reiniciar o jogo

  if ((digitalRead(buttonB) == LOW || digitalRead(buttonY) == LOW || digitalRead(buttonR) == LOW) && fase == 2 && status == 2) {
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    status = 0;
    fase = 1;
  }

  // IF para iniciar a fase 3
  if(fase == 3 && status == 0) {
    delay(1000);
    digitalWrite(ledB, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    delay(300);
    digitalWrite(ledG, HIGH);
    delay(300);
    digitalWrite(ledG, LOW);
    delay(300);
    digitalWrite(ledY, HIGH);
    delay(300);
    digitalWrite(ledY, LOW);
    status = 1;
  }
    // IF para checar se o botão pressionado foi o correto de acordo com a fase

  if(digitalRead(buttonB) == LOW && fase == 3 && status == 1) {
    digitalWrite(ledB, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    status = 2;
  }

  // Se foi o botão errado, reiniciar o jogo

    if ((digitalRead(buttonG) == LOW || digitalRead(buttonY) == LOW || digitalRead(buttonR) == LOW) && fase == 3 && status == 1) {
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    status = 0;
    fase = 1;
  }
  // IF para checar se o botão pressionado foi o correto de acordo com a fase

  if(digitalRead(buttonG) == LOW && fase == 3 && status == 2) {
    digitalWrite(ledG, HIGH);
    delay(300);
    digitalWrite(ledG, LOW);
    status = 3;
  }
    // Se foi o botão errado, reiniciar o jogo

    if ((digitalRead(buttonB) == LOW || digitalRead(buttonY) == LOW || digitalRead(buttonR) == LOW) && fase == 3 && status == 2) {
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    status = 0;
    fase = 1;
  }

  // IF para checar se o botão pressionado foi o correto de acordo com a fase

  if(digitalRead(buttonY) == LOW && fase == 3 && status == 3) {
    digitalWrite(ledY, HIGH);
    delay(300);
    digitalWrite(ledY, LOW);
    delay(1000);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    delay(1000);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    fase = 4;
    status = 4;
  }

    // Se foi o botão errado, reiniciar o jogo

    if ((digitalRead(buttonB) == LOW || digitalRead(buttonG) == LOW || digitalRead(buttonR) == LOW) && fase == 3 && status == 3) {
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    status = 0;
    fase = 1;
  }
 // fase 4

// IF para iniciar a fase 4
if (fase == 4 && status == 4) {
    delay(1000);
    digitalWrite(ledB, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    delay(300);
    digitalWrite(ledG, HIGH);
    delay(300);
    digitalWrite(ledG, LOW);
    delay(300);
    digitalWrite(ledY, HIGH);
    delay(300);
    digitalWrite(ledY, LOW);
    delay(300);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledR, LOW);
  status = 1;
}
  // IF para checar se o botão pressionado foi o correto de acordo com a fase

  if(digitalRead(buttonB) == LOW && fase == 4 && status == 1) {
    digitalWrite(ledB, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    status = 2;
  }


  // Se foi o botão errado, reiniciar o jogo

    if ((digitalRead(buttonY) == LOW || digitalRead(buttonG) == LOW || digitalRead(buttonR) == LOW) && fase == 4 && status == 1) {
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    status = 0;
    fase = 1;
  }
  // IF para checar se o botão pressionado foi o correto de acordo com a fase

  if(digitalRead(buttonG) == LOW && fase == 4 && status == 2) {
    digitalWrite(ledG, HIGH);
    delay(300);
    digitalWrite(ledG, LOW);
    status = 3;
    Serial.println(status);
  }


  // Se foi o botão errado, reiniciar o jogo

    if ((digitalRead(buttonY) == LOW || digitalRead(buttonB) == LOW || digitalRead(buttonR) == LOW) && fase == 4 && status == 2) {
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    status = 0;
    fase = 1;
  }
  // IF para checar se o botão pressionado foi o correto de acordo com a fase

  if(digitalRead(buttonY) == LOW && fase == 4 && status == 3) {
    digitalWrite(ledY, HIGH);
    delay(300);
    digitalWrite(ledY, LOW);
    status = 7;
  }


  // Se foi o botão errado, reiniciar o jogo

    if ((digitalRead(buttonG) == LOW || digitalRead(buttonB) == LOW || digitalRead(buttonR) == LOW) && fase == 4 && status == 3) {
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    status = 0;
    fase = 1;
  }
  // IF para checar se o botão pressionado foi o correto de acordo com a fase

  if(digitalRead(buttonR) == LOW && fase == 4 && status == 7) {
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledR, LOW);
    delay(1000);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    delay(1000);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    Serial.println("Acabou");
    status = 5;
  }


  // Se foi o botão errado, reiniciar o jogo

    if ((digitalRead(buttonG) == LOW || digitalRead(buttonB) == LOW || digitalRead(buttonY) == LOW) && fase == 4 && status == 7) {
    digitalWrite(ledB, HIGH);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, HIGH);
    delay(300);
    digitalWrite(ledB, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, LOW);
    status = 0;
    fase = 1;
  }

// IF para, caso o jogador queira, pode recomeçar o jogo a qualquer momento caso clique no botão de restart.
  if(digitalRead(buttonStart) == LOW && fase !=1) {
    fase = 1;
    status = 0;
  }

}


void storeButtonPress(int button) {
  buttonPresses[currentIndex] = button;
  currentIndex++;
  if (currentIndex == 4) {
    // If the buffer is full, reset currentIndex to 0
    currentIndex = 0;
  }

  // Print the current state of the buffer
  Serial.print("Buffer = {");
  for (int i = 0; i < 4; i++) {
    Serial.print(buttonPresses[i]);
    if (i < 3) {
      Serial.print(", ");
    }
  }
  Serial.println("}");
}

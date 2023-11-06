

const int MAX_LEVEL  = 100;
int sequence[MAX_LEVEL];
int your_sequence[MAX_LEVEL];
int level  = 1;

int velocity = 1000;

void setup() {
Serial.begin(9600);
pinMode(23, INPUT_PULLUP);
pinMode(4,  INPUT_PULLUP);
pinMode(15, INPUT_PULLUP);
pinMode(13, INPUT_PULLUP);

pinMode(22, INPUT_PULLUP);

pinMode(16, OUTPUT);
pinMode(17,  OUTPUT);
pinMode(18, OUTPUT);
pinMode(19, OUTPUT);

digitalWrite(16, LOW);
digitalWrite(17,  LOW);
digitalWrite(18, LOW);
digitalWrite(19, LOW);

}

void loop()
{


if(digitalRead(22) == LOW && level == 1){
  show_sequence();
  get_sequence();
  
}

if  (level == 1)
generate_sequence();//generate a sequence;

if (level != 1) //If start button is pressed or you're winning
{
show_sequence();    //show the sequence
get_sequence();     //wait for your sequence
}
}

void  show_sequence()
{
digitalWrite(16, LOW);
digitalWrite(17,  LOW);
digitalWrite(18, LOW);
digitalWrite(19, LOW);



for (int i = 0; i < level; i++)
{
digitalWrite(sequence[i],  HIGH);
delay(velocity);
digitalWrite(sequence[i], LOW);
delay(200);
}
}

void  get_sequence()
{
int flag = 0; //this flag indicates if the sequence is correct


for  (int i = 0; i < level; i++)
{
flag = 0;
while(flag == 0)
{
if (digitalRead(23)  == LOW)
{
digitalWrite(16, HIGH);
your_sequence[i] = 16;
flag = 1;
delay(200);
if  (your_sequence[i] != sequence[i])
{
wrong_sequence();
return;
}

digitalWrite(16,  LOW);
}

if (digitalRead(4) == LOW)
{
digitalWrite(17, HIGH);
your_sequence[i]  = 17;
flag = 1;
delay(200);
if (your_sequence[i] != sequence[i])
{
wrong_sequence();
return;
}
digitalWrite(17,  LOW);
}

if (digitalRead(15) == LOW)
{
digitalWrite(18, HIGH);
your_sequence[i]  = 18;
flag = 1;
delay(200);
if (your_sequence[i] != sequence[i])
{
wrong_sequence();
return;
}
digitalWrite(18,  LOW);
}

if (digitalRead(13) == LOW)
{
digitalWrite(19, HIGH);
your_sequence[i]  = 19;
flag = 1;
delay(200);
if (your_sequence[i] != sequence[i])
{
wrong_sequence();
return;
}
digitalWrite(19,  LOW);
}

if (digitalRead(22) == LOW)
{
your_sequence[i]  = 22;
flag = 1;
delay(200);
if (your_sequence[i] != sequence[i])
{
wrong_sequence();
return;
}
digitalWrite(30,  LOW);
}

}
}
right_sequence();
}

void generate_sequence()
{
randomSeed(millis());  //in this way is really random!!!

for (int i = 0; i < MAX_LEVEL; i++)
{
sequence[i]  = random(16,20);
}
}
void wrong_sequence()
{
for (int i = 0; i < 3;  i++)
{
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
level  = 1;
velocity = 1000;
}

void right_sequence()
{
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

if  (level < MAX_LEVEL);
level++;

velocity -= 50; //increase difficulty
}

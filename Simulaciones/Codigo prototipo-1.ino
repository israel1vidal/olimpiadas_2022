float temperatura ;
char estado = 'Z';
//unsigned long prev = 0;
//unsigned long tiempo = 0;

void setup() {
 // prev = millis();
  pinMode(2,INPUT); //BOTON ON
  pinMode(5,INPUT); //BOTON OFF
  pinMode(3,OUTPUT); // LED Enfriar
  pinMode(4,OUTPUT); // Temp. Ideal
  pinMode(13,OUTPUT); // LED Calentar
}

void loop() {
  switch(estado){
////////////////////////////////////////////////////////////////////////////
    case 'A':
            temperatura = analogRead(A1);
            cambio();
            //ecuacion();
    break;
////////////////////////////////////////////////////////////////////////////
    case 'B':
            //  ecuacion();
              temperatura = analogRead(A1);
              cambio();
              digitalWrite(13,LOW);
              digitalWrite(4,LOW);
              digitalWrite(3,HIGH);
    break;
////////////////////////////////////////////////////////////////////////////
    case 'C':
//            ecuacion();
              temperatura = analogRead(A1);
              cambio();
              digitalWrite(13,LOW);
              digitalWrite(3,LOW);
              digitalWrite(4,HIGH);
    break;
////////////////////////////////////////////////////////////////////////////
    case 'D':
   //         ecuacion();
              temperatura =analogRead(A1);
              cambio();
              digitalWrite(3,LOW);
              digitalWrite(4,LOW);
              digitalWrite(13,HIGH);
     break;
////////////////////////////////////////////////////////////////////////////
    case 'Z':
            digitalWrite(13,LOW);
            digitalWrite(3,LOW);
            digitalWrite(4,LOW);
            if(digitalRead(2) == LOW)estado = 'A';
    break;
////////////////////////////////////////////////////////////////////////////
   }
}


//void ecuacion(){
//  tiempo = millis();
//  if(tiempo > (prev + 10000)){
//    prev = millis();
//    estado = 'B';
//  }
//}

void cambio(){
  if(digitalRead(5) == LOW)estado = 'Z';
  if(temperatura > 700) estado = 'B';
  if(temperatura < 700 & temperatura > 400) estado = 'C';
  if(temperatura < 400) estado = 'D';
}

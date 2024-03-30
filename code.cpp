//C++ Code for Arduino Uno
// setup pins
void setup() {
  
  // initialize arrays to store columns and layers
  int columns[] = {5, 2, 3, 6, 8, 9, 10, 7, 4};
  int layers[] = {A0, A1, A2};
  
  // loop to setup pins 2-10 as OUTPUT
  for(int i = 0; i < 9; i++){
    pinMode(columns[i], OUTPUT);
  }
  
  // loop to setup and pull up pins A0-A2 as OUTPUT
  for(int i = 0; i < 3; i++){
    pinMode(layers[i], OUTPUT);
    digitalWrite(layers[i], HIGH); // Set layers to HIGH to turn them off initially
  }
}

// pattern 1
void pattern1(){
  int columns[] = {5, 2, 3, 6, 8, 9, 10, 7, 4};
  int layers[] = {A0, A1, A2};
  // Loop for layers
  for(int i = 0; i < 3; i++){
    // Grounding the current layer number
    digitalWrite(layers[i], LOW);
    
    // Turning on all column LEDs consecutively
    for(int j = 0; j < 9; j++){
      // Activating current light and layer
      digitalWrite(columns[j], HIGH);
      delay(80);
      digitalWrite(columns[j], LOW);
    }
    
    // Set layer to HIGH to turn it off
    digitalWrite(layers[i], HIGH);
  }
}

void pattern2(){
  int columns[] = {5, 2, 3, 6, 8, 9, 10, 7, 4};
  int layers[] = {A0, A1, A2};

  // Turn off all layers
  for(int x: layers){
    digitalWrite(x, LOW); // Set layers to HIGH to turn them off
  }
  
  // Turn on columns from 2 to 10, delay, and turn off in reverse order
  for(int x: columns){
    digitalWrite(x, HIGH);
    delay(100);
  }

  for(int i = 8; i >= 0; i--){
    digitalWrite(columns[i], LOW);
    delay(100);
  }

  // Turn on all layers
  for(int x: layers){
    digitalWrite(x, HIGH); // Ground the layers to turn them on
  }
}

void pattern3(){
  int columns[] = {5, 2, 3, 6, 8, 9, 10, 7, 4};
  int layers[] = {A0, A1, A2};
  
  int oddcolumns[] = {2, 6, 9, 7}; 
  int evencolumns[] = {3, 8, 10, 4}; 
  
  // Turn on middle column (pin 5) layer by layer from A0 to A2
  for(int i = 0; i < 3; i++){
    digitalWrite(layers[i], LOW);  // Ground the layer to turn it on
    digitalWrite(columns[0], HIGH);
    delay(100);
    digitalWrite(layers[i], HIGH);
    delay(100);
    digitalWrite(columns[0], LOW);
  }

  // Turn off all layers
  for(int i = 0; i < 3; i++){
    digitalWrite(layers[i], HIGH); // Set layers to HIGH to turn them off
  }

  delay(100); // Wait for a moment 

  // Turn on odd columns layer by layer from A0 to A2
  for(int i = 0; i < 3; i++){
    digitalWrite(layers[i], LOW);  // Ground the layer to turn it on
    for(int y: oddcolumns){
      digitalWrite(y, HIGH);
    }
    delay(100);
    digitalWrite(layers[i], HIGH);
    delay(100);
    for(int y: oddcolumns){
      digitalWrite(y, LOW);
    }
  }

  // Turn off all layers
  for(int i = 0; i < 3; i++){
    digitalWrite(layers[i], HIGH); // Set layers to HIGH to turn them off
  }

  delay(100); // Wait for a moment 

  // Turn on even columns layer by layer from A0 to A2
  for(int i = 0; i < 3; i++){
    digitalWrite(layers[i], LOW);  // Ground the layer to turn it on
    for(int y: evencolumns){
      digitalWrite(y, HIGH);
    }
    delay(100);
    digitalWrite(layers[i], HIGH);
    delay(100);
    for(int y: evencolumns){
      digitalWrite(y, LOW);
    }
  }

  // Turn off all layers
  for(int i = 0; i < 3; i++){
    digitalWrite(layers[i], HIGH); // Set layers to HIGH to turn them off
  }
}

void pattern4(){
  int columns[] = {5, 2, 3, 6, 8, 9, 10, 7, 4};
  int layers[] = {A0, A1, A2};
  
  for(int j = 0; j < 3; j++){
    // Turn on the first column (pin 5) and the layers, then turn them off
    digitalWrite(columns[0], HIGH); 
    for(int x: layers){
      digitalWrite(x, LOW);  // Ground the layer to turn it on
      delay(100); 
    }
    
    for(int x: layers){
      digitalWrite(x, HIGH);
      delay(100); 
    }
    
    digitalWrite(columns[0], LOW); 
    
    // Turn on the rest of the columns, turn off layers, then turn on layers
    for(int i = 1; i < 9; i++){
      digitalWrite(columns[i], HIGH); 
    }
    
    for(int i = 2; i >= 0; i--){
      digitalWrite(layers[i], LOW);  // Ground the layer to turn it on
      delay(100); 
    }
    
    for(int i = 2; i >= 0; i--){
      digitalWrite(layers[i], HIGH);
      delay(100); 
    } 
    
    // Turn off the rest of the columns
    for(int i = 1; i < 9; i++){
      digitalWrite(columns[i], LOW); 
    }
  }
}


// Main loop with patterns to activate in order
void loop(){
  pattern1();
  pattern2();
  pattern3();
  pattern4(); 
}

// --- Pin configuration for 8 slots (buttons and LEDs) ---
const int slotPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};       // Digital input pins for slot buttons
const int ledPins[8]  = {10, 11, 12, 13, A0, A1, A2, A3}; // Digital output pins for slot LEDs

// --- State tracking arrays ---
bool sentState[8];     // Tracks whether "Slot X ON" message has already been sent
bool buttonStates[8];  // Tracks whether each button is currently considered pressed

void setup() {
  Serial.begin(9600); // Initialize serial communication for output

  // Initialize pin modes and states
  for (int i = 0; i < 8; i++) {
    pinMode(slotPins[i], INPUT_PULLUP);   // Set button pin as input with internal pull-up resistor
    pinMode(ledPins[i], OUTPUT);          // Set LED pin as output
    digitalWrite(ledPins[i], LOW);        // Ensure LED is initially off

    // Initialize state tracking variables
    sentState[i] = false;
    buttonStates[i] = false;
  }
}

void loop() {
  for (int i = 0; i < 8; i++) { // Loop through all 8 slots
    bool isPressed = digitalRead(slotPins[i]) == LOW; // Read the button input; LOW means the button is pressed (due to INPUT_PULLUP)

    // --- Detect a new button press (rising edge) ---
    if (isPressed && !buttonStates[i]) {
      digitalWrite(ledPins[i], HIGH); // Turn the corresponding LED on

      // Send "Slot X ON" message to Serial
      Serial.print("Slot ");
      Serial.print(i + 1); // Web interface index starting from 1 
      Serial.println(" ON");

      // Update internal states to reflect the button is now pressed
      sentState[i] = true;
      buttonStates[i] = true;
    }

    // --- Detect a button release (falling edge) ---
    else if (!isPressed && buttonStates[i]) {
      digitalWrite(ledPins[i], LOW); // Turn the corresponding LED off

      // Send "Slot X OFF" message to Serial
      Serial.print("Slot ");
      Serial.print(i + 1);
      Serial.println(" OFF");

      // Update internal states to reflect the button is now released
      sentState[i] = false;
      buttonStates[i] = false;
    }

    // If button state hasn't changed, do nothing (prevents repeat messages)
  }

  delay(50); // Debounce
}

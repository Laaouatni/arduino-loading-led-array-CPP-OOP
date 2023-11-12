const int MINI_PAUSA = 100;
const int MAXI_PAUSA = 5 * MINI_PAUSA;
const int NUM_TOT_PIN = 13 + 1;

class ArduinoComponente {
  protected:
    int pin;
  public:
    static bool pinDisponibili[NUM_TOT_PIN];
    ArduinoComponente() { 
      pin = 0;
      while(pinDisponibili[pin]) { pin++; };
      pinDisponibili[pin] = true; 
      pinMode(pin, OUTPUT);
    };
    void accendi() { digitalWrite(pin, HIGH); };
    void spegni () { digitalWrite(pin, LOW ); };
};

bool ArduinoComponente::pinDisponibili[NUM_TOT_PIN] = { true, true, false, false, false, false, false, false, false, false, false, false, false, false };

class Led : public ArduinoComponente {};

class ArrayLeds {
  private:
  	Led **privArr;
  	int size;
  public:
    ArrayLeds(int n) : size(n) {
      privArr = new Led*[n];
      for(int i = 0; i < n; i++) {
        privArr[i] = new Led();
      };
    };
    void accendi(){
      for(int i = 0; i < size; i++) {
        privArr[i]->accendi();
        delay(MINI_PAUSA);
      };
    };
    void spegni() {
      for(int i = size; i >= 0; i--) {
        privArr[i]->spegni();
        delay(MINI_PAUSA);
      };
    };
};

const int NUM_LED = 6;

ArrayLeds listaLuci(NUM_LED);

void loop() {
  listaLuci.accendi();
  delay(MAXI_PAUSA);
  
  listaLuci.spegni();
  delay(MAXI_PAUSA);
};

void setup() {}

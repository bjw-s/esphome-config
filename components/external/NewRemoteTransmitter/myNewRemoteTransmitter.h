#include "esphome.h"
#include "NewRemoteTransmitter.h"

class MyNewRemoteTransmitter : public Component, public Switch {
 private:
  int _pin;
  int _address;
  int _period;
  int _unit;
  bool _publish_state;

 public:
  MyNewRemoteTransmitter(int pin, int address, int period, int unit, bool publish_state){
    _pin = pin;
    _address = address;
    _period = period;
    _unit = unit;
    _publish_state = publish_state;
  }

  void setup() override {

  }

  void write_state(bool state) override {
    NewRemoteTransmitter transmitter(_address, _pin, _period);
    transmitter.sendUnit(_unit, state);
    if (_publish_state) {
      publish_state(state);
    }
  }
};

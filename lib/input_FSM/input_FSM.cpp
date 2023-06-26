#include <Arduino.h>
#include "input_FSM.h"

    

input::input()
{
    /* type = digital;
    hold_ms_1 = 200;
    hold_ms_2 = 1000;
    #warning "verificar los valores por defecto"
     */
}
/**
 * @brief Configuración de pines
 *
 * Durante el llamado a esta función se configura el estado base de la entada, 
 * o sea, si se corre el setup con la entrada en un estado alto, se resgitraran los estados bajos como eventos
 *
 * @param pinNumber el numero de pin de la entrada según placa arduino (ver equivalentes)
 * @param inputType digital(defalut), pullup, analog(en proceso)
 * @param hold1 (200ms default)tiempo anti-rebote 
 * @param hold2 (1000ms default)tiempo para long-press
 * @return void
 */
void input::setInput(uint8_t pinNumber, types inputType, uint16_t hold1, uint16_t hold2)
{
    pin = pinNumber;
    type = inputType;
    hold_ms_1 = hold1;
    hold_ms_2 = hold2;
    state = reading;
    baseState=digitalRead(pin);
    

    switch (type)
    {
    case digital:
        pinMode(pin, INPUT);
        // Esto hay que borrarlo 
        Serial.print("configurado pin digital");
        Serial.println(pin);
        // hasta ca 
        break;

    case pullup:
        pinMode(pin, INPUT);
        digitalWrite(pin, HIGH); // configura la resistencia de pullup - ver hoja de datos
        break;

    case analog:
        pinMode(pin, INPUT);
        break;

    default:
        pinMode(pin, INPUT);

        break;
    }
}
/**
 * @brief Cambio de estado base
 *
 * Cambia el estado que se reconoce como base o que no genera un evento en la entrada.
 * por defecto HIGH, si dicha entrada recive un estado bajo se registrará un evento en getInput()
 * 
 *
 * @param base HIGH o LOW
 * @return void
 */
void input::changeBaseState(int base = HIGH)
{
    baseState = base;
}
uint16_t input::getInput()
{
    // solo para entradas digitales por ahora
    static uint8_t count = 0;
    static uint32_t holder1 = 0;
    static uint32_t holder2 = 0;
    static bool hold_1_flag = true;
    // static int pinPrevState = digitalRead(pin);
    

    if (millis() >= holder1 + hold_ms_1)
    {
        hold_1_flag = true;
    };

    switch (state)
    {
    case reading:
        Serial.println("leyendo");
        if (digitalRead(pin) != baseState)
        {
            state = delay;
            holder1 = millis();
            hold_1_flag = false;
            Serial.println("cambio de estado");
        }
        break;

    case delay:
        if (hold_1_flag)
        {
            state = reRead;
        }
        break;
    case reRead:
        if (digitalRead(pin) != baseState)
        {
            state = reading;
            count++;
        }else
            {
                state=reading;
            }
        break;
    default:
        state = reading; // reset
        break;
    };


    return (count);
}

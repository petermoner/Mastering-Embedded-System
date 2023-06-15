/*
 *  Name   : MDIO_private.h
 *  Version: v1.0
 * Created: 7/24/2022 10:11:16 PM
 * Author : Peter Moner
 */ 


#ifndef MDIO_PRIVATE_H
#define MDIO_PRIVATE_H


/************************************************************************************************/
/*                                        Interfacing macros                                    */
/************************************************************************************************/

/*DIO Ports*/
#define PORTA        (0)
#define PORTB        (1)
#define PORTC        (2)
#define PORTD        (3)


/*DIO Pins*/
#define PIN0         (0)
#define PIN1         (1)
#define PIN2         (2)
#define PIN3         (3)
#define PIN4         (4)
#define PIN5         (5)
#define PIN6         (6)
#define PIN7         (7)

/*DIO Pins' status*/
#define OUTPUT       (0)
#define INPUT_PULLUP (1)
#define INPUT_FLOAT  (2)

/*DIO Output pins' value*/
#define LOW          (0)
#define HIGH         (1)

/************************************************************************************************/
/*                                        Functions' prototypes                                 */
/************************************************************************************************/

/*This function is responsible for setting a specific status [OUTPUT - INPUT_FLOAT - INPUT_PULLUP] to a specific port pin*/
void MDIO_voidSetPinDirection(u8_t A_u8PortName , u8_t A_u8PinNumber , u8_t A_u8PinStatus);

/*This function is responsible for setting a specific value [HIGH - LOW] to a specific port pin*/
void MDIO_voidSetPinValue(u8_t A_u8PortName , u8_t A_u8PinNumber , u8_t A_u8PinValue);

/*This function is responsible for toggling a specific port pin value [HIGH -> LOW, LOW -> HIGH]*/
void MDIO_voidTogglePinValue(u8_t A_u8PortName , u8_t A_u8PinNumber);

/*This function is responsible for getting a specific port pin value [HIGH - LOW]*/
u8_t MDIO_voidGetPinValue(u8_t A_u8PortName , u8_t A_u8PinNumber);

/*This function is responsible for setting a specific status [OUTPUT - INPUT_FLOAT - INPUT_PULLUP] to a specific port */
void MDIO_voidSetPortDirection(u8_t A_u8PortName , u8_t A_u8PortStatus);

/*This function is responsible for setting a specific value [HIGH - LOW] to a specific port*/
void MDIO_voidSetPortValue(u8_t A_u8PortName , u8_t A_u8PortValue);

/*This function is responsible for toggling a specific port value [HIGH -> LOW, LOW -> HIGH]*/
void MDIO_voidTogglePortValue(u8_t A_u8PortName);

/*This function is responsible for getting a specific port value [HIGH - LOW]*/
u8_t MDIO_voidGetPortValue(u8_t A_u8PortName);

void MDIO_voidSetLowNibbleValue(u8_t A_u8PortName,u8_t A_u8Value);
void MDIO_voidSetHighNibbleValue(u8_t A_u8PortName,u8_t A_u8Value);


#endif /* MDIO_PRIVATE_H */
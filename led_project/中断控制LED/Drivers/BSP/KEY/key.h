#ifndef __KEY_H
#define __KEY_H

#include "./SYSTEM/sys/sys.h"

#define KEY_PORT_PORT GPIOE
#define KEY0_PIN GPIO_PIN_3
#define KEY_GPIO_CLK do{__HAL_RCC_GPIOE_CLK_ENABLE();}while(0)

#define KEY_PRESSED GPIO_PIN_RESET

void KEY_Init(void);
uint8_t KEY_Scan();

#endif /* __KEY_H */
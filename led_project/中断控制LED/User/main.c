#include "./BSP/KEY/key.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/EXTI/exti.h"
#include "./SYSTEM/sys/sys.h"

int main(void)
{
    HAL_Init();
    sys_stm32_clock_init(RCC_PLL_MUL9);
    delay_init(72);
    KEY_Init();
    LED_Init();
    EXTI_Init();

    LED0(1);

    while (1)
    {
        printf("Main loop running...\n");
        delay_ms(1000);
    }
}

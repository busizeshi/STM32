#include "./BSP/KEY/key.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/BEEP/beep.h"
#include "./BSP/LED/led.h"
#include "./SYSTEM/sys/sys.h"

int main(void)
{
    HAL_Init();
    sys_stm32_clock_init(RCC_PLL_MUL9);
    delay_init(72);
    KEY_Init();
    LED_Init();

    uint8_t last = 1;

    while (1)
    {
        uint8_t now = KEY_Scan();

        if (last == 0 && now == 0)
        {
            LED_Toggle(LED0_ID);
        }

        last = now;
    }
}

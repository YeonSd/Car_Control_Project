#include "stm32f4xx.h"
#include "gpio_utils.h"
#define ARM_MATH_M4
// Declaration For User-Defined Functions
void GPIO_Init(void);
void TIM2_Init(void);
void TIM3_Init(void);
void Motor_Control(uint8_t direction, uint16_t speed);
void TIM4_ms_Delay(uint32_t delay);
// Definitions for User-Defined Functions
void GPIO_Init(void) {
   // Enable GPIOA Clock
   ENABLE_GPIO_CLOCK(GPIOA);
   ENABLE_GPIO_CLOCK(GPIOD); // 추가: 스위치용 포트 D 클럭 활성화
   // Set PA5, PA6 to Alternate Function Mode
   SET_GPIO_AF_MODE(GPIOA, 5);
   SET_GPIO_AF_MODE(GPIOA, 6);
   // Set PA5, PA6 to Pull-Down
   SET_GPIO_PULLDOWN(GPIOA, 5);
   SET_GPIO_PULLDOWN(GPIOA, 6);
   // Set Alternate Function: PA5 -> AF1 (TIM2_CH1), PA6 -> AF2 (TIM3_CH1)
   SET_GPIO_AF(GPIOA, 5, 1);
   SET_GPIO_AF(GPIOA, 6, 2);
   // PD0, PD1 설정 (입력 + 풀다운)
   GPIOD->MODER &= ~((0x3 << (0 * 2)) | (0x3 << (1 * 2))); // 입력 모드
   GPIOD->PUPDR &= ~((0x3 << (0 * 2)) | (0x3 << (1 * 2))); // 초기화
   GPIOD->PUPDR |=  ((0x2 << (0 * 2)) | (0x2 << (1 * 2))); // 풀다운 설정
   // PD2 설정 (입력 + 풀다운)
   GPIOD->MODER &= ~(0x3 << (2 * 2)); // 입력 모드
   GPIOD->PUPDR &= ~(0x3 << (2 * 2)); // 초기화
   GPIOD->PUPDR |=  (0x2 << (2 * 2)); // 풀다운 설정
}
void TIM2_Init(){
   RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
   TIM2->PSC = 16-1; //Setting the clock frequency to 1MHz.
   TIM2->ARR = 20000; // Total period of the timer = 20ms
   TIM2->CNT = 0;
   TIM2->CCMR1 = 0x0060; //PWM mode for the timer
   TIM2->CCER |= 1; //Enable channel 1 as output
   TIM2->CCR1 = 5000; // Pulse width for PWM
}
void TIM3_Init(){
   RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
   TIM3->PSC = 16-1; //Setting the clock frequency to 1MHz.
   TIM3->ARR = 20000; // Total period of the timer = 20ms
   TIM3->CNT = 0;
   TIM3->CCMR1 = 0x0060; //PWM mode for the timer
   TIM3->CCER |= 1; //Enable channel 1 as output
   TIM3->CCR1 = 5000; // Pulse width for PWM
}
void Motor_Control(uint8_t direction, uint16_t speed){
   // direction = 1 => Clockwise Rotations
   // direction = 0 => Clockwise Rotations
   if (direction == 0){
       /* Sending PWM to IN1 and switching off input to IN2 */
       // Waiting for the pulse to finish, if any
       while (TIM3->CNT <= TIM3->CCR1 ){};
       // Then switching off Timer 3
       TIM3->CR1 &= ~TIM_CR1_CEN;
       // Adding a Delay of 1ms
       TIM4_ms_Delay(1);
       // Starting Timer 2
       TIM2->CR1 |= TIM_CR1_CEN;
       // Changing the speed for the motor
       TIM2->CCR1 = (uint16_t)((speed/225.0)*20000);
   }
   else{
       /* Sending PWM to IN2 and switching off input to IN1 */
       // Waiting for the pulse to finish, if any
       while (TIM2->CNT <= TIM2->CCR1 ){};
       // Then switching off Timer 2
       TIM2->CR1 &= ~TIM_CR1_CEN;
       // Adding a Delay of 1ms
       TIM4_ms_Delay(1);
       // Starting Timer 3
       TIM3->CR1 |= TIM_CR1_CEN;
       // Changing the speed for the motor
       TIM3->CCR1 = (uint16_t)((speed/225.0)*20000);
   }
}
void TIM4_ms_Delay(uint32_t delay){
   RCC->APB1ENR |= 1<<2; //Start the clock for the timer peripheral
   TIM4->PSC = 16000-1; //Setting the clock frequency to 1kHz.
   TIM4->ARR = (delay); // Total period of the timer
   TIM4->CNT = 0;
   TIM4->CR1 |= 1; //Start the Timer
   while(!(TIM4->SR & TIM_SR_UIF)){} //Polling the update interrupt flag
   TIM4->SR &= ~(0x0001); //Reset the update interrupt flag
}
int main(void){
   GPIO_Init();
   TIM2_Init();
   TIM3_Init();
   uint8_t direction = 0; // 초기 방향: forward
   uint16_t speed = 0;    // 초기 속도: 정지
   // PWM 타이머를 미리 활성화
   TIM2->CR1 |= TIM_CR1_CEN;
   TIM3->CR1 |= TIM_CR1_CEN;
   Motor_Control(direction, speed);
   while (1) {
       // 스위치 입력 읽기
       uint8_t accel    = (GPIOD->IDR & (1 << 0)) ? 1 : 0;
       uint8_t brake    = (GPIOD->IDR & (1 << 1)) ? 1 : 0;
       uint8_t reverse  = (GPIOD->IDR & (1 << 2)) ? 1 : 0;
       // 1. 브레이크 강제 정지 (즉시 정지)
       if (brake) {
           speed = 0;
           Motor_Control(direction, speed);
       }
       // 2. 방향전환 (속도가 0일 때만 허용)
       else if (reverse && speed == 0) {
           direction = !direction; // 방향 반전
           Motor_Control(direction, speed); // 속도는 그대로 유지 (0)
           TIM4_ms_Delay(200); // 방향 전환 시 스위치 디바운싱 방지용 지연
       }
       // 3. 악셀 가속 / 감속
       else if (accel && speed < 225) {
           speed += 5;
           if (speed > 225) speed = 225;
           Motor_Control(direction, speed);
       }
       else if (!accel && speed > 0) {
           speed -= 5;
           if (speed > 225) speed = 0;
           Motor_Control(direction, speed);
       }
       TIM4_ms_Delay(50); // 50ms 주기 체크
   }
}

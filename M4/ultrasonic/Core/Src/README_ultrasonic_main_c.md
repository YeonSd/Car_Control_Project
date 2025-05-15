# main.c Function Documentation

> STM32F411RE 기반 초음파 센서 제어 코드  
> 파일 경로: `M4/ultrasonic/Core/Src/main.c`

---

## Function List

| 함수명 | 설명 |
|--------|------|
| `main()` | 시스템 초기화 및 루프 처리 |
| `delay_us(uint16_t us)` | TIMx를 사용한 마이크로초 단위 지연 |
| `trigger_sensor()` | TRIG 핀(PA6)에 10us 펄스를 출력 |
| `HAL_TIM_IC_CaptureCallback()` | ECHO 핀(PA5)의 펄스 폭을 측정 |
| `SystemClock_Config()` | 클럭 설정 함수 |
| `MX_GPIO_Init()` | GPIO 초기화 |
| `MX_TIMx_Init()` | 타이머 초기화 |

---

## 주요 함수 상세

### `void delay_us(uint16_t us)`
- TIMx를 사용하여 마이크로초 단위의 정확한 지연을 생성
- **사용처**: `trigger_sensor()` 내부에서 TRIG 펄스 생성 시 사용

---

### `void trigger_sensor(void)`
- PA6(TRIG)을 LOW → HIGH (10us) → LOW로 전환하여 초음파를 발사
- 이후 ECHO 핀에서 신호를 수신함

---

### `void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)`
- ECHO 핀(PA5)에 들어온 HIGH 펄스의 길이를 측정
- 거리 계산:  
  \[
  \text{distance} = \frac{(\text{pulse\_width} \times \text{speed\_of\_sound})}{2}
  \]

---

### `int main(void)`
- HAL 초기화
- GPIO, TIM, SystemClock 설정
- 무한 루프 안에서 주기적으로 거리 측정 수행

---

## Notes
- PA5: ECHO (Input, 5V tolerant)
- PA6: TRIG (Output)
- 타이머: TIM2_CH1 입력 캡처 사용

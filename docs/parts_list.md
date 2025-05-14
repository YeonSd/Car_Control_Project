# 개발 간 사용한 보드 및 모듈

**Board**
| 품목 | 용도 | 수량 | 이미지 |
| ------ | ------ |------ |------ |
| STM32F103C8T6 | controller MCU <br/> car_status MCU (can slave2) |2|<img src="../media/part_list%20images/stm32f103.png" alt="부품 이미지" width="100" />|
| STM32F446RE | car_central MCU (can master) |1|<img src="../media/part_list%20images/stm32f446re.jpg" alt="부품 이미지" width="100" />|
| STM32F411RE | car_sensor MCU (can slave1) |1|<img src="../media/part_list%20images/stm32f411re.jpg" alt="부품 이미지" width="100" />|
<br/>

**Sensor**
| 품목 | 용도 | 수량 | 이미지 |
| ------ | ------ |------ |------ |
| [MPU-6050] 자이로센서 | controller - 전륜 조향제어|1|<img src="../media/part_list%20images/mpu-6050.jpg" alt="부품 이미지" width="90" />|
|[HC-SRO4] 초음파센서|장애물 감지|1|<img src="../media/part_list%20images/hc-sro4.png" alt="부품 이미지" width="100" />|
|조도센서|야간 주행 시 자동 점등|1|<img src="../media/part_list%20images/gl5528(LDR).png" alt="부품 이미지" width="120" />|
|충격감지센서|차량 충돌 시 감지|1|<img src="../media/part_list%20images/(sw-420)Impact_sensor.png" alt="부품 이미지" width="120" />|
<br/>

**Communication module**
| 품목 | 용도 | 수량 | 이미지 |
| ------ | ------ |------ |------ |
|[NRF24L01+PA+LNA] 2.4G 무선 모듈|car-controller RF 통신|2|<img src="../media/part_list%20images/nrf24l01+pa+lna(rf_module).jpg" alt="부품 이미지" width="120" />|
|[SN65HVD230] CAN tranceiver|can 컨트롤러가 포함된 f446,f103 |2|<img src="../media/part_list%20images/sn65hvd230(can_transceiver).png" alt="부품 이미지" width="120" />|
|[MCP-2515,TJA1050] <br>CAN controller+tranceiver|f441-CAN control|1|<img src="../media/part_list%20images/mcp2515(tja1050)(can controller+transceiver).png" alt="부품 이미지" width="120" />|
<br/>


**Motor**
| 품목 | 용도 | 수량 | 이미지 |
| ------ | ------ |------ |------ |
|[JGA25-370] DC모터|내부 인코더를 통해 dc모터의 방향,속도 확인가능|1|<img src="../media/part_list%20images/jga25-370(dc_motor).png" alt="부품 이미지" width="100" />|
|L298N|Dc motor driver|1|<img src="../media/part_list%20images/l298n(motor_driver).png" alt="부품 이미지" width="100" />|
|진동모터|controller - 충돌 경고 핸들 진동|2|<img src="../media/part_list%20images/vibration_motor_module.png" alt="부품 이미지" width="100" />|
|[MG996R]servo 모터|전륜 조향|1|<img src="../media/part_list%20images/mg996r(servo_motor).png" alt="부품 이미지" width="100" />|
<br/>


**Etc**
| 품목 | 용도 | 수량 | 이미지 |
| ------ | ------ |------ |------ |
|RC카 섀시, 휠||1|<img src="../media/part_list%20images/rc_car_chassis.png" alt="부품 이미지" width="150" />|
|Locker 스위치| car - 배터리 on/off , controller - 기어변속|?|<img src="../media/part_list%20images/locker_switch.png" alt="부품 이미지" width="70" />|
|tactile 스위치|브레이크,액셀, 페어링 용도|2|<img src="../media/part_list%20images/tactile_switch.png" alt="부품 이미지" width="70" />|
|LED|전조등, 후미등||<img src="../media/part_list%20images/10mm_led.jpg" alt="부품 이미지" width="100" />|
|LCD 디스플레이| car - 차량상태 확인 |1|<img src="../media/part_list%20images/lcd_display.png" alt="부품 이미지" width="100" />|
|OLED 디스플레이| controller - 주행 중 현황 확인 |1|<img src="../media/part_list%20images/oled_display.png" alt="부품 이미지" width="100" />|
|충전형 18650 리튬 배터리(3000mAh)| car - 3S, controller - 2S|5|<img src="../media/part_list%20images/18650_batteries.png" alt="부품 이미지" width="100" />|
|DC 스텝다운 컨버터| MCU 전원공급용도 <br>(car : 12v->5v, controller : 8v->5v) |2|<img src="../media/part_list%20images/(lm2596s)dc_stepdown_converter.png" alt="부품 이미지" width="100" />|
|전선 분배기|배터리 전력 병렬 공급|2|<img src="../media/part_list%20images/(pct-2-4)cable_expand_connector.png" alt="부품 이미지" width="100" />|
|저항|몇옴->어떤기능|?||
|로직 레벨 시프터|stm32보드 3.3v 감압 입력|?|<img src="../media/part_list%20images/logic_level_shifter(8ch).png" alt="부품 이미지" width="100" />|


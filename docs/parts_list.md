# 개발 간 사용한 보드 및 모듈

board
| 품목 | 용도 | 수량 |
| ------ | ------ |------ |
| STM32F103C8T6 | controller MCU |1|
| STM32F446RE | car_central MCU (can master) |1|
| STM32F411RE | car_sensor MCU (can slave1) |1|
| STM32F103C8T6 | car_status MCU (can slave2) |1|  
<br/>

Sensor
| 품목 | 용도 | 수량 |
| ------ | ------ |------ |
| [MPU-6050] 자이로센서 | controller - 전륜 조향제어|1|
|[HC-SRO4] 초음파센서|장애물 감지|1|
|조도센서|야간 주행 시 자동 점등|1|
|충격감지센서|차량 충돌 시 감지|1|
<br/>


Communication module
| 품목 | 용도 | 수량 |
| ------ | ------ |------ |
|[NRF24L01+PA+LNA] 2.4G 무선 모듈|car-controller RF 통신|2|
|[SN65HVD230] CAN tranceiver|can 컨트롤러가 포함된 f446,f103 |2|
|[MCP-2515,TJA1050] <br>CAN controller+tranceiver|f441-CAN control|1|
<br/>


Motor
| 품목 | 용도 | 수량 |
| ------ | ------ |------ |
|[JGA25-370] DC모터|내부 인코더를 통해 dc모터의 방향,속도 확인가능|1|
|L298N|Dc motor driver|1|
|진동모터|controller - 충돌 경고 핸들 진동|2|
|[MG996R]servo 모터|전륜 조향|1|
<br/>


Etc
| 품목 | 용도 | 수량 |
| ------ | ------ |------ |
|RC카 섀시, 휠||1|
|Locker 스위치| car - 배터리 on/off , controller - 기어변속|?|
|tactile 스위치|브레이크,액셀, 페어링 용도|2|
|LED|전조등, 후미등||
|LCD 디스플레이| car - 차량상태 확인 |1|
|OLED 디스플레이| controller - 주행 중 현황 확인 |1|
|충전형 18650 리튬 배터리(3000mAh)| car - 3S, controller - 2S|5|
|DC 스텝다운 컨버터| MCU 전원공급용도 <br>(car : 12v->5v, controller : 8v->5v) |2|
|전선 분배기|배터리 전력 병렬 공급|2|
|저항|몇옴->어떤기능|?|
|로직 레벨 시프터|stm32보드 3.3v 감압 입력|?|


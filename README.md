# develop 브랜치 구조도 (Tree 형식)

```
develop
├── docs/                       # 프로젝트 문서 디렉토리
├── media/                      # 이미지 및 미디어 리소스 디렉토리
├── .gitignore                  # Git 무시 파일 목록
├── README.md                   # 프로젝트 소개 문서
├── system_description.md       # 시스템 전체 설명 문서
│
├── mcu_controller                  # 핸들 MCU 기능 모듈
│   ├── feature/button          # 버튼 입력 처리 기능
│   ├── feature/gyro            # 자이로 센서 기능
│   └── README.md               # mcu_handle 설명 파일
│
├── mcu_car_central             # 차량 중앙 제어 MCU 기능 모듈
│   ├── feature/dc_motor        # DC 모터 제어 기능
│   ├── feature/servo_motor     # 서보 모터 조향 기능
│   └── README.md               # mcu_car_central 설명 파일
│
├── mcu_car_sensor              # 차량 센서 처리 MCU 기능 모듈
│   ├── feature/ultrasonic      # 초음파 거리 측정 기능
│   ├── feature/sensor          # 기타 센서 기능
│   └── README.md               # mcu_car_sensor 설명 파일
│
└── mcu_car_status              # 차량 상태 표시 MCU 기능 모듈
    ├── feature/LCD_display     # LCD/OLED 화면 출력 기능
    └── README.md               # mcu_car_status 설명 파일

```




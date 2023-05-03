# xv6상에 System call 추가하기

### 개요
xv6 운영체제 상에 새로운 시스템 콜을 추가해보는 프로젝트이다.
해당 프로젝트에서는 두 개의 시스템 콜을 추가하는 것을 목표로 한다.

### System call Type
1. memsize : memsize 함수를 호출하는 프로세스의 메모리 사이즈를 측정하는 시스템 콜이다.
2. trace : 쉘 입력 창에서 추적하고자 하는 System call을 mask 값으로 나타내어 입력하고 mask 값 뒤 인자로 오는 명령을 실행하여 해당 명령이 수행하는 프로그램 내의 System call의 호출을 추적하여 출력하는 시스템 콜이다.

### System call Call Graph
1. memsize System call 콜 그래프
![image](https://user-images.githubusercontent.com/64363668/235918602-f9d48a04-a4bd-46dd-afef-6ae9c2ebd818.jpeg)

2. trace System call 콜 그래프
![image](https://user-images.githubusercontent.com/64363668/235918648-2b057895-aa35-417d-b117-ae6078a91c45.jpeg)


### System call running result
1. memsize System call 실행 결과
<img width="452" alt="image" src="https://user-images.githubusercontent.com/64363668/235919551-5ede0cdc-4f55-4d64-b2e7-8e7e878155f7.png">

2. trace System call 실행 결과
<img width="452" alt="image" src="https://user-images.githubusercontent.com/64363668/235919737-ce26b225-c007-45c0-b0c4-188e52cda228.png">
<img width="457" alt="image" src="https://user-images.githubusercontent.com/64363668/235919825-e2302cfd-5bba-4a19-8398-32f373f18c88.png">

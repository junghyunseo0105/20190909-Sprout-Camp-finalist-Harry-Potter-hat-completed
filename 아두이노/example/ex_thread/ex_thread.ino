#include <FreeRTOS_AVR.h>

// 세마포어 핸들을 선언합니다.
SemaphoreHandle_t sem;


//스레드1
static void Thread1(void* arg) {
  while (1) {

    //세마포어를 받을때까지 스레드1은 계속 기다리게 됩니다.
    xSemaphoreTake(sem, portMAX_DELAY);

    //세마포어를 받을 경우 LED를 끕니다.
    Serial.println("thread1");
  }
}

//스레드2
static void Thread2(void* arg) {

  while (1) {
    //13번 LED를 켭니다
    Serial.println("thread2");

    //200ms를 대기합니다.
    vTaskDelay((1L * configTICK_RATE_HZ) / 1000L);

    //세마포어를 전달합니다.
    xSemaphoreGive(sem);

    //다시 200ms 대기합니다.
    vTaskDelay((1L * configTICK_RATE_HZ) / 1000L);
  }
}

void setup() {
  portBASE_TYPE s1, s2;

  Serial.begin(9600);
  
  //세마포어를 초기화 합니다. 세마포어는 동시에 1개만 생성됩니다.
  sem = xSemaphoreCreateCounting(1, 0);

  //우선순위가 2인 thread1을 생성합니다.
  s1 = xTaskCreate(Thread1, NULL, configMINIMAL_STACK_SIZE, NULL, 2, NULL);
  
  //우선순위가 1인 thread2를 생성합니다.
  s2 = xTaskCreate(Thread2, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);

  // 세마포어,스레드 생성에 에러가 생길 경우 에러메시지 출력
  if (sem== NULL || s1 != pdPASS || s2 != pdPASS ) {
    Serial.println(F("Creation problem"));
    while(1);
  }
  //스케쥴러를 시작합니다.
  vTaskStartScheduler();
  Serial.println(F("Insufficient RAM"));
  while(1);
}

void loop() {
  
}
